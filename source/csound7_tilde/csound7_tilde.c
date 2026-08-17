/**
    csound7~ — Csound 7 embedded statically inside Max/MSP.

    First draft, generated without a local compiler available (Linux
    sandbox, no real Xcode/Max SDK on hand). The Csound 7 APIs used here
    were verified by reading the actual sources (csound/csound, develop
    branch, include/csound.h and include/csound_rtmidi.h) — not from
    memory. Places where I had to assume something on the Max SDK side
    (exact buffer~ function names, class_getpath) are flagged "VERIFY:"
    and should be checked/adjusted on the first real build.

    Full protocol documented in the project's README.md.
*/

#include "ext.h"
#include "ext_obex.h"
#include "z_dsp.h"
#include "ext_systhread.h"
#include "ext_buffer.h"   // VERIFY: exact buffer~ header name in your SDK version
#include "ext_path.h"     // for path_toabsolutesystempath
#include "jpatcher_api.h" // for jpatcher_get_filepath - finds the file next to the open patcher

#include "csound.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <pthread.h>

#define CS7_MIDI_QUEUE_SIZE 4096
#define CS7_DEFAULT_KSMPS   1
#define CS7_MAX_PATH        2048
// Safety clamp for how many audio inlets/outlets a .csd's nchnls/nchnls_i
// can ask for. 128 in, 128 out - Max/MSP itself doesn't document a hard
// lower ceiling than this for object inlet/outlet counts, but an absurd
// value (e.g. a typo in the .csd) shouldn't be allowed to try creating
// thousands of inlets, so this clamps it defensively.
#define CS7_MAX_CHANNELS    128

static t_class *s_csound7_class = NULL;

typedef struct _csound7
{
    t_pxobject  x_obj;

    CSOUND     *csound;
    int         cs_started;      // csoundStart() already called successfully
    int         running;         // 1 = perform64 calls csoundPerformKsmps, 0 = paused (see "start"/"stop")
    double      cs_sr;           // sr Csound is currently compiled for
    long        ksmps;           // current/last-known real ksmps (see ksmps_forced)
    int         ksmps_forced;    // 1 = user explicitly set ksmps (creation arg/@ksmps),
                                  // so we push it via csoundSetOption before compiling.
                                  // 0 = let the .csd/.orc's own "ksmps = N" line (or
                                  // Csound's built-in default) decide, same as plain
                                  // Csound - we just read back whatever it ends up
                                  // being afterwards (the ring buffer doesn't care).
    long        msg_level;       // csoundSetMessageLevel() value, 0-231, default 0 (quiet)

    long        nchnls_out;      // derived from nchnls in the file, before dsp_setup
    long        nchnls_in;       // derived from nchnls_i

    t_symbol   *orc_path;        // current .csd/.orc file (used by "compile")

    // --- input/output ring buffer, decouples ksmps from Max's vector size ---
    // non-interleaved layout: one circular buffer per channel.
    MYFLT     **rb_in;           // [nchnls_in][rb_size]
    MYFLT     **rb_out;          // [nchnls_out][rb_size]
    long        rb_size;
    long        rb_in_write;     // write index (Max audio -> csound)
    long        rb_in_read;
    long        rb_in_filled;
    long        rb_out_write;    // write index (csound -> Max audio)
    long        rb_out_read;
    long        rb_out_filled;

    MYFLT      *spin_scratch;    // scratch buffer for one k-cycle
    MYFLT      *spout_scratch;

    // --- lock-free single-producer/single-consumer MIDI queue ---
    unsigned char midi_queue[CS7_MIDI_QUEUE_SIZE];
    volatile long midi_head;     // written by the message thread (producer)
    volatile long midi_tail;     // written by the Csound callback (consumer)

    pthread_mutex_t engine_lock; // protects compile/reset vs. perform

    void       *ctl_out;         // control outlet (last one, messages)
    void       *ctl_proxy;       // proxy for the control inlet (last one)
    long        proxy_num;    // stuffloc for ctl_proxy (not used for message routing, see csound7_list())

} t_csound7;

// ---------------------------------------------------------------------
// prototypes
// ---------------------------------------------------------------------
void *csound7_new(t_symbol *s, long argc, t_atom *argv);
void  csound7_free(t_csound7 *x);
void  csound7_assist(t_csound7 *x, void *b, long m, long a, char *s);

void  csound7_dsp64(t_csound7 *x, t_object *dsp64, short *count,
                     double samplerate, long maxvectorsize, long flags);
void  csound7_perform64(t_csound7 *x, t_object *dsp64, double **ins,
                         long numins, double **outs, long numouts,
                         long sampleframes, long flags, void *userparam);

void  csound7_anything(t_csound7 *x, t_symbol *s, long argc, t_atom *argv);
void  csound7_list(t_csound7 *x, t_symbol *s, long argc, t_atom *argv);

static void csound7_do_compile(t_csound7 *x, t_symbol *path);
static void csound7_do_reset(t_csound7 *x);
static void csound7_dump_channels(t_csound7 *x);
static void csound7_buf2tab(t_csound7 *x, t_symbol *bufname, long tabnum);
static void csound7_tab2buf(t_csound7 *x, long tabnum, t_symbol *bufname);
static void csound7_diskinfile(t_csound7 *x, t_symbol *chan, t_symbol *path);
static void csound7_conform_path(t_symbol *path, char *dst, long dstsize);
static void csound7_start_engine(t_csound7 *x, double sr);
static void csound7_apply_csoptions(CSOUND *csound, t_object *obj, const char *path);
static void csound7_load_plugins_dir(t_csound7 *x);
static long csound7_scan_nchnls(const char *path, const char *token, long fallback);
static t_symbol *csound7_resolve_path(t_csound7 *x, t_symbol *filename);
static void csound7_rb_alloc(t_csound7 *x, long size);
static void csound7_rb_free(t_csound7 *x);

// MIDI host IO callbacks
static int32_t cs7_midi_in_open(CSOUND *csound, void **userData, const char *devName);
static int32_t cs7_midi_in_close(CSOUND *csound, void *userData);
static int32_t cs7_midi_read(CSOUND *csound, void *userData, unsigned char *buf, int32_t nBytes);

// Csound messages -> Max console
static void cs7_msg_callback(CSOUND *csound, int32_t attr, const char *fmt, va_list args);

// "verbose" attribute custom setter (pushes the new level into the live
// Csound engine immediately, not just on the next start/reset)
t_max_err csound7_verbose_set(t_csound7 *x, t_object *attr, long argc, t_atom *argv);

// "ksmps" attribute custom setter (ksmps only takes effect on a fresh
// csoundStart(), so this triggers a full reset+recompile if already running)
t_max_err csound7_ksmps_set(t_csound7 *x, t_object *attr, long argc, t_atom *argv);

