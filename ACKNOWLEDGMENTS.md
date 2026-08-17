# Acknowledgments

`csound7~` exists on the shoulders of decades of work by the Csound
community and the people who built the Csound-in-a-host pattern this
project follows. This isn't an exhaustive list of every Csound
contributor ever - just the people and prior projects most directly
relevant to what's being built here, and to what comes next
(Pure Data / plugdata versions).

## Csound itself

- **Barry Vercoe** - created Csound at MIT in 1985, the common ancestor
  of this entire lineage.
- **John P. ffitch** - long-time Csound maintainer, credited as one of
  the authors of the Csound API (`csound.h`) this project is built on.
- **Victor Lazzarini** - Csound co-developer; wrote **`csoundapi~`**,
  the Csound-in-Pure-Data external (part of
  [csound/csound_pd](https://github.com/csound/csound_pd)) - the direct
  reference for a future Pd/plugdata version of this project. Also
  documented the Csound 6 -> 7 host API migration this project relies
  on, and is credited as a `csound.h` API author.
- **Steven Yi** - Csound co-developer; updated and maintained
  **`csound~` for Max/MSP** for Csound 6 within the main Csound
  repository ([csound/csound_tilde](https://github.com/csound/csound_tilde))
  - the direct predecessor of this project in the Max/MSP world.
  Credited as a `csound.h` API author.
- **Michael Gogins** - Csound developer, `csound.h` API author,
  extensive work on Csound hosting (including later browser/WebAssembly
  embedding, conceptually similar to what this project does for Max).
- **Andres Cabrera** - Csound developer, `csound.h` API author, built
  `iCsound` and mobile (iOS/Android) Csound hosting examples - another
  precedent for "embed Csound inside someone else's runtime via the
  API," same problem this project solves for Max.
- **Matt Ingalls** - created the original **`csound~` for Max/MSP**,
  later maintained by **Davis Pyon** before Steven Yi's Csound 6 update.
  Credited as a `csound.h` API author.
- **Iain Duncan** (not to be confused with Iain McCurdy below - two
  different people) - built **`csound6~`**
  ([iainctduncan/csound_max](https://github.com/iainctduncan/csound_max)),
  a minimal Max/MSP object using the Csound 6 API for lower latency than
  the legacy `csound~`, described by its own author as largely a port of
  Victor Lazzarini's Csound object for Pure Data. Possibly the closest
  existing precedent to this project's own approach.
- **John D. Ramsdell** and **István Varga** - credited as `csound.h` API
  authors alongside the above.
- **Iain McCurdy** - prolific author of Csound tutorials and example
  `.csd` patches used across the Csound community for learning the
  language; not part of the host-API lineage above, but part of why
  Csound is approachable enough for a project like this to exist.

## Direct prior art

- [`csound/csound_tilde`](https://github.com/csound/csound_tilde) -
  `csound~` for Max/MSP. What this project's Max-side design (audio via
  `csoundPerformKsmps`, control channels, live recompilation) is a
  from-scratch, statically-linked take on.
- [`iainctduncan/csound_max`](https://github.com/iainctduncan/csound_max) -
  Iain Duncan's `csound6~`, a more modern, lower-latency take on the same
  idea using the Csound 6 API, itself a port of Lazzarini's Pd object.
  The closest existing relative of this project.
- [`csound/csound_pd`](https://github.com/csound/csound_pd) -
  `csoundapi~` for Pure Data, by Victor Lazzarini. The reference point
  for the Pd/plugdata version of this project mentioned as a future
  direction - reading its source is the natural next step whenever that
  work starts, since Pd's external API differs from Max's SDK but the
  underlying Csound API usage pattern will look familiar from this
  project.

## SDKs and libraries

See `THIRD-PARTY-LICENSES.md` for the licenses; credit here for the
software itself:

- **Cycling '74** - the Max SDK (`max-sdk-base`) this external is built
  against.
- **Erik de Castro Lopo** - author of libsndfile and libsamplerate,
  both statically linked into this project's Csound build.

---

Sources for the attributions above:
[csound/csound_tilde](https://github.com/csound/csound_tilde),
[csound/csound_pd](https://github.com/csound/csound_pd),
[Csound API reference (csound.h)](https://csound.com/docs/api/csound_8h.html),
[Victor Lazzarini - Wikipedia](https://en.wikipedia.org/wiki/Victor_Lazzarini).
