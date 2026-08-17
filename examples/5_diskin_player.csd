<CsoundSynthesizer>
<CsOptions>

</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 5: pick a WAV/AIFF/MP3 file from disk in Max and STREAM it
instr 1
    Sfile chnget "wavpath"

    kamp chnget "wavamp"

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

</CsScore>
</CsoundSynthesizer>
