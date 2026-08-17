<CsoundSynthesizer>
<CsOptions>

</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 3: simple buffer~ -> table sample player
gitab1 ftgen 1, 0, 1, -2, 0

instr 1
    itab = gitab1
    ilen = ftlen(itab)
    krate chnget "rate"
    kamp  chnget "amp"

    ifsr chnget "buf_sr_1"

    aphase phasor krate * (ifsr / ilen)
    aSig tablei aphase, itab, 1, 0, 1
    aSig = aSig * kamp
    out aSig, aSig
endin

</CsInstruments>
<CsScore>

</CsScore>
</CsoundSynthesizer>
