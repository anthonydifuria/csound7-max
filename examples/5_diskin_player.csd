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

; Example 5: pick a WAV/AIFF/MP3 file from disk in Max and STREAM it
; straight off the hard drive - no buffer~, no table, no preloading into
; RAM. Good for long files (an hour-long file costs the same tiny bit of
; RAM as a 2-second one).
;
; This uses soundin, not diskin2: diskin2 turned out to have a real
; normalization bug in this Csound 7 build - confirmed by testing (only
; a ~0.0001 amp multiplier brought the volume back to normal, which is
; the same order of magnitude as 1/32768, the scale factor for 16-bit
; samples). That strongly points at diskin2 failing to apply 0dbfs
; correctly for this file's format - treating samples as if 0dbfs were
; still 32768 (the pre-Csound-5 convention) instead of the 1 set below,
; so everything comes out ~32768x too loud. soundin doesn't have this
; problem, confirmed by ear with no correction factor needed.
;
; Trade-off: soundin has no kpitch/rate control (always plays at the
; file's original speed) and no reverse playback - diskin (no "2",
; the older opcode diskin2 was meant to replace) does have both and
; wasn't fully ruled out as also buggy, so it's worth a quick try
; later if rate control turns out to matter more than this detour cost.
;
; Workflow in Max:
;   1. An "opendialog" object, banged, pops the native file picker and
;      outputs the chosen file's FULL PATH as a single symbol from its
;      left outlet. IMPORTANT: route that outlet straight into a
;      "prepend diskinfile wavpath" object (NOT through a typed message
;      box) before sending it to csound7~'s control inlet - a message
;      box re-parses its text and SPLITS on spaces, breaking any path
;      that contains a space (very common in real filenames/folders).
;      "prepend" just tacks its own arguments onto the front of
;      whatever list arrives, without re-parsing anything, so the path
;      survives intact even with spaces in it.
;      Net result: csound7~ receives "diskinfile wavpath <full path>".
;   2. "wavpath" above is just a name - it becomes a Csound string
;      channel called "wavpath" (see chnget "wavpath" in instr 1
;      below), you can pick any name, it only has to match on both
;      sides. Using a different name per instance lets you run several
;      independent players side by side.
;   3. Send "event i 1 0 -1" to start playback - do this AFTER
;      "diskinfile", not before: the file is opened once, at the
;      instant this instrument instance starts (same ordering
;      discipline as buf2tab in example 3).
;   4. Optional control while it plays:
;        wavamp  0.5   -> volume
;   5. "event i -1 0 0" to stop.
;   6. Loading a DIFFERENT file: stop first, send a new "diskinfile
;      wavpath <path>", then start again - same discipline as buf2tab.
;
; No sr handling needed on our end - soundin matches the file's
; samplerate to the engine's on its own. Channel count IS handled
; manually here though (soundin has no auto-widening like loscil/
; diskin2 do): filenchnls reads the file's channel count at init, and
; a mono file gets copied to both outputs so it isn't silent on one
; side - same if/elseif pattern as example 6's loscil code.
instr 1
    Sfile chnget "wavpath"

    kamp chnget "wavamp"
    if kamp == 0 then
        kamp = 0.3  ; kept modest on purpose, same reasoning as example 6
    endif

    ichnls filenchnls Sfile

    if ichnls == 1 then
        aL soundin Sfile
        aR = aL
    elseif ichnls >= 2 then
        aL, aR soundin Sfile
    else
        aL = 0
        aR = 0
    endif
    out aL * kamp, aR * kamp
endin

</CsInstruments>
<CsScore>
; nothing here on purpose - trigger manually with "event i 1 0 -1"
; after sending "diskinfile wavpath <path>", see the workflow above.
</CsScore>
</CsoundSynthesizer>