// ---------------------------------------------------------------------
// ext_main
// ---------------------------------------------------------------------
C74_EXPORT void ext_main(void *r)
{
    // MUST happen before the first csoundCreate() anywhere in this
    // external's lifetime (called once here, when Max loads the external -
    // well before any csound7~ instance exists). csoundCreate() calls this
    // internally with default flags if it hasn't been called yet, which
    // installs Csound's own signal handlers and an atexit() callback -
    // fine for a standalone Csound binary, but fatal inside a host: those
    // handlers call exit() directly on certain conditions, killing the
    // ENTIRE Max process, not just this object. Confirmed for real: a
    // runtime error during testing took down all of Max with "csound7~:
    // signal_handler" -> exit() in the crash log, not just this instrument.
    // See the doc comment on csoundInitialize() in csound.h.
    csoundInitialize(CSOUNDINIT_NO_SIGNAL_HANDLER | CSOUNDINIT_NO_ATEXIT);

    t_class *c = class_new("csound7~", (method)csound7_new, (method)csound7_free,
                            sizeof(t_csound7), 0L, A_GIMME, 0);

    class_addmethod(c, (method)csound7_dsp64,   "dsp64",   A_CANT, 0);
    class_addmethod(c, (method)csound7_assist,  "assist",  A_CANT, 0);
    class_addmethod(c, (method)csound7_anything,"anything",A_GIMME,0);
    class_addmethod(c, (method)csound7_list,    "list",    A_GIMME,0);

    class_dspinit(c);

    // "verbose" flag/attribute: console message level, 0-231 (default 0 =
    // quiet). Works as a creation flag ("csound7~ test.csd 32 @verbose 1"),
    // as a runtime message ("verbose 1"), and shows up in the Inspector -
    // this is the Max-native equivalent of a command-line "-m" flag, since
    // <CsOptions> flags in the .csd are ignored by this engine (see the
    // ordering note in csound7_start_engine).
    CLASS_ATTR_LONG(c, "verbose", 0, t_csound7, msg_level);
    CLASS_ATTR_LABEL(c, "verbose", 0, "Console Verbosity (0-231)");
    CLASS_ATTR_FILTER_CLIP(c, "verbose", 0, 231);
    CLASS_ATTR_ACCESSORS(c, "verbose", NULL, csound7_verbose_set);

    // "ksmps" flag/attribute: same idea, but for the block size. Only set
    // this if you actually want Max to force a value - leave it alone
    // (default) and the .csd/.orc's own "ksmps = N" line decides, exactly
    // like running Csound standalone. See csound7_ksmps_set() below.
    CLASS_ATTR_LONG(c, "ksmps", 0, t_csound7, ksmps);
    CLASS_ATTR_LABEL(c, "ksmps", 0, "Force ksmps (0/unset = let the .csd decide)");
    CLASS_ATTR_ACCESSORS(c, "ksmps", NULL, csound7_ksmps_set);

    class_register(CLASS_BOX, c);
    s_csound7_class = c;
}

// ---------------------------------------------------------------------
// new / free
// ---------------------------------------------------------------------
void *csound7_new(t_symbol *s, long argc, t_atom *argv)
{
    t_csound7 *x = (t_csound7 *)object_alloc(s_csound7_class);
    if (!x) return NULL;

    x->csound       = NULL;
    x->cs_started   = 0;
    x->running      = 1; // starts running immediately, same as before "start"/"stop" existed
    x->cs_sr        = 0.0;
    x->ksmps        = CS7_DEFAULT_KSMPS; // placeholder; overwritten by the
                                          // real value read back after the
                                          // first compile (see start_engine)
    x->ksmps_forced = 0; // 0 = let the .csd's own "ksmps = N" decide
    x->msg_level    = 0; // quiet by default, see "verbose" message
    x->orc_path     = NULL;
    x->rb_in        = NULL;
    x->rb_out       = NULL;
    x->rb_size      = 0;
    x->spin_scratch = NULL;
    x->spout_scratch= NULL;
    x->midi_head    = 0;
    x->midi_tail    = 0;
    pthread_mutex_init(&x->engine_lock, NULL);

    // first argument: path to the .csd/.orc file. second (optional): ksmps.
    if (argc >= 1 && (argv[0].a_type == A_SYM)) {
        // resolve relative paths (e.g. "test.csd") through Max's own
        // search path (patcher folder, subfolders, Packages, ...) so you
        // never have to type an absolute path here. See
        // csound7_resolve_path() below.
        x->orc_path = csound7_resolve_path(x, atom_getsym(argv));
    } else {
        object_error((t_object *)x,
            "a .csd/.orc file is required as the first argument");
        x->orc_path = NULL;
    }
    // second positional arg: OPTIONAL ksmps override. Only treated as
    // ksmps if it's actually numeric - an "@attr value" pair landing in
    // this slot (e.g. "csound7~ test.csd @verbose 1") is left alone for
    // attr_args_process() to handle further down. If this arg is absent,
    // ksmps_forced stays 0 and the .csd's own "ksmps = N" line decides.
    if (argc >= 2 && (argv[1].a_type == A_LONG || argv[1].a_type == A_FLOAT)) {
        long v = atom_getlong(argv + 1);
        if (v >= 1) {
            x->ksmps = v;
            x->ksmps_forced = 1;
        }
    }

    // derive nchnls/nchnls_i from the file BEFORE creating the audio
    // inlets/outlets.
    // VERIFY: simple text-based parsing (looks for the "nchnls" /
    // "nchnls_i" token followed by "="); this is not a full Csound
    // parser, it works for the common "nchnls = N" single-line case.
    const char *path = x->orc_path ? x->orc_path->s_name : NULL;
    x->nchnls_out = path ? csound7_scan_nchnls(path, "nchnls", 2) : 2;
    x->nchnls_in  = path ? csound7_scan_nchnls(path, "nchnls_i", x->nchnls_out) : 2;
    if (x->nchnls_out < 1) x->nchnls_out = 1;
    if (x->nchnls_in  < 1) x->nchnls_in  = 1;
    if (x->nchnls_out > CS7_MAX_CHANNELS) {
        object_error((t_object *)x, "nchnls %ld exceeds the %d channel safety limit, clamping",
            x->nchnls_out, CS7_MAX_CHANNELS);
        x->nchnls_out = CS7_MAX_CHANNELS;
    }
    if (x->nchnls_in > CS7_MAX_CHANNELS) {
        object_error((t_object *)x, "nchnls_i %ld exceeds the %d channel safety limit, clamping",
            x->nchnls_in, CS7_MAX_CHANNELS);
        x->nchnls_in = CS7_MAX_CHANNELS;
    }

    // The control proxy must be created BEFORE dsp_setup(): Max PREPENDS
    // each newly created inlet immediately after the object's own leftmost
    // inlet (same rule as outlet_new() below, "last coded = closest to the
    // start"), so whichever proxy_new() call happens LAST ends up right
    // after inlet 0, and whichever happens FIRST ends up pushed all the
    // way to the rightmost slot by the time everything created after it is
    // done. Confirmed for real with a pure audio-signal test (audio
    // routing is strictly positional, unlike control messages, which are
    // accepted from any inlet — see csound7_list()/csound7_anything()
    // below — so this couldn't be papered over the same way): creating
    // this proxy AFTER dsp_setup(), as an earlier version of this file
    // did, left it sitting in the MIDDLE of the audio inlets instead of at
    // the end (nchnls_in=2 gave audio1, control, audio2 instead of the
    // intended audio1, audio2, control) — the audio data itself still
    // routed correctly to whichever real audio inlet you found by trial
    // and error, but the visual/patchable layout was wrong.
    x->ctl_proxy = proxy_new((t_object *)x, x->nchnls_in, &x->proxy_num);
    dsp_setup((t_pxobject *)x, (short)x->nchnls_in);

    // Outlets must be CODED in right-to-left order for Max to DISPLAY them
    // left-to-right (each outlet_new call prepends to the object's outlet
    // list, so the last one coded ends up leftmost). We want, visually,
    // left-to-right: [audio 1, audio 2, ..., audio N, control]. So we code
    // control FIRST (it ends up rightmost, correct), then the audio
    // outlets in descending channel order (so channel 1 is coded last and
    // ends up leftmost, correct).
    x->ctl_out = outlet_new((t_object *)x, NULL);
    for (long i = x->nchnls_out - 1; i >= 0; i--) {
        outlet_new((t_object *)x, "signal");
    }

    // create the Csound instance right away (so "read"/"compile" work even
    // before DSP is turned on), with a provisional sr taken from the
    // system; dsp64 will resync it with Max's real one.
    csound7_start_engine(x, sys_getsr() > 0 ? sys_getsr() : 44100.0);

    // apply any "@attrname value" pairs typed at creation (e.g.
    // "csound7~ test.csd 32 @verbose 1") - must happen after the engine
    // exists so csound7_verbose_set() can push the level immediately.
    attr_args_process(x, argc, argv);

    return x;
}

