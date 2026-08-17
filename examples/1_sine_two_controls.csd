<CsoundSynthesizer>
<CsOptions>

</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 1: single oscillator, two live controls from Max.
instr 1
    kfreq chnget "freq"
    kamp  chnget "amp"

    aSig oscili kamp, kfreq
    out aSig, aSig
endin

</CsInstruments>
<CsScore>

i 1 0 -1
</CsScore>
</CsoundSynthesizer>
