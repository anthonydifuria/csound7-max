<CsoundSynthesizer>
<CsOptions>

-M0
</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 4_1: FM MIDI synth with an envelope.
massign 0, 1

instr 1
    ifreq cpsmidi
    iamp  ampmidi 0.3

    aenv  madsr 0.01, 0.15, 0.7, 2.3
    aMod  oscili iamp * ifreq, ifreq
    aSig  oscili iamp , ifreq + aMod
    aSig2  oscili iamp , ifreq + 1 + aMod
    out aSig * aenv * 0.5, aSig2 * aenv * 0.5
endin

</CsInstruments>
<CsScore>

</CsScore>
</CsoundSynthesizer>