void csound7_free(t_csound7 *x)
{
    dsp_free((t_pxobject *)x);
    if (x->csound) {
        csoundDestroy(x->csound);
        x->csound = NULL;
    }
    csound7_rb_free(x);
    pthread_mutex_destroy(&x->engine_lock);
}

void csound7_assist(t_csound7 *x, void *b, long m, long a, char *s)
{
    if (m == ASSIST_OUTLET) {
        if (a < x->nchnls_out)
            snprintf(s, 256, "(signal) Csound audio out %ld", a + 1);
        else
            snprintf(s, 256, "outgoing control data (chn/outvalue/channels/...)");
    } else {
        if (a < x->nchnls_in)
            snprintf(s, 256, "(signal) Csound audio in %ld", a + 1);
        else
            snprintf(s, 256, "incoming control data (chn/event/compile/midi/...)");
    }
}

// ---------------------------------------------------------------------
// start the Csound engine
// ---------------------------------------------------------------------
static void csound7_start_engine(t_csound7 *x, double sr)
{
    pthread_mutex_lock(&x->engine_lock);

    if (x->csound) {
        csoundDestroy(x->csound);
        x->csound = NULL;
    }

    // csoundCreate(hostData, opcodedir) — Csound 7 signature, different
    // from Csound 6 which only took one argument.
    x->csound = csoundCreate(x, NULL);
    if (!x->csound) {
        object_error((t_object *)x, "csoundCreate failed");
        pthread_mutex_unlock(&x->engine_lock);
        return;
    }

    // route Csound's messages/errors/warnings into the Max console, this
    // is essential for debugging (compile errors, missing plugins, etc.)
    csoundSetHostData(x->csound, x);
    csoundSetMessageCallback(x->csound, cs7_msg_callback);

    // Message level default (quiet); real compile errors/warnings always
    // go through CSOUNDMSG_ERROR/WARNING in cs7_msg_callback below
    // regardless of this setting. Can still be overridden BY the file's
    // own <CsOptions> (e.g. "-m7") via csound7_apply_csoptions() right
    // below, same as any other flag - or live at any time with the
    // "verbose <0-231>" message on the control inlet.
    csoundSetMessageLevel(x->csound, x->msg_level);

    // Apply whatever the .csd's own <CsOptions> block says, BEFORE any of
    // our own forced options below - csoundCompileCSD() would normally do
    // this itself, but by the time it runs (after csoundStart(), see the
    // ordering note further down) it's too late for Csound to act on
    // anything option-related, since those only take effect at start
    // time. This is what makes a plain "-M0" (or any other flag) in a
    // .csd's <CsOptions> actually work again, without needing a code
    // change + rebuild for every new flag (confirmed the hard way: MIDI
    // input needed exactly this and nothing in <CsOptions> could reach
    // it before this existed).
    if (x->orc_path) csound7_apply_csoptions(x->csound, (t_object *)x, x->orc_path->s_name);

    char opt[64];
    // sr: always forced, AFTER the file's own options above (so this
    // wins if the file also tried to set a rate - Max's DSP chain and
    // Csound have to agree on the same sample rate for the audio to be
    // correct, this isn't "Max being controlling for no reason", it's a
    // hard technical requirement of hosting Csound live inside another
    // audio engine).
    snprintf(opt, sizeof(opt), "--sample-rate=%d", (int)sr);
    csoundSetOption(x->csound, opt);

    // ksmps: only forced if the user explicitly asked for a specific
    // value (creation arg or @ksmps attribute). Otherwise left alone on
    // purpose, so the .csd/.orc's own "ksmps = N" line (or Csound's own
    // default) decides, exactly like running Csound standalone - the
    // ring buffer exists specifically so any ksmps Csound ends up
    // choosing works fine here. See the sync-back after compiling below.
    if (x->ksmps_forced) {
        snprintf(opt, sizeof(opt), "--ksmps=%ld", x->ksmps);
        csoundSetOption(x->csound, opt);
    }

    // nchnls/nchnls_i: always forced, but note this isn't overriding the
    // .csd - the values come FROM the .csd (csound7_scan_nchnls parsed
    // them out before dsp_setup, since Max's inlet/outlet count is fixed
    // at object-creation time and can't grow later). This just makes sure
    // the compiled orchestra ends up matching what we already told Max.
    snprintf(opt, sizeof(opt), "--nchnls=%ld", x->nchnls_out);
    csoundSetOption(x->csound, opt);
    snprintf(opt, sizeof(opt), "--nchnls_i=%ld", x->nchnls_in);
    csoundSetOption(x->csound, opt);

    // 0dbfs: same class of bug as <CsOptions>/MIDI above - it's a header
    // statement in <CsInstruments>, only read by csoundCompileCSD(),
    // which runs AFTER csoundStart() in this external (see the ordering
    // comment on that elsewhere in this file). By the time the .csd's
    // own "0dbfs = 1" line gets parsed, the engine has ALREADY locked in
    // its 0dbfs reference for the whole session and silently ignores it
    // - confirmed for real: the startup banner always printed "0dBFS
    // level = 32768.0" no matter what any .csd said, and file-streaming
    // opcodes (soundin/diskin/diskin2, which scale decoded samples by
    // the engine's LIVE 0dbfs) came out ~32768x too loud as a direct
    // result (a 16-bit sample divided by its own format's full scale
    // then re-multiplied by the wrong 32768 comes out as basically the
    // raw, un-normalized integer - measured for real, peaks around
    // 19000-32000 instead of the expected 0-1). Scanned from the file
    // the same way nchnls is, defaulting to 1 (the modern convention
    // every .csd in this project actually declares) if not found.
    long odbfs_val = x->orc_path ? csound7_scan_nchnls(x->orc_path->s_name, "0dbfs", 1) : 1;
    snprintf(opt, sizeof(opt), "--0dbfs=%ld", odbfs_val);
    csoundSetOption(x->csound, opt);

    // NOTE: deliberately NOT passing "-odac" here (that means "render to a
    // realtime device", not what we want). But leaving -o completely unset
    // turned out to be wrong too: Csound then falls back to writing a
    // soundfile named after the .csd ("test.aif"), which failed to open
    // and broke the performance (confirmed from a real console log:
    // "sfinit: cannot open test.aif"). The actual correct flag for pure
    // host-API usage (host reads/writes spin/spout itself, no file, no
    // device) is "-n" (nosound) - tells Csound not to write audio anywhere
    // on its own.
    csoundSetOption(x->csound, "-n");
    csoundSetOption(x->csound, "-+rtaudio=null");
    csoundSetOption(x->csound, "-+rtmidi=null");

    // MIDI via host callbacks, not a real device.
    //
    // csoundSetHostMIDIIO() + the callback registrations below only
    // REGISTER our callbacks - they don't, by themselves, tell Csound's
    // engine that a MIDI input device should actually be opened. That
    // needs the same flag a standalone Csound needs on its command line
    // to enable realtime MIDI in: "-M<device>" (e.g. "-M0" in the
    // cpsmidi manual example) - now handled by whatever the file's own
    // <CsOptions> says (via csound7_apply_csoptions() above), but forced
    // to "-M0" here too as a safety default in case a .csd forgets it -
    // without SOME "-M" flag reaching Csound before start, cs7_midi_in_
    // open()/cs7_midi_read() below stay fully wired up but NEVER CALLED,
    // so queued "midi" messages just pile up and are silently never
    // drained (confirmed for real: massign set up correctly, notes
    // queued with no errors, but the instrument never triggered at all -
    // not even its init pass). "0" is an arbitrary device name/number
    // here since we don't have real devices - it's just passed through
    // to cs7_midi_in_open()'s devName argument, which ignores it.
    csoundSetOption(x->csound, "-M0");
    csoundSetHostMIDIIO(x->csound);
    csoundSetExternalMidiInOpenCallback(x->csound, cs7_midi_in_open);
    csoundSetExternalMidiReadCallback(x->csound, cs7_midi_read);
    csoundSetExternalMidiInCloseCallback(x->csound, cs7_midi_in_close);

    csound7_load_plugins_dir(x);

    // order matters: Start BEFORE CompileCSD/CompileOrc, so performance
    // never terminates on its own when the score ends ("i" events are
    // treated as realtime events, not as a score with an end) — see the
    // csoundCompileCSD docs in csound.h.
    csoundStart(x->csound);
    x->cs_started = 1;
    x->cs_sr = sr;

    if (x->orc_path) {
        const char *p = x->orc_path->s_name;
        size_t len = strlen(p);
        int is_csd = (len > 4 && strcasecmp(p + len - 4, ".csd") == 0);
        if (is_csd) {
            int32_t csd_err = csoundCompileCSD(x->csound, p, 0, 0);
            if (csd_err != 0)
                object_error((t_object *)x, "csoundCompileCSD failed on %s (code %d)", p, csd_err);
        } else {
            FILE *f = fopen(p, "rb");
            if (f) {
                fseek(f, 0, SEEK_END);
                long sz = ftell(f);
                fseek(f, 0, SEEK_SET);
                char *buf = (char *)malloc(sz + 1);
                fread(buf, 1, sz, f);
                buf[sz] = 0;
                fclose(f);
                csoundCompileOrc(x->csound, buf, 0);
                free(buf);
            } else {
                object_error((t_object *)x, "could not open %s", p);
            }
        }
    }

    // sync with whatever ksmps Csound actually ended up running at -
    // either what we forced above, or whatever the .csd/.orc declared on
    // its own (or Csound's built-in default, 10, if neither said
    // anything). The ring buffer is deliberately ksmps-agnostic, so
    // reading it back here is all that's needed to keep the perform64
    // loop's block-size bookkeeping correct.
    if (x->csound) {
        uint32_t real_ksmps = csoundGetKsmps(x->csound);
        if (real_ksmps > 0) x->ksmps = (long)real_ksmps;
    }

    csound7_rb_alloc(x, x->ksmps * 4 > 256 ? x->ksmps * 4 : 256);

    pthread_mutex_unlock(&x->engine_lock);
}

