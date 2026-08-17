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

; Example 2: audio in -> audio out, with a gain control.
; Connect signal into inlets 1-2 of csound7~, hear it back out of
; outlets 1-2. Send "gain 0.5" to the control inlet to attenuate,
; "gain 1" for unity (the default).
instr 1
    print 1
    a1, a2 inch 1, 2
    kgain chnget "gain"
  
    out a1 * kgain, a2 * kgain
endin

</CsInstruments>
<CsScore>
i 1 0 -1
</CsScore>
</CsoundSynthesizer>
