# csound7~ manual (Max/MSP)

Full reference for how `csound7~` behaves and how to talk to it. For build
instructions and repo layout, see `README.md`. For runnable examples, see
`examples/` and `help/csound7~.maxhelp`.

## What it does

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
  not via `csoundPushMidiMessage` — that function does not exist in the
  real Csound 7 API. Csound calls our callback to "pull" MIDI bytes from an
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
  scratch - i.e. turns off the whole engine and restarts it from zero.
- `verbose <0-231>` also works as a plain runtime message (see below —
  it's actually a real attribute, but Max dispatches attribute-named
  messages the same way).
- `midi <status> <data1> <data2>` (3 ints) → queues a raw MIDI message for
  Csound's `notein`/`massign` etc. Connect `midiin` → your own
  `pack`/reformatting upstream to build the 3-number shape.

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
runs before `csoundCompileCSD()` on purpose, and per `csound.h` that means
`csoundCompileCSD()`'s own `<CsOptions>` handling never gets a chance to
run - anything set that way would apply too late. So the external reads
`<CsOptions>` itself, as plain text, and applies each flag via the API
*before* `csoundStart()` - functionally equivalent to a normal Csound
`.csd`, just handled by hand because of the ordering constraint. Anything
in there gets applied, except the small always-forced set above, which
wins if there's a conflict.

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