static void csound7_do_reset(t_csound7 *x)
{
    double sr = x->cs_sr > 0 ? x->cs_sr : sys_getsr();
    csound7_start_engine(x, sr);
}

static void csound7_do_compile(t_csound7 *x, t_symbol *path)
{
    if (path) x->orc_path = path;
    if (!x->orc_path) {
        object_error((t_object *)x, "no file set (use 'read' first)");
        return;
    }
    if (!x->csound) return;

    const char *p = x->orc_path->s_name;
    FILE *f = fopen(p, "rb");
    if (!f) {
        object_error((t_object *)x, "could not open %s", p);
        return;
    }
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = (char *)malloc(sz + 1);
    fread(buf, 1, sz, f);
    buf[sz] = 0;
    fclose(f);

    pthread_mutex_lock(&x->engine_lock);
    // csoundCompileOrc is documented as safe to call repeatedly during
    // performance (async=0 = synchronous, runs immediately).
    int32_t err = csoundCompileOrc(x->csound, buf, 0);
    pthread_mutex_unlock(&x->engine_lock);
    free(buf);

    if (err != 0)
        object_error((t_object *)x, "compile error (%d)", err);
    else
        object_post((t_object *)x, "recompiled %s", p);
}

// ---------------------------------------------------------------------
// dsp64 — sync sr, (re)allocate the ring buffer if needed
// ---------------------------------------------------------------------
void csound7_dsp64(t_csound7 *x, t_object *dsp64, short *count,
                    double samplerate, long maxvectorsize, long flags)
{
    if (!x->csound || samplerate != x->cs_sr) {
        object_post((t_object *)x,
            "Max sr (%.0f) differs from Csound (%.0f), automatic reset+recompile",
            samplerate, x->cs_sr);
        csound7_start_engine(x, samplerate);
    }
    dsp_add64(dsp64, (t_object *)x, (t_perfroutine64)csound7_perform64, 0, NULL);
}

// ---------------------------------------------------------------------
// perform64 — feed/drain the ring buffer, calls csoundPerformKsmps in
// blocks of x->ksmps independently of Max's vector size
// ---------------------------------------------------------------------
void csound7_perform64(t_csound7 *x, t_object *dsp64, double **ins, long numins,
                        double **outs, long numouts, long sampleframes,
                        long flags, void *userparam)
{
    if (!x->csound || !x->cs_started || !x->running) {
        for (long ch = 0; ch < numouts; ch++)
            memset(outs[ch], 0, sizeof(double) * sampleframes);
        return;
    }

    if (!pthread_mutex_trylock(&x->engine_lock)) {
        // 1) write Max's incoming audio into the input ring buffer
        for (long ch = 0; ch < numins && ch < x->nchnls_in; ch++) {
            for (long i = 0; i < sampleframes; i++) {
                long w = (x->rb_in_write + i) % x->rb_size;
                x->rb_in[ch][w] = (MYFLT)ins[ch][i];
            }
        }
        x->rb_in_write = (x->rb_in_write + sampleframes) % x->rb_size;
        x->rb_in_filled += sampleframes;

        // 2) as long as we have at least ksmps samples available on input
        //    (and room on output), run one Csound k-cycle
        while (x->rb_in_filled >= x->ksmps &&
               (x->rb_out_filled + x->ksmps) <= x->rb_size) {

            MYFLT *spin  = csoundGetSpin(x->csound);
            const MYFLT *spout = csoundGetSpout(x->csound);
            uint32_t cs_ksmps = csoundGetKsmps(x->csound);

            // copy from the input ring (interleaved into spin, Csound
            // layout: frame*nchnls + channel)
            for (uint32_t f = 0; f < cs_ksmps; f++) {
                long r = (x->rb_in_read + f) % x->rb_size;
                for (long ch = 0; ch < x->nchnls_in; ch++) {
                    spin[f * x->nchnls_in + ch] = x->rb_in[ch][r];
                }
            }
            x->rb_in_read = (x->rb_in_read + cs_ksmps) % x->rb_size;
            x->rb_in_filled -= cs_ksmps;

            csoundPerformKsmps(x->csound);

            for (uint32_t f = 0; f < cs_ksmps; f++) {
                long w = (x->rb_out_write + f) % x->rb_size;
                for (long ch = 0; ch < x->nchnls_out; ch++) {
                    x->rb_out[ch][w] = spout[f * x->nchnls_out + ch];
                }
            }
            x->rb_out_write = (x->rb_out_write + cs_ksmps) % x->rb_size;
            x->rb_out_filled += cs_ksmps;
        }

        // 3) drain from the output ring into Max's audio output
        for (long ch = 0; ch < numouts && ch < x->nchnls_out; ch++) {
            for (long i = 0; i < sampleframes; i++) {
                if (x->rb_out_filled > 0) {
                    long r = (x->rb_out_read + i) % x->rb_size;
                    outs[ch][i] = (double)x->rb_out[ch][r];
                } else {
                    outs[ch][i] = 0.0;
                }
            }
        }
        if (x->rb_out_filled >= sampleframes) {
            x->rb_out_read = (x->rb_out_read + sampleframes) % x->rb_size;
            x->rb_out_filled -= sampleframes;
        }

        pthread_mutex_unlock(&x->engine_lock);
    } else {
        // engine busy (compile/reset in progress): output silence
        for (long ch = 0; ch < numouts; ch++)
            memset(outs[ch], 0, sizeof(double) * sampleframes);
    }
}

