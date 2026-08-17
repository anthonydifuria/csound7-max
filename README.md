# csound7~ — Csound 7 embedded as a monolithic, statically-linked Max/MSP external

A Max/MSP external (`csound7~`) that embeds the Csound 7 engine
**statically** inside the binary: no separate Csound install needed on the
end user's machine, no risk of version mismatch.

This is an **aggressive first draft**, generated without being able to
compile or test the code locally (I work in a Linux sandbox, no Xcode/Max
available to me). Expect 1-2 rounds of fixes after the first real build on
your Mac — that's normal for a project of this complexity. Every place
where I had to make an assumption without being able to verify it is
flagged with `// VERIFY:` in the code, or noted below.

## License

This project's own code is LGPL 2.1 (or later) - see `LICENSE`, chosen
to match Csound and libsndfile, both also LGPL, which this project
statically links. See `THIRD-PARTY-LICENSES.md` for the full picture:
exact licenses for Csound, libsndfile, libsamplerate (BSD-2-Clause), and
the Max SDK (permissive/MIT-style), where each one's source comes from,
and how the LGPL's static-linking conditions are met (short version:
keep the source and build scripts - this whole repo - distributed
alongside any compiled binary).

See `ACKNOWLEDGMENTS.md` for credit to the Csound community and the
prior `csound~` (Max/MSP) and `csoundapi~` (Pure Data) projects this one
follows in the footsteps of.

## What it does (summary of decisions made in chat)

- **Universal binary** (arm64 + x86_64), buildable from a single Apple
  Silicon Mac via cross-compile + `lipo`.
- **Embedded Csound**: core opcodes + libsndfile + libsamplerate only, all
  static. No Csound audio/MIDI/GUI/scripting backends — Max feeds audio
  through the API (`csoundPerformKsmps`), not through a device.
- **Audio inlets/outlets**: their count is derived automatically from
  `nchnls`/`nchnls_i` read from the `.csd`/`.orc` file passed as the first
  creation argument. You never type numbers by hand.
- **File path**: the `.csd`/`.orc` argument (creation, `read`, `compile`)
  can be a relative path (e.g. `test.csd`, or `examples/test.csd`) — it's
  resolved through Max's own file search path (the folder containing the
  open patcher, its subfolders, anything added in File Preferences, and
  Packages), the same way Max resolves it for any other object. You only
  need an absolute path if the file lives somewhere Max wouldn't normally
  look. This also means the external itself does **not** need to live
  inside `~/Documents/Max 9/Packages/` — a self-contained project folder
  with your patcher, `csound7~.mxo`, and your `.csd` files side by side
  (or in subfolders) works fine, since Max always searches the open
  patcher's own folder.
- **Control inlet/outlet**: one per side, placed after the audio ones, using
  a generic message protocol. See below.
- **MIDI**: via "host MIDI IO" (`csoundSetHostMIDIIO` + a read callback),
  not via `csoundPushMidiMessage` — that function **does not exist** in the
  Csound 7 API I verified from source (`develop` branch), contrary to what
  we assumed out loud earlier in chat. The real mechanism is functionally
  equivalent: Csound calls our callback to "pull" MIDI bytes from an
  internal queue that we fill from Max messages.
- **Live coding**: `csoundCompileOrc` at runtime, explicit only (never
  automatic), triggered by a `compile` message.
- **Sample rate**: automatic sync with Max, automatic reset+recompile if it
  changes while running.
- **Ksmps**: controlled by the `.csd`/`.orc` itself by default (its own
  `ksmps = N` line, or Csound's own default if it doesn't set one) -
  exactly like running Csound standalone. An internal ring buffer
  decouples Csound's blocks from Max's vector size, so whatever value
  Csound ends up with just works. Only forced from the Max side if you
  explicitly ask for it (creation arg or `@ksmps` attribute, see below).
