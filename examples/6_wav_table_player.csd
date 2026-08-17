<CsoundSynthesizer>
<CsOptions>
; This section DOES work - the external reads and applies it itself
; before starting Csound (see the README for why csoundCompileCSD()'s
; own <CsOptions> handling can't be used here). Nothing needed here for
; this example.
</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 6: pick a WAV/AIFF/MP3 file from disk in Max and load it
; DIRECTLY into a Csound table via GEN01 - no buffer~ involved at all
; (unlike example 3, which goes through a buffer~ you fill yourself
; first). This is the table-based counterpart of example 5's diskin
; streaming: whole file in RAM instead of streamed from disk, which
; costs more memory for long files but lets you use table-reading
; opcodes that need random access (looping, scrubbing, granular
; synthesis, etc. - not covered here, but this is the loading mechanism
; those would build on).
;
; The C side (csound7_diskinfile() in csound7_tilde.c) does ONLY ONE
; thing: it sets a Csound STRING CHANNEL called "wavpath" to whatever
; path you picked. No code generation, no ftgen anywhere in C. Every
; single step of turning that path into a table happens right here, in
; real, visible Csound code: instr 99 below reads the channel with
; chnget into a real string variable (Spath) and feeds THAT into ftgen.
; This is the exact same "diskinfile" mechanism example 5 uses to feed
; its own Sfile - same C function, same channel-setting call, just a
; different Csound instrument (and channel name) consuming it.
;
; Same visible-placeholder pattern as example 3's gitab1: table 1 is
; declared right here, as a 1-sample silent stub, until instr 99
; actually replaces it with the real file via GEN01 - same "declared
; empty, filled at runtime" idea, just with a different GEN (GEN01,
; reads a soundfile, vs. example 3's GEN02, reads literal numbers).
gitab1 ftgen 1, 0, 1, -2, 0

; instr 99: the loader. Reads the path back OUT of Csound's own string
; channel and does the real conversion - this is the "transformation
; from path to table" as genuine Csound code, not hidden in C:
instr 99
    Spath chnget "wavpath"
    i_cs7wav ftgen 1, 0, 0, 1, Spath, 0, 0, 0
    prints "wav2tab: loaded '%s' into table 1\n", Spath
endin
;
; Workflow in Max:
;   1. "opendialog" -> "prepend diskinfile wavpath" (NOT a typed message
;      box - see example 5's note about paths with spaces) -> csound7~'s
;      control inlet. Sets the "wavpath" string channel above.
;   2. Send "event i 99 0 0" to run the loader instrument - do this
;      AFTER step 1, not before (same discipline as buf2tab in example
;      3): the channel has to actually hold the new path first. This
;      runs instr 99 for a near-zero duration - it does its i-time-only
;      job (the chnget + ftgen above) and is done.
;   3. Send "event i 1 0 -1" to start playback - do this AFTER step 2,
;      not before: the table's real content is only there once instr 99
;      has actually run.
;   4. Optional controls while it plays:
;        wavrate 2     -> double speed / up an octave
;        wavrate 0.5   -> half speed / down an octave
;        wavamp  0.5   -> volume
;   5. "event i -1 0 0" to stop.
;   6. Loading a DIFFERENT file: stop first, "diskinfile wavpath" the
;      new file, "event i 99 0 0" again, then start - never reload a
;      table a running note is actively reading, same rule as buf2tab
;      in example 3.
;
; Why GEN01 instead of buf2tab: it reads the file itself, so the
; table carries the file's own samplerate AND channel-count metadata
; built in. loscil (below) uses that automatically to correct
; speed/pitch when the file's sr differs from the engine's, and to know
; whether to output one or two channels - none of the manual sr-channel
; passing (example 3) or uzi-per-channel looping (example 3's
; multichannel discussion) is needed here, Csound handles both itself.
;
; Caveat: loscil only supports MONO or STEREO tables, nothing wider -
; if you need arbitrary channel counts (e.g. a real 64-channel diffusion
; file), that's what example 5's diskin array form is for instead.
; If instr 1 starts while gitab1 is still the empty stub, ftchnls(itab)
; reads as mono (the stub is a plain 1-point GEN02 table, no file
; metadata) and loscil reads zeros - silence, same safe behavior as
; example 3, not an error.
instr 1
    itab    = gitab1
    ichnls  = ftchnls(itab)

    krate chnget "wavrate"
    if krate == 0 then
        krate = 1
    endif

    kamp chnget "wavamp"
    if kamp == 0 then
        kamp = 0.3  ; kept modest on purpose - confirmed for real that
    endif            ; 0.7 was way too loud as a forgotten-channel default.

    ; ibas (loscil's base-frequency arg) = 1 here on purpose: we don't
    ; know or care about the file's "musical" pitch, we just want
    ; straight sample playback, so krate=1 always means "original
    ; speed" regardless of what pitch info (if any) is in the file -
    ; same reasoning the official loscil manual example uses for plain
    ; sample playback.
    if ichnls == 1 then
        aL loscil kamp, krate, itab, 1
        aR = aL
    elseif ichnls == 2 then
        aL, aR loscil kamp, krate, itab, 1
    else
        aL = 0
        aR = 0
    endif
    out aL, aR
endin

</CsInstruments>
<CsScore>
; nothing here on purpose - trigger manually with "event i 1 0 -1"
; after loading the table with wav2tab, see the workflow above.
</CsScore>
</CsoundSynthesizer>