// ---------------------------------------------------------------------
// ring buffer alloc/free
// ---------------------------------------------------------------------
static void csound7_rb_free(t_csound7 *x)
{
    if (x->rb_in) {
        for (long ch = 0; ch < x->nchnls_in; ch++) if (x->rb_in[ch]) sysmem_freeptr(x->rb_in[ch]);
        sysmem_freeptr(x->rb_in);
        x->rb_in = NULL;
    }
    if (x->rb_out) {
        for (long ch = 0; ch < x->nchnls_out; ch++) if (x->rb_out[ch]) sysmem_freeptr(x->rb_out[ch]);
        sysmem_freeptr(x->rb_out);
        x->rb_out = NULL;
    }
    x->rb_size = 0;
}

static void csound7_rb_alloc(t_csound7 *x, long size)
{
    csound7_rb_free(x);
    x->rb_size = size;
    x->rb_in  = (MYFLT **)sysmem_newptr(sizeof(MYFLT *) * x->nchnls_in);
    x->rb_out = (MYFLT **)sysmem_newptr(sizeof(MYFLT *) * x->nchnls_out);
    for (long ch = 0; ch < x->nchnls_in; ch++)
        x->rb_in[ch] = (MYFLT *)sysmem_newptrclear(sizeof(MYFLT) * size);
    for (long ch = 0; ch < x->nchnls_out; ch++)
        x->rb_out[ch] = (MYFLT *)sysmem_newptrclear(sizeof(MYFLT) * size);
    x->rb_in_write = x->rb_in_read = x->rb_in_filled = 0;
    x->rb_out_write = x->rb_out_read = x->rb_out_filled = 0;
}

// ---------------------------------------------------------------------
// messages on the control inlet
// ---------------------------------------------------------------------
void csound7_list(t_csound7 *x, t_symbol *s, long argc, t_atom *argv)
{
    // Max only calls this for messages with NO leading symbol (e.g. a
    // message box literally containing "0.3 440", two bare numbers) -
    // "amp 0.3" does NOT arrive here, it arrives at csound7_anything()
    // with selector "amp" instead (see the comment down there). There's
    // no sensible use for a plain numeric list against a named Csound
    // channel, so this just points you at the right message shape.
    object_error((t_object *)x,
        "plain numeric lists aren't used for anything - to set a channel, "
        "use a message box like \"<channel_name> <value>\" (e.g. \"amp 0.3\")");
}

void csound7_anything(t_csound7 *x, t_symbol *s, long argc, t_atom *argv)
{
    // see csound7_list() above - control messages accepted from any inlet

    if (s == gensym("event")) {
        // rebuild a score line from the atoms: "i 1 0 -1 440 0.5"
        char line[1024]; line[0] = 0;
        for (long i = 0; i < argc; i++) {
            char tmp[64];
            if (argv[i].a_type == A_SYM)
                snprintf(tmp, sizeof(tmp), "%s ", atom_getsym(argv + i)->s_name);
            else
                snprintf(tmp, sizeof(tmp), "%g ", atom_getfloat(argv + i));
            strncat(line, tmp, sizeof(line) - strlen(line) - 1);
        }
        if (x->csound) csoundEventString(x->csound, line, 1);
        return;
    }
    if (s == gensym("start")) {
        // resumes the whole performance where it left off - engine
        // state (running instruments, channel values, etc.) is
        // untouched, this just lets csound7_perform64 call
        // csoundPerformKsmps again. Everything else (which instruments
        // play, when) is entirely up to you via "event" and normal
        // Csound orchestra/score code, same as always.
        x->running = 1;
        return;
    }
    if (s == gensym("stop")) {
        // pauses the whole performance in place - csound7_perform64
        // stops calling csoundPerformKsmps and outputs silence, nothing
        // in the engine advances (no k-cycles, no time passing) until
        // "start". Not the same as "reset", which recompiles from
        // scratch instead.
        x->running = 0;
        return;
    }
    if (s == gensym("channels")) {
        csound7_dump_channels(x);
        return;
    }
    if (s == gensym("read")) {
        if (argc >= 1 && argv[0].a_type == A_SYM)
            x->orc_path = csound7_resolve_path(x, atom_getsym(argv));
        return;
    }
    if (s == gensym("compile")) {
        t_symbol *path = (argc >= 1 && argv[0].a_type == A_SYM)
            ? csound7_resolve_path(x, atom_getsym(argv)) : NULL;
        csound7_do_compile(x, path);
        return;
    }
    if (s == gensym("reset")) {
        csound7_do_reset(x);
        return;
    }
    // NOTE: "verbose" is now a real Max attribute (see ext_main /
    // csound7_verbose_set below), so it's handled by the attribute
    // dispatch system before "anything" is ever called - no case needed
    // here. Usable as a creation flag ("@verbose 1"), a plain runtime
    // message ("verbose 1"), or from the Inspector.
    if (s == gensym("midi")) {
        if (argc >= 3) {
            unsigned char status = (unsigned char)atom_getlong(argv);
            unsigned char d1 = (unsigned char)atom_getlong(argv + 1);
            unsigned char d2 = (unsigned char)atom_getlong(argv + 2);
            unsigned char nbytes = 3;
            unsigned char hi = status & 0xF0;
            if (hi == 0xC0 || hi == 0xD0) nbytes = 2; // program change / channel pressure

            long next = (x->midi_head + nbytes) % CS7_MIDI_QUEUE_SIZE;
            if (next != x->midi_tail) { // room available
                x->midi_queue[x->midi_head] = status;
                x->midi_head = (x->midi_head + 1) % CS7_MIDI_QUEUE_SIZE;
                x->midi_queue[x->midi_head] = d1;
                x->midi_head = (x->midi_head + 1) % CS7_MIDI_QUEUE_SIZE;
                if (nbytes == 3) {
                    x->midi_queue[x->midi_head] = d2;
                    x->midi_head = (x->midi_head + 1) % CS7_MIDI_QUEUE_SIZE;
                }
            } else {
                object_error((t_object *)x, "MIDI queue full, event dropped");
            }
        }
        return;
    }
    if (s == gensym("buf2tab")) {
        if (argc >= 2 && argv[0].a_type == A_SYM) {
            csound7_buf2tab(x, atom_getsym(argv), atom_getlong(argv + 1));
        }
        return;
    }
    if (s == gensym("tab2buf")) {
        if (argc >= 2 && argv[1].a_type == A_SYM) {
            csound7_tab2buf(x, atom_getlong(argv), atom_getsym(argv + 1));
        }
        return;
    }
    if (s == gensym("diskinfile")) {
        if (argc >= 2 && argv[0].a_type == A_SYM && argv[1].a_type == A_SYM) {
            csound7_diskinfile(x, atom_getsym(argv), atom_getsym(argv + 1));
        } else {
            object_error((t_object *)x, "diskinfile needs 2 args: <channel name> <path>");
        }
        return;
    }

    // anything else with a numeric first argument is treated as a
    // generic "<channel_name> <value>" set - this is what actually
    // handles messages like "amp $1" or "freq 440" typed directly as a
    // message box, since Max dispatches "amp 0.3" here (selector "amp"
    // not matching any named method above) rather than to csound7_list()
    // (Max only calls "list" when a message has NO leading symbol at
    // all, e.g. "0.3 0.5" - "amp 0.3" is a typed/selector message, not a
    // plain list, no matter how it looks).
    if (argc >= 1 && (argv[0].a_type == A_FLOAT || argv[0].a_type == A_LONG)) {
        double val = atom_getfloat(argv);
        if (x->csound) csoundSetControlChannel(x->csound, s->s_name, (MYFLT)val);
        return;
    }

    object_error((t_object *)x, "unrecognized message '%s'", s->s_name);
}

