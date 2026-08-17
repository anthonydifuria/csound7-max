# Third-party licenses

`csound7~` statically links against several third-party libraries, and its
build system fetches the Max SDK headers. This file lists exactly what's
used, under which license, where the source comes from, and - for the two
LGPL components - how this project satisfies the LGPL's static-linking
requirements.

This is not legal advice. It's a best-effort summary based on the plain
text of each license, put together because static linking of LGPL code
specifically needs a bit of care. If you plan to distribute this project
commercially or in a context where the details matter, get an actual
legal opinion.

## Summary table

| Component      | License          | How it's used                          |
|-----------------|-----------------|-----------------------------------------|
| Csound 7        | LGPL 2.1 (or later) | statically linked (`libCsoundLib64.a`) |
| libsndfile      | LGPL 2.1 (or later) | statically linked (`libsndfile.a`)     |
| libsamplerate   | BSD-2-Clause     | statically linked (`libsamplerate.a`)  |
| Max SDK (`max-sdk-base`) | Permissive, MIT-style (Cycling '74) | headers/CMake scripts used at build time, fetched via `FetchContent`, not vendored in this repo |

## Csound 7 - LGPL 2.1 (or later)

- Source: <https://github.com/csound/csound> (this project builds the
  `develop` branch by default - see `scripts/build_csound_static.sh`; if
  you've rebuilt against a specific tag or commit, record it here or in
  your own build notes, since that's the exact source your binary
  corresponds to. Csound's own version banner prints its git commit hash
  at startup, e.g. `[commit: 0aae1a9a157ae49a80f71543ae421479877eb6a2]` -
  worth saving whenever you rebuild for distribution).
- License text: identical to the LGPL 2.1 reproduced in this project's
  own `LICENSE` file, fetched directly from
  <https://raw.githubusercontent.com/csound/csound/develop/COPYING>.

## libsndfile - LGPL 2.1 (or later)

- Source: <https://github.com/libsndfile/libsndfile>
- License text: same LGPL 2.1, fetched directly from
  <https://raw.githubusercontent.com/libsndfile/libsndfile/master/COPYING>.

### How the LGPL's static-linking requirement is satisfied

The LGPL 2.1 (section 6) allows linking LGPL code into a non-free/closed
combined work, statically or dynamically, but requires that the person
who receives that combined work is able to modify the LGPL library and
relink it. Since this whole project builds Csound and libsndfile *from
their own upstream source* via `scripts/build_csound_static.sh`, rather
than vendoring a prebuilt blob, anyone who has this repository already
has everything needed to swap in a modified Csound/libsndfile and rebuild
the external from scratch - which is exactly what section 6(a) asks for.

This only holds as long as **the source and build scripts are
distributed together with the compiled external** - if `csound7~.mxo` is
ever handed out on its own, without this repository, the LGPL's
conditions aren't met unless one of the license's other options is used
instead (e.g. a standing public repository link, or a written offer valid
for at least three years to provide the corresponding source - see
section 6, options a-e, in the full text). The simplest way to stay
compliant: keep this project's source publicly available (e.g. a public
GitHub repo) and always point to it alongside the compiled binary.

## libsamplerate - BSD-2-Clause

- Source: <https://github.com/libsndfile/libsamplerate>
- Copyright (c) 2012-2016, Erik de Castro Lopo <erikd@mega-nerd.com>
- License text, fetched directly from
  <https://raw.githubusercontent.com/libsndfile/libsamplerate/master/COPYING>:

```
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
```

No copyleft obligation - permissive, just requires keeping this notice
around, which this file does.

## Max SDK (`Cycling74/max-sdk-base`) - permissive, MIT-style

- Source: <https://github.com/Cycling74/max-sdk-base> (fetched
  automatically at configure time via CMake's `FetchContent` - not
  vendored/copied into this repository).
- Copyright (c) 2021, Cycling '74. All rights reserved.
- License text, fetched directly from
  <https://raw.githubusercontent.com/Cycling74/max-sdk-base/main/LICENSE.md>:

```
Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```

No copyleft obligation - this is why `csound7_tilde.c` itself doesn't
need to be MIT-licensed just because it's built against these headers;
LGPL was chosen for this project's own code as a separate decision (see
`LICENSE`), for consistency with Csound/libsndfile rather than because
the Max SDK requires it.

## What about Max/MSP itself?

Max/MSP the application is not distributed by this project - end users
need their own licensed copy of Max to load `csound7~` at all, same as
any other third-party external. Nothing here redistributes Cycling '74's
Max application or its runtime, only an addon built against their
publicly published SDK headers, which is exactly what that SDK is for.
