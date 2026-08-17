<CsoundSynthesizer>
<CsOptions>
; This section DOES work - the external reads and applies it itself
; before starting Csound (see the README for why csoundCompileCSD()'s
; own <CsOptions> handling can't be used here).
;
; -M0 enables realtime MIDI input via the host (Max) instead of a real
; device - without it, Csound never actually opens the MIDI input path,
; so massign below would sit there doing nothing no matter how many
; "midi" messages you send it (confirmed for real: notes queued with no
; errors, but the instrument never triggered, not even its init pass).
; The external ALSO forces "-M0" as a safety default even without this
; line, but writing it here is the normal, portable way to ask for it -
; matches how a real standalone Csound .csd would do it.
-M0
</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 4: single-oscillator MIDI synth with an envelope.
;
; Workflow in Max (see 4_midi_synth.maxpat): notein -> pack 0 0 (pitch,
; velocity) -> "prepend 144" (144 = raw note-on status byte, any
; channel - velocity 0 means note-off, standard MIDI convention) ->
; "prepend midi" -> csound7~'s control inlet. So for each note you send:
; "midi <status> <data1> <data2>", e.g. "midi 144 60 100" for a note-on,
; note 60, velocity 100 (see the two test message boxes in the .maxpat
; if you don't have a MIDI keyboard connected).
;
; massign routes MIDI note-on/off (any channel, "0") straight to
; instr 1 - Csound's own MIDI engine (fed by our host MIDI callback)
; automatically starts/stops an instance of instr 1 per key, exactly
; like it would with a real MIDI keyboard/device.
massign 0, 1

instr 1
    ; cpsmidi/ampmidi read the frequency/velocity of the MIDI note that
    ; triggered this instance - Csound 7 only exposes these as i-rate
    ; (confirmed against the real manual: "icps cpsmidi" / "iamp
    ; ampmidi iscal", no k-rate variant anymore, unlike Csound 6) -
    ; fine here since we just need each note's pitch/velocity once, at
    ; the moment it starts, not a continuously updating value. madsr is
    ; a standard ADSR that releases properly on note-off (needs the
    ; instrument to be a "held" note, which is exactly what
    ; massign-triggered notes are).
    ifreq cpsmidi
    print  ifreq
    iamp  ampmidi 0.3
    kenv  madsr 0.01, 0.15, 0.7, 0.3
    aSig  oscili iamp * kenv, ifreq
    out aSig, aSig
endin

</CsInstruments>
<CsScore>
; nothing here - notes come from MIDI messages only, see above.
</CsScore>
</CsoundSynthesizer>