static void csound7_dump_channels(t_csound7 *x)
{
    if (!x->csound) return;
    controlChannelInfo_t *lst = NULL;
    int32_t n = csoundListChannels(x->csound, &lst);
    if (n <= 0 || !lst) return;

    for (int32_t i = 0; i < n; i++) {
        t_atom a[2];
        const char *type =
            (lst[i].type & CSOUND_AUDIO_CHANNEL)  ? "audio"  :
            (lst[i].type & CSOUND_STRING_CHANNEL) ? "string" :
            (lst[i].type & CSOUND_CONTROL_CHANNEL)? "control": "?";
        atom_setsym(a, gensym(lst[i].name));
        atom_setsym(a + 1, gensym(type));
        outlet_anything(x->ctl_out, gensym("channel"), 2, a);
    }
    csoundDeleteChannelList(x->csound, lst);
}

// ---------------------------------------------------------------------
// buffer~ <-> Csound table
// VERIFY: exact buffer API function names (buffer_ref_new/
// buffer_ref_getobject/buffer_locksamples/buffer_getframecount) need to be
// confirmed against the actual ext_buffer.h header of your SDK version.
// ---------------------------------------------------------------------
// "buf2tab <bufname> <tabnum>" - copies a buffer~'s samples into a
// Csound table, resizing/recreating the table to exactly fit (no wasted
// preallocation), via a fresh score event.
//
// SAFE ONLY IF NOTHING IS CURRENTLY READING THIS TABLE NUMBER - i.e. no
// held note with a live opcode instance (e.g. an audio-rate tablei)
// already pointing at it. Recreating a table that something is actively
// reading frees the memory that opcode still has a pointer to, and the
// very next audio block reads freed memory and segfaults the whole Max
// process, not just this object - confirmed for real (a crash log
// showing Csound's own "tableir_audio" reading a null pointer on the
// CoreAudio IO thread, right after a buf2tab sent while the reading
// instrument was still playing). This is a fundamental constraint of
// static-table-reading opcodes like tablei, not something specific to
// this external - the correct, safe pattern (see 3_buffer_player.csd)
// is: stop the instrument (or never have started it yet), buf2tab, then
// (re)start it - never buf2tab into a table a running note is actively
// reading from.
static void csound7_buf2tab(t_csound7 *x, t_symbol *bufname, long tabnum)
{
    if (!x->csound) return;
    t_buffer_ref *ref = buffer_ref_new((t_object *)x, bufname);
    t_buffer_obj *buf = buffer_ref_getobject(ref);
    if (!buf) { object_error((t_object *)x, "buffer~ '%s' not found", bufname->s_name); object_free(ref); return; }

    float *samples = buffer_locksamples(buf);
    if (!samples) { object_free(ref); return; }
    long frames = buffer_getframecount(buf);
    double buf_sr = buffer_getsamplerate(buf);

    MYFLT *table = (MYFLT *)malloc(sizeof(MYFLT) * (frames + 1));
    for (long i = 0; i < frames; i++) table[i] = (MYFLT)samples[i];
    table[frames] = table[frames > 0 ? frames - 1 : 0]; // guard point

    buffer_unlocksamples(buf);

    // Resize/recreate the table via csoundCompileOrc, NOT a score "f"
    // event: csoundEventString() only QUEUES the event for the next
    // k-cycle, so a csoundTableCopyIn() called right after it (below)
    // would run before the resize actually happened, writing into the
    // old/wrong-sized table - then the queued "f" event fires one
    // k-cycle later and recreates the table at the right size but all
    // zeros (GEN02 with value 0), silently wiping out the real data.
    // Confirmed for real: table ended up correctly sized but completely
    // silent, console showing "scalemax 0.000" for the final table.
    // csoundCompileOrc() evaluates global-space (i-time) code
    // SYNCHRONOUSLY, inside the call itself, so by the time it returns
    // the table is genuinely resized and the following copy-in lands in
    // the right place.
    char orc[256];
    snprintf(orc, sizeof(orc), "i_cs7buf ftgen %ld, 0, %ld, -2, 0\n", tabnum, frames);
    csoundCompileOrc(x->csound, orc, 0); // async=0: must be synchronous, see comment above

    csoundTableCopyIn(x->csound, (int32_t)tabnum, table, 0);
    free(table);
    object_free(ref);

    // Publish the buffer~'s OWN native samplerate (not the engine's) as a
    // per-table control channel, "buf_sr_<tabnum>" - buffer~ remembers the
    // samplerate of whatever soundfile was loaded into it, which can be
    // completely different from the Csound engine's sr. A phasor-driven
    // reader (see 3_buffer_player.csd) needs THIS value, not the engine
    // sr, to compute the correct playback speed - using the engine's sr
    // instead only happens to "work" when the two rates coincide, and
    // silently plays too fast/slow otherwise (confirmed for real: a file
    // recorded at double the engine's sr played back at double speed).
    char chan_name[64];
    snprintf(chan_name, sizeof(chan_name), "buf_sr_%ld", tabnum);
    csoundSetControlChannel(x->csound, chan_name, (MYFLT)buf_sr);

    object_post((t_object *)x, "copied %ld frames from '%s' into table %ld (source sr %.0f)",
        frames, bufname->s_name, tabnum, buf_sr);
}

static void csound7_tab2buf(t_csound7 *x, long tabnum, t_symbol *bufname)
{
    if (!x->csound) return;
    MYFLT *tptr = NULL;
    int32_t len = csoundGetTable(x->csound, &tptr, (int32_t)tabnum);
    if (len <= 0 || !tptr) { object_error((t_object *)x, "table %ld not found", tabnum); return; }

    t_buffer_ref *ref = buffer_ref_new((t_object *)x, bufname);
    t_buffer_obj *buf = buffer_ref_getobject(ref);
    if (!buf) { object_error((t_object *)x, "buffer~ '%s' not found", bufname->s_name); object_free(ref); return; }

    // VERIFY: you might need to resize the buffer~ first via
    // buffer_edit_begin/buffer_setminmax/etc depending on the SDK version.
    float *samples = buffer_locksamples(buf);
    if (samples) {
        long frames = buffer_getframecount(buf);
        long n = (frames < len) ? frames : len;
        for (long i = 0; i < n; i++) samples[i] = (float)tptr[i];
        buffer_unlocksamples(buf);
        buffer_setdirty(buf);
    }
    object_free(ref);
}

