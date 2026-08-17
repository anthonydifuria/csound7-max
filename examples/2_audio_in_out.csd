<CsoundSynthesizer>
<CsOptions>

</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 2: audio in -> audio out, with a gain control.
instr 1
    a1, a2 inch 1, 2
    kgain chnget "gain"
  
    out a1 * kgain, a2 * kgain
endin

</CsInstruments>
<CsScore>

i 1 0 -1
</CsScore>
</CsoundSynthesizer>