- **Csound tables <-> Max buffer~**: bidirectional bridging.
- **Dynamic plugins**: a `plugins/` folder next to the external, loaded with
  `csoundLoadPlugins()` on every startup — drop extra opcode `.dylib` files
  in there (e.g. faust, fluidsynth) with no need to rebuild anything.

## Control inlet/outlet protocol (the last one, messages)

Send these messages to the control inlet (rightmost one, shown visually
as the last inlet). Note: they're actually accepted from **any** inlet,
not strictly enforced to the rightmost one - matching how the official
`csound~` for Max (see `ACKNOWLEDGMENTS.md`) works too, its control
methods aren't inlet-restricted either. The rightmost inlet is still the
intended/documented one to use.

- `<name> <value>` → sets the Csound control channel called `<name>` to
  `<value>` (`csoundSetControlChannel`). Just a plain message box like
  `amp 0.3` or `freq $1`, or use a `pack`/message combo for a name that
  changes at runtime. Read it inside Csound with `kval invalue "name"`
  or `kval chnget "name"`. (Any message whose first word isn't one of
  the reserved ones on this list - `event`, `start`, `stop`, `channels`,
  `read`, `compile`, `reset`, `midi`, `buf2tab`, `tab2buf` - is treated
  this way, with the message's own name as the channel name.)
- **To receive values from Csound back into Max** you must use the
  `outvalue "name", kval` opcode (not plain `chnset`) — it's the only one
  that triggers a push notification to the host. With plain `chnset` Csound
  never notifies anyone, the value just sits there passively and nothing
  gets sent out.
- `event i 1 0 -1 440 0.5` → turns on (held note, negative duration) an
  instance of instrument 1 with those parameters.
- `event i -1 0 0` → turns off the held instance of instrument 1 (standard
  Csound convention: same instrument number, negated).
- `start` → resumes the whole performance (if paused with `stop`).
  Doesn't touch engine state - whatever was running keeps running from
  where it left off.
- `stop` → pauses the whole performance in place: outputs silence,
  nothing in the engine advances (no k-cycles, no time passing) until
  `start`. Not the same as `reset`, which recompiles from scratch.
  Which instruments play, and when, is entirely up to you via `event`
  and ordinary Csound orchestra/score code, same as it's always been in
  Csound - `start`/`stop` only gate the whole performance on/off.
- `channels` → the external dumps a `channel <name> <type>` message out the
  control outlet for every channel currently alive in Csound (handy after a
  live recompile to see what you just created).
- `read <absolute path>` → sets the orchestra file used by `compile`.
- `compile` → recompiles by reading the file set with `read` (or the one
  passed as a creation argument). Never automatic, only on command.
- `compile <absolute path>` → sets the path and recompiles in one shot.
- `buf2tab <buffer~ name> <table number>` → copies samples from a Max
  `buffer~` into a Csound f-table (created/resized as needed).
- `tab2buf <table number> <buffer~ name>` → copies the other way, from the
  Csound table into the `buffer~`.
- `reset` → full `csoundReset`, then recompiles the current file from
  scratch.
- `verbose <0-231>` also works as a plain runtime message (see below —
  it's actually a real attribute, but Max dispatches attribute-named
  messages the same way).

## What's controlled by the `.csd` vs. what's forced by Max

Some parameters are structurally required to be forced from the Max side
because they're needed before the file is even read, or because Max's
own audio engine has to agree with Csound on them - this is unavoidable
when embedding Csound live inside another audio host, not us being
controlling for its own sake:

- **sr** - always forced to match Max's current sample rate, with an
  automatic reset+recompile if it changes. Max's DSP chain and Csound
  must run at the same rate.
- **nchnls / nchnls_i** - always forced, but the values come *from* the
  `.csd` itself (parsed out before the object's inlets/outlets are even
  created, since Max's I/O count is fixed at creation time and can't
  grow later). This mirrors the file's own declaration, it doesn't
  override it with something arbitrary.
- **`-n` (nosound), `-+rtaudio=null`, `-+rtmidi=null`** - always forced,
  applied *after* your own `<CsOptions>` (see below) so nothing you put
  there can override them. These aren't musical parameters, they're what
  makes host-driven audio/MIDI (via the API) possible at all; anything
  else here (e.g. an `-odac`) would break the whole embedding model.

Everything else is left to the `.csd`/`.orc` as normal Csound, most
notably:

- **ksmps** - your file's own `ksmps = N` line decides, by default. Only
  overridden if you explicitly pass a ksmps creation arg or set
  `@ksmps` (see below).
- Everything inside `<CsInstruments>`/`<CsScore>` - opcodes, instruments,
  tables, score events - is entirely yours, untouched.

`<CsOptions>` itself DOES work, but not the normal way: `csoundStart()`
runs before `csoundCompileCSD()` on purpose (see the ordering note
above), and per `csound.h` that means `csoundCompileCSD()`'s own
`<CsOptions>` handling never gets a chance to run - anything set that way
would apply too late. So the external reads `<CsOptions>` itself, as
plain text, and applies each flag via the API *before* `csoundStart()` -
functionally equivalent to a normal Csound `.csd`, just handled by hand
because of the ordering constraint. Anything in there gets applied,
except the small always-forced set above, which wins if there's a
conflict. Needed a real-world MIDI input flag (`-M0`) to reach this at
all, which is what prompted building this instead of leaving `<CsOptions>`
dead.

## Console verbosity (`@verbose`)

`verbose` is a real Max **attribute**, not just a message — the
Max-native equivalent of a Csound `-m` command-line flag. You can also
just put `-m<N>` directly in `<CsOptions>` now (see above); `@verbose`
additionally lets you change it live, at any time, from the control
inlet, which a `.csd`'s own `<CsOptions>` can't do. Sets Csound's console
message level (`csoundSetMessageLevel`, range `0-231`), default `0` =
quiet (no note-amplitude/out-of-range/benchmark chatter). Real compile
errors and warnings always print regardless of this setting.

Three ways to use it, all equivalent:

- As a creation flag: `csound7~ test.csd 32 @verbose 1`
- As a runtime message to the control inlet: `verbose 1`
- From the object's Inspector (right-click → Inspector), where it shows
  up as "Console Verbosity (0-231)"

## Forcing ksmps (`@ksmps`)

By default ksmps comes from the `.csd` itself (see above). If you do
want Max to force a specific value instead, two equivalent ways:

- The second creation arg, numeric: `csound7~ test.csd 32` (32 = ksmps)
- The `@ksmps` attribute, any time: `csound7~ test.csd @ksmps 32`, or as
  a runtime message `ksmps 32` / from the Inspector

Changing `@ksmps` while running triggers a full reset+recompile (ksmps
is only settled at `csoundStart()` time, same reason an automatic sr
change does too). Setting it back to unforced isn't currently exposed -
recreate the object without the arg/attribute if you want to hand
control back to the `.csd`.

MIDI: send `midi <status> <data1> <data2>` (3 ints) to the control inlet —
connect `midiin` → your own `pack`/reformatting upstream, then
`notein`/`massign` will work inside Csound, reading from the internal
queue.

## Prerequisites to build

1. Xcode (Command Line Tools at least): `xcode-select --install`
2. CMake >= 3.25: `brew install cmake`
3. Git

You don't need to download the Max SDK by hand: the official SDK's CMake
setup (`Cycling74/max-sdk-base`) is fetched automatically via `FetchContent`
at configure time — you just need an internet connection the first time.

## Build steps

### 1. Static build of Csound 7 (universal)

```bash
cd scripts
./build_csound_static.sh
```

This clones `csound/csound` (branch `develop`, which is the Csound 7 line —
if a stable `7.x` tag has been released by the time you read this, pin to
that instead, see the comment at the top of the script), builds it as a
static library twice (arm64 and x86_64) with only core + libsndfile +
libsamplerate, then runs `lipo` to merge into a universal build. Output in
`build/csound-install/universal/{lib,include}`.

The script builds libsndfile and libsamplerate from source as static
libraries first, then points Csound's own CMake configure at them directly
(this was needed after a real test build showed Csound picking up
Homebrew's dynamic `.dylib` versions instead — see git history / chat for
details if curious). The final static Csound library is named
`libCsoundLib64.a` (confirmed from a real build), already wired up in
`source/csound7_tilde/CMakeLists.txt`.

### 2. Build the external

You only need the Xcode Command Line Tools (the compiler) for this, not
the Xcode app itself. Fully from the terminal:

```bash
cd ..
mkdir -p build/external
cd build/external
cmake -G "Unix Makefiles" ../..
cmake --build . --config Release
```

This still produces a proper universal (arm64+x86_64) `.mxo`: clang builds
the fat binary the same way regardless of which CMake generator drives it.

If you'd rather see errors in an IDE, you can instead generate an Xcode
project and build/debug from there:

```bash
cmake -G Xcode ../..
cmake --build . --config Release
# or open the generated .xcodeproj in Xcode.app
```

The compiled external will come out as a universal `csound7~.mxo`. On
Apple Silicon you might need to ad-hoc sign it if Max complains:

```bash
codesign --force --deep -s - csound7~.mxo
```

### 3. Installation

Copy (or symlink) `csound7~.mxo`, the `plugins/` folder, and `examples/`
into a package folder under `~/Documents/Max 9/Packages/csound7/` (create
the `csound7/externals/`, `csound7/examples/` structure if you want to
follow the Max package convention).

## Windows

Implemented via `scripts/build_csound_static.ps1` (PowerShell, MSVC
toolchain) and `../.github/workflows/windows-build.yml` (a GitHub Actions
`windows-latest` runner, as a separate job from the PD side) - but
**unverified**, written without access to a Windows machine. Meant to be
proven for real by that workflow's first actual run (or by you, on a real
Windows box) - the same "aggressive first draft" situation the macOS build
script was in before its first real compile, just without a way for me to
close the loop myself this time.