// "wav2tab <path> <tabnum> [channel]" - loads a soundfile DIRECTLY into a
// Csound table via GEN01, bypassing buffer~ entirely. Unlike buf2tab, this
// needs no sr channel trick and no manual per-channel uzi loop: GEN01
// stores the file's own samplerate as part of the table's metadata, and a
// reader opcode built for it (loscil - see 6_wav_table_player.csd) uses that
// automatically to correct playback speed/pitch on its own. It also reads
// the file's channels itself; <channel> (optional, default 0) is GEN01's
// own selector - 0 = load all channels (interleaved; loscil supports
// mono or stereo tables this way), N = extract only channel N. There is
// NO uzi loop needed here because GEN01 does the extraction Csound-side.
//
// isize=0 below means "deferred" allocation (see GEN01 docs): the table
// is sized to exactly fit the file and carries the sr/channel metadata
// loscil needs - but a deferred table is NOT usable by plain table-index
// opcodes like tablei, only by loscil and similar. That's fine here,
// that's exactly what this path is for.
//
// Same synchronicity requirement as buf2tab's resize: csoundCompileOrc()
// runs this GEN01 call SYNCHRONOUSLY (not queued like a score "f" event),
// so by the time this function returns the table genuinely exists and is
// safe to reference from an "event i ..." sent right after.
// opendialog (and Max path handling in general) can hand you a path in
// old Mac OS 9-style HFS colon notation ("Macintosh HD:Users:you:..." or
// a "Macintosh HD:/Users/you/..." hybrid) instead of a plain POSIX path
// - confirmed for real: diskin2 failed to open a file with exactly that
// "Macintosh HD:/..." string, since libsndfile/fopen() only understand
// POSIX paths, not Mac volume-prefixed ones. path_nameconform() (Max
// SDK, ext_path.h) converts whatever style arrives into a proper native
// POSIX absolute path - used here so every message that takes a file
// path (wav2tab, diskinfile) is safe regardless of how Max produced it.
static void csound7_conform_path(t_symbol *path, char *dst, long dstsize)
{
    dst[0] = 0;
    path_nameconform(path->s_name, dst, PATH_STYLE_NATIVE, PATH_TYPE_ABSOLUTE);
    if (!dst[0]) {
        // fallback: not a recognizable Max path (e.g. already a plain
        // POSIX path that path_nameconform didn't like) - use as-is.
        strncpy(dst, path->s_name, dstsize - 1);
        dst[dstsize - 1] = 0;
    }

    // path_nameconform() did NOT clean up a real-world case: some Max/macOS
    // combos hand opendialog paths back as a hybrid "<Volume Name>:/posix/
    // path..." (confirmed for real: "Macintosh HD:/Users/ant/.../file.wav"
    // came out of path_nameconform completely unchanged, and diskin2 then
    // failed to open it - "Volume:" isn't a real path component to fopen()/
    // libsndfile). Whatever comes after that first ":/" IS already a
    // complete, valid POSIX absolute path on its own, so just strip the
    // volume-name prefix down to the leading slash. No-op for a normal
    // clean POSIX path (no colon present) or a genuine colon-only HFS path
    // with no slash right after the colon.
    char *cut = strchr(dst, ':');
    if (cut && cut[1] == '/') {
        memmove(dst, cut + 1, strlen(cut + 1) + 1);
    }
}

// "diskinfile <channel name> <path>" - sets a Csound STRING channel to a
// file path. That's ALL this does - no code generation, no ftgen, no
// compiling anything. What happens with the path from here on is 100%
// real, visible Csound code living in the .csd itself: an instrument
// does "Spath chnget <channel name>" to read it back, then feeds Spath
// into whatever opcode needs it (diskin for live streaming - see
// 5_diskin_player.csd, or ftgen/GEN01 to load it into a table - see
// 6_wav_table_player.csd's loader instrument). Same generic mechanism,
// reused by both examples with a different channel name/instrument on
// the Csound side.
// <channel name> is yours to choose (matches what the instrument's own
// chnget call asks for) - lets you run several independent diskin players
// at once, each reading its own channel name, same idea as buf2tab's
// per-table numbering.
static void csound7_diskinfile(t_csound7 *x, t_symbol *chan, t_symbol *path)
{
    if (!x->csound) return;
    char conformed[CS7_MAX_PATH];
    csound7_conform_path(path, conformed, sizeof(conformed));
    csoundSetStringChannel(x->csound, chan->s_name, conformed);
    object_post((t_object *)x, "diskinfile: channel '%s' = '%s'", chan->s_name, conformed);
}

// ---------------------------------------------------------------------
// dynamic plugins: load everything found in <bundle>/plugins/
// ---------------------------------------------------------------------
static void csound7_load_plugins_dir(t_csound7 *x)
{
    // VERIFY: class_getpath + path_toabsolutesystempath is the standard
    // pattern for locating the external's own folder, but double-check its
    // exact behavior (it might return the .mxo bundle's own path, in which
    // case you'd need to go up a couple of levels to sit next to it,
    // rather than inside Contents/MacOS/).
    short path_id = class_getpath(s_csound7_class);
    char external_path[CS7_MAX_PATH];
    external_path[0] = 0;
    path_toabsolutesystempath(path_id, "", external_path);

    char plugins_path[CS7_MAX_PATH];
    snprintf(plugins_path, sizeof(plugins_path), "%s/plugins", external_path);

    csoundLoadPlugins(x->csound, plugins_path);
}

// ---------------------------------------------------------------------
// MIDI host IO callbacks (called by the Csound engine)
// ---------------------------------------------------------------------
static int32_t cs7_midi_in_open(CSOUND *csound, void **userData, const char *devName)
{
    (void)csound; (void)devName;
    *userData = NULL;
    return 0;
}

static int32_t cs7_midi_in_close(CSOUND *csound, void *userData)
{
    (void)csound; (void)userData;
    return 0;
}

static int32_t cs7_midi_read(CSOUND *csound, void *userData, unsigned char *buf, int32_t nBytes)
{
    (void)userData;
    t_csound7 *x = (t_csound7 *)csoundGetHostData(csound);
    if (!x) return 0;

    int32_t n = 0;
    while (n < nBytes && x->midi_tail != x->midi_head) {
        buf[n++] = x->midi_queue[x->midi_tail];
        x->midi_tail = (x->midi_tail + 1) % CS7_MIDI_QUEUE_SIZE;
    }
    return n;
}

// ---------------------------------------------------------------------
// "verbose" attribute setter - clamps to Csound's real 0-231 range and,
// if the engine is already running, applies the new level immediately
// instead of waiting for the next start/reset.
// ---------------------------------------------------------------------
t_max_err csound7_verbose_set(t_csound7 *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        long v = atom_getlong(argv);
        if (v < 0) v = 0;
        if (v > 231) v = 231;
        x->msg_level = v;
        if (x->csound) csoundSetMessageLevel(x->csound, x->msg_level);
    }
    return MAX_ERR_NONE;
}

// ---------------------------------------------------------------------
// "ksmps" attribute setter - explicit override only. ksmps is baked in
// at csoundStart() time, so changing it live means a full reset (same
// as an automatic sr change already does).
// ---------------------------------------------------------------------
t_max_err csound7_ksmps_set(t_csound7 *x, t_object *attr, long argc, t_atom *argv)
{
    if (argc && argv) {
        long v = atom_getlong(argv);
        if (v < 1) v = 1;
        x->ksmps = v;
        x->ksmps_forced = 1;
        if (x->csound) csound7_do_reset(x);
    }
    return MAX_ERR_NONE;
}

// ---------------------------------------------------------------------
// Csound messages -> Max console (compile errors, warnings, plugin
// loading, etc.)
// ---------------------------------------------------------------------
static void cs7_msg_callback(CSOUND *csound, int32_t attr, const char *fmt, va_list args)
{
    t_csound7 *x = (t_csound7 *)csoundGetHostData(csound);
    char line[1024];
    vsnprintf(line, sizeof(line), fmt, args);

    // strip trailing newlines, object_post adds its own
    size_t len = strlen(line);
    while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r')) {
        line[--len] = 0;
    }
    if (len == 0) return;

    // Csound tags a lot of purely informational text (version banner,
    // sr/kr/ksmps summary, "SECTION 1:", etc.) with the same
    // CSOUNDMSG_ERROR type it uses for real errors - confirmed from a
    // real build/run, the entire startup banner came through as
    // CSOUNDMSG_ERROR and lit up red in the Max console, which is
    // misleading (nothing was actually wrong). So the message TYPE from
    // Csound itself isn't a reliable signal for "this needs your
    // attention" - real failures are already surfaced separately via our
    // own explicit return-code checks elsewhere in this file
    // (csoundCompileCSD failing, a file not opening, etc.), which DO use
    // object_error and ARE reliable. Everything arriving through this
    // callback is just Csound's own console chatter, so it always goes
    // through object_post (never red), only labeled by type for clarity.
    int32_t type = attr & CSOUNDMSG_TYPE_MASK;
    if (type == CSOUNDMSG_WARNING)
        object_post(x ? (t_object *)x : NULL, "csound warning: %s", line);
    else
        object_post(x ? (t_object *)x : NULL, "csound: %s", line);
}

