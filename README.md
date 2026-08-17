# csound7~ — Csound 7 embedded as a monolithic, statically-linked Max/MSP external

*by Anthony Di Furia — anthonydifuria.sound@gmail.com*

A Max/MSP external (`csound7~`) that embeds the Csound 7 engine
**statically** inside the binary: no separate Csound install needed on the
end user's machine, no risk of version mismatch. Audio in/out inlets are
sized automatically from your `.csd`, and a message protocol on the
control inlet lets you set channels, trigger events, hot-recompile,
bridge to `buffer~`, and more.

**For the full manual** (message protocol, what's forced by Max vs. left
to the `.csd`, `@verbose`/`@ksmps`) **see `MANUAL.md`.** This file covers
building and installing the external. Runnable examples are in
`examples/`, and `help/csound7~.maxhelp` is the in-Max reference patch.

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

Builds successfully via `scripts/build_csound_static.ps1` (PowerShell,
MSVC toolchain) and `.github/workflows/windows-build.yml` (GitHub Actions
`windows-latest` runner) - verified with real CI runs, not just assumed
from reading the build files. Getting there took a few real rounds of
fixes, kept here as a record of the non-obvious gotchas:

- CMake couldn't auto-detect Visual Studio on the runner ("Generator
  Visual Studio 17 2022 could not find any instance of Visual Studio"),
  even though it's installed there - switched to the Ninja generator
  with `ilammy/msvc-dev-cmd@v1` setting up the compiler on `PATH`
  explicitly instead of relying on CMake's own VS-instance discovery.
- Csound's own CMakeLists.txt hard-fails on MSVC without a `dirent.h`
  (a POSIX header MSVC doesn't ship) - fixed by fetching the well-known
  `tronkko/dirent` single-header shim and pointing the compiler at it.
- `csound7_tilde.c` used `pthread_mutex_t`/`strcasecmp` directly - neither
  exists on MSVC. Shimmed locally with a Win32 `CRITICAL_SECTION`-backed
  mutex and `_stricmp`, active only `#ifdef _WIN32`.
- The final link failed with dozens of unresolved Winsock symbols
  (`bind`, `htons`, ...) - Csound's static lib bundles a UDP
  server/console feature that needs `ws2_32.lib`, not linked by default.
- The final link also failed with unresolved CRT symbols (`rand`,
  `access`, ...) - a runtime-library mismatch: `max-sdk-base`'s own
  `max-pretarget.cmake` forces the static CRT (`/MT`) to match its
  prebuilt `MaxAPI.lib`/`MaxAudio.lib`, but only
  `if (CMAKE_GENERATOR MATCHES "Visual Studio")` - since Ninja is used
  instead (see above), that forcing was skipped. Fixed by setting
  `CMAKE_MSVC_RUNTIME_LIBRARY` to the same static-CRT value ourselves,
  generator-independently.

Unlike the PD side (which had to solve MSVC's refusal to link a DLL with
unresolved *host* symbols by hand, via a hand-written stub import
library - see the `csound7-pd` repo's own Windows notes), the Max SDK
itself ships real, prebuilt Windows import libraries directly inside
`max-sdk-base` (`c74support/max-includes/x64/MaxAPI.lib`,
`c74support/msp-includes/x64/MaxAudio.lib`), and its own
`FindMaxSDK.cmake`/`max-posttarget.cmake` scripts wire these up
automatically - including the `.mxe64` output suffix - through the
`max::external`/`max::glob` directory properties this project's
`source/csound7_tilde/CMakeLists.txt` already sets.

## Files in this repo

- `MANUAL.md` — full reference: message protocol, `.csd` vs. Max-forced
  parameters, `@verbose`/`@ksmps`.
- `CMakeLists.txt` — top level, bridges into max-sdk-base.
- `source/csound7_tilde/` — the external's source code.
- `scripts/build_csound_static.sh` / `.ps1` — static Csound build
  (macOS/Windows).
- `examples/` — six runnable example patches + matching `.csd` files:
  a two-control oscillator, audio in/out with gain, a buffer~/table
  player, a MIDI synth, disk-streamed playback, and table-based WAV
  playback. Also `examples/test.csd`, a minimal single-tone orchestra
  used for the initial "does audio come out at all" check.
- `help/csound7~.maxhelp` — the object's in-Max help patch (navigable,
  one bpatcher per example).
- `plugins/` — empty folder (with README) where you drop extra opcode
  `.dylib` files loaded dynamically.
- `.github/workflows/` — CI: builds macOS and Windows on every push (no
  Linux job here - Max/MSP doesn't run on Linux; see the `csound7-pd`
  repo for that one).

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