The good news: unlike the PD side (which had to solve MSVC's refusal to
link a DLL with unresolved symbols by hand, see `../PD/README.md`'s own
Windows section), the Max SDK itself ships real, prebuilt Windows import
libraries directly inside `max-sdk-base`
(`c74support/max-includes/x64/MaxAPI.lib`,
`c74support/msp-includes/x64/MaxAudio.lib` - confirmed by actually
fetching `max-sdk-base` and looking, not assumed), and its own
`FindMaxSDK.cmake`/`max-posttarget.cmake` scripts already wire these up
automatically through the `max::external`/`max::glob` directory properties
this project's `source/csound7_tilde/CMakeLists.txt` already sets - along
with the `.mxe64` Windows output suffix, also confirmed directly in
`max-posttarget.cmake`. Nothing extra was needed for that part; the only
real changes were guarding the macOS-only framework/`-lc++`/`-lpthread`
linker lines behind `if(APPLE)` (previously unconditional - would have
broken Windows's linker outright) and fixing the static Csound/libsndfile/
libsamplerate lib file lookups to try Windows-appropriate `.lib` names via
`find_library()` rather than the hardcoded `.a` names.

If the first CI run fails, that's expected and useful - the two spots
flagged `UNVERIFIED` in `build_csound_static.ps1` (whether Csound's own
codebase compiles clean under MSVC without patches, and whether
`winflexbison`'s bison/flex behave closely enough to GNU's for Csound's
grammar files) are the most likely places a real fix will be needed.

## Files in this repo

- `CMakeLists.txt` — top level, bridges into max-sdk-base.
- `source/csound7_tilde/` — the external's source code.
- `scripts/build_csound_static.sh` — static universal Csound build.
- `examples/test.csd` — minimal test orchestra (single 400Hz tone, used
  for the initial "does audio come out at all" check).
- `examples/1_sine_two_controls.csd` — one oscillator, two live controls
  (`freq`, `amp`) from Max.
- `examples/2_audio_in_out.csd` — audio in -> audio out, with a `gain`
  control.
- `examples/3_buffer_player.csd` — `buffer~` -> table sample player
  (`buf2tab`, then `phasor`+`tablei`), with `rate`/`amp` controls.
- `examples/4_midi_synth.csd` — one-oscillator MIDI synth with an
  envelope, driven by `midi <status> <data1> <data2>` messages.
- `plugins/` — empty folder (with README) where you drop extra opcode
  `.dylib` files loaded dynamically.

These four are untested first drafts, same as everything else in this
project's first pass — expect to send me the real compile/console
output if any opcode name or rate mismatch trips something up.

## References

Sources actually fetched and read directly (not from memory) while
building this, used to confirm real function signatures/behavior rather
than guess:

- [`csound/csound`, `develop` branch, `include/csound.h`](https://raw.githubusercontent.com/csound/csound/develop/include/csound.h)
  — the real Csound 7 C API: `csoundCreate(hostData, opcodedir)`'s 2-arg
  signature (differs from Csound 6), `csoundSetMessageLevel`/
  `csoundGetMessageLevel`, the `OPARMS` struct (confirms `msglevel` is
  the `-m` flag's backing field), and critically the documented behavior
  of `csoundStart()` vs. `csoundCompileCSD()` ordering (calling `Start`
  first makes `<CsScore>` dispatch as realtime events and makes
  `<CsOptions>` be ignored — this is *documented in the header itself*,
  not an assumption).
- [`csound/csound`, `develop` branch, `include/msg_attr.h`](https://raw.githubusercontent.com/csound/csound/develop/include/msg_attr.h)
  — the real `CSOUNDMSG_TYPE_MASK` (`0x7000`), `CSOUNDMSG_ERROR`
  (`0x1000`), `CSOUNDMSG_WARNING` (`0x4000`) constants, used to fix a
  real bug in `cs7_msg_callback` where a guessed bitmask (`attr & 0x07`)
  never matched anything.
- [`csound/csound`, `develop` branch, `include/csound_rtmidi.h`](https://raw.githubusercontent.com/csound/csound/develop/include/csound_rtmidi.h)
  (fetched earlier in this project, before this file's revision history
  started) — confirmed `csoundSetHostMIDIIO` +
  `csoundSetExternalMidiInOpenCallback`/`ReadCallback`/`InCloseCallback`
  as the real MIDI mechanism, and that `csoundPushMidiMessage` does
  **not** exist in Csound 7 (an earlier assumption in chat, corrected
  after reading the actual header).
- [Csound 7 Manual — deprecated opcodes](https://csound.com/manual/deprecated/)
  — checked whether `outs` is officially deprecated (it isn't listed,
  but Csound 7 warns on it anyway at compile time regardless).

Everything Max-SDK-specific (`CLASS_ATTR_LONG`/`CLASS_ATTR_ACCESSORS`,
`proxy_new`/outlet ordering, `dsp_setup`/`dsp_add64`/`t_perfroutine64`,
`ext_path.h`'s `locatefile_extended`/`path_toabsolutesystempath`,
`ext_buffer.h`'s buffer~ functions, `jpatcher_api.h`'s
`jpatcher_get_filepath`, `object_obex_lookup(..., gensym("#P"), ...)`)
is based on well-established, widely-documented Max SDK patterns from
training knowledge, not a fresh fetch of `Cycling74/max-sdk-base` in
this conversation — these are exactly the parts flagged `VERIFY:` in
the code, and the ones that have needed real fixes (outlet ordering,
the `jpatcher_get_filepath` hybrid-path format, etc.) after you
compiled and ran the actual code and sent back the real output. That
loop — assume from documented convention, flag it, fix it against your
real build log — is how the Max-side details in this project have
actually been validated, as opposed to the Csound API details above,
which were confirmed against source before ever being used.