// ---------------------------------------------------------------------
// resolve a possibly-relative filename so callers never have to type an
// absolute path. Absolute paths (starting with '/' or '~') are passed
// through untouched. Two strategies are tried, in order:
//
//   1) Relative to the patcher that owns this object (the file sitting
//      right next to your .maxpat). This is the common case and doesn't
//      depend on Max's internal search-path database at all - we just
//      take the patcher's own file path, chop off its filename, and
//      verify the result with a real fopen() before trusting it.
//   2) Max's file search path (patcher folder + subfolders, folders
//      added in File Preferences, Packages) via locatefile_extended, as
//      a fallback for files that live elsewhere Max would still find
//      them (e.g. a Packages examples folder).
//
// If neither works, the raw symbol is returned unchanged and the
// caller's own fopen()/csoundCompileCSD() will fail with a clear
// "could not open" error instead of silently doing the wrong thing.
//
// VERIFY: jpatcher_get_filepath()/object_obex_lookup(..., gensym("#P"),
// ...) is the standard documented Max SDK pattern for "find the patcher
// that owns me", but not yet confirmed against a real build here.
// ---------------------------------------------------------------------
static t_symbol *csound7_resolve_path(t_csound7 *x, t_symbol *filename)
{
    if (!filename) return filename;
    const char *name = filename->s_name;
    if (name[0] == '/' || name[0] == '~') return filename; // already absolute

    // --- strategy 1: next to the owning patcher ---
    t_object *patcher = NULL;
    object_obex_lookup(x, gensym("#P"), &patcher);
    if (patcher) {
        t_symbol *patcher_file = jpatcher_get_filepath(patcher);
        if (patcher_file && patcher_file->s_name[0]) {
            // jpatcher_get_filepath() returns a hybrid legacy-Mac path
            // ("Macintosh HD:/Users/ant/...", volume name + colon glued
            // to an otherwise POSIX-looking path), not a clean POSIX
            // path - confirmed from a real build log. Strip everything
            // up to the first '/' to get a real POSIX path.
            const char *posix_start = strchr(patcher_file->s_name, '/');
            char dir[CS7_MAX_PATH];
            strncpy(dir, posix_start ? posix_start : patcher_file->s_name, sizeof(dir) - 1);
            dir[sizeof(dir) - 1] = 0;
            char *slash = strrchr(dir, '/');
            if (slash) {
                *(slash + 1) = 0; // keep trailing '/', drop the patcher's own filename
                char full[CS7_MAX_PATH];
                snprintf(full, sizeof(full), "%s%s", dir, name);
                FILE *test = fopen(full, "rb");
                if (test) {
                    fclose(test);
                    object_post((t_object *)x, "resolved '%s' -> '%s' (next to patcher)", name, full);
                    return gensym(full);
                }
                object_post((t_object *)x, "tried '%s' (next to patcher), not found there", full);
            } else {
                object_post((t_object *)x, "patcher filepath '%s' has no '/', couldn't derive a folder", dir);
            }
        } else {
            object_post((t_object *)x, "patcher has no filepath yet (unsaved patch?), skipping patcher-relative lookup");
        }
    } else {
        object_post((t_object *)x, "could not find owning patcher (#P lookup failed)");
    }

    // --- strategy 2: Max's own file search path ---
    char fname[CS7_MAX_PATH];
    strncpy(fname, name, sizeof(fname) - 1);
    fname[sizeof(fname) - 1] = 0;

    short path_id = 0;
    t_fourcc filetype = 0, outtype = 0;
    short loc_err = locatefile_extended(fname, &path_id, &outtype, &filetype, 0);

    if (loc_err == 0) {
        char full[CS7_MAX_PATH];
        if (path_toabsolutesystempath(path_id, fname, full) == 0) {
            FILE *test = fopen(full, "rb");
            if (test) {
                fclose(test);
                object_post((t_object *)x, "resolved '%s' -> '%s' (Max search path)", name, full);
                return gensym(full);
            }
            object_post((t_object *)x, "locatefile_extended found '%s' but fopen failed on it", full);
        } else {
            object_post((t_object *)x, "locatefile_extended found path_id %d but path_toabsolutesystempath failed", path_id);
        }
    } else {
        object_post((t_object *)x, "locatefile_extended('%s') returned error %d (not found)", name, loc_err);
    }

    object_error((t_object *)x,
        "could not locate '%s' next to the patcher or via Max's "
        "search path — using the name as given, this will likely fail to open", name);
    return filename;
}

// ---------------------------------------------------------------------
// minimal text parsing for a .csd's own <CsOptions> block, applied via
// csoundSetOption() BEFORE csoundStart() - see the big comment on the
// call site in csound7_start_engine() for why this exists at all (in
// short: csoundCompileCSD() reads <CsOptions> too, but only AFTER
// csoundStart() has already run in our ordering, which is too late for
// Csound to act on any of it).
// ---------------------------------------------------------------------
static void csound7_apply_csoptions(CSOUND *csound, t_object *obj, const char *path)
{
    size_t plen = strlen(path);
    if (plen < 4 || strcasecmp(path + plen - 4, ".csd") != 0) return; // .orc files have no CsOptions

    FILE *f = fopen(path, "rb");
    if (!f) return;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0 || sz > 1 << 20) { fclose(f); return; } // 1MB safety limit, matches csound7_scan_nchnls
    char *buf = (char *)malloc(sz + 1);
    fread(buf, 1, sz, f);
    buf[sz] = 0;
    fclose(f);

    char *start = strstr(buf, "<CsOptions>");
    char *end   = start ? strstr(start, "</CsOptions>") : NULL;
    if (start && end) {
        start += strlen("<CsOptions>");
        *end = 0; // cut the buffer off at the closing tag

        // line by line, so a ";" comment on one line can't eat the rest
        // of the block - then whitespace-split each line into individual
        // flags, one csoundSetOption() call per flag (Csound's own
        // command-line parser expects them one at a time, same as if
        // you'd typed them separately on a real command line).
        char *saveptr_line = NULL;
        char *line = strtok_r(start, "\r\n", &saveptr_line);
        while (line) {
            char *comment = strchr(line, ';');
            if (comment) *comment = 0;

            char *saveptr_tok = NULL;
            char *tok = strtok_r(line, " \t", &saveptr_tok);
            while (tok) {
                csoundSetOption(csound, tok);
                object_post(obj, "CsOptions: applied '%s' from %s", tok, path);
                tok = strtok_r(NULL, " \t", &saveptr_tok);
            }
            line = strtok_r(NULL, "\r\n", &saveptr_line);
        }
    }
    free(buf);
}

// ---------------------------------------------------------------------
// minimal text parsing for "nchnls"/"nchnls_i" in the orchestra file
// ---------------------------------------------------------------------
static long csound7_scan_nchnls(const char *path, const char *token, long fallback)
{
    FILE *f = fopen(path, "rb");
    if (!f) return fallback;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0 || sz > 1 << 20) { fclose(f); return fallback; } // 1MB safety limit
    char *buf = (char *)malloc(sz + 1);
    fread(buf, 1, sz, f);
    buf[sz] = 0;
    fclose(f);

    long result = fallback;
    char *p = buf;
    size_t tlen = strlen(token);
    while ((p = strstr(p, token)) != NULL) {
        char *after = p + tlen;
        // avoid partial matches (e.g. "nchnls" inside "nchnls_i" when
        // looking for "nchnls"): the next character must not be
        // alphanumeric/underscore
        if (*after == '_' || isalnum((unsigned char)*after)) { p = after; continue; }
        while (*after == ' ' || *after == '\t') after++;
        if (*after == '=') {
            after++;
            result = strtol(after, NULL, 10);
            break;
        }
        p = after;
    }
    free(buf);
    return result;
}
