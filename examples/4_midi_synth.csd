<CsoundSynthesizer>
<CsOptions>

-M0
</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 4: single-oscillator MIDI synth with an envelope.
massign 0, 1

instr 1
    ifreq cpsmidi
    iamp  ampmidi 0.3

    aenv  madsr 0.01, 0.15, 0.7, 0.3
    aSig  oscili iamp , ifreq
    out aSig * aenv, aSig * aenv
endin

</CsInstruments>
<CsScore>

</CsScore>
</CsoundSynthesizer>
