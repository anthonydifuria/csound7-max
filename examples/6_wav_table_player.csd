<CsoundSynthesizer>
<CsOptions>

</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 6: pick a WAV/AIFF/MP3 file from disk in Max and load it

gitab1 ftgen 1, 0, 1, -2, 0


instr 99
    Spath chnget "wavpath"
    i_cs7wav ftgen 1, 0, 0, 1, Spath, 0, 0, 0
    prints "wav2tab: loaded '%s' into table 1\n", Spath
endin

instr 1
    itab    = gitab1
    ichnls  = ftchnls(itab)

    krate chnget "wavrate"
    if krate == 0 then
        krate = 1
    endif

    kamp chnget "wavamp"

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

</CsScore>
</CsoundSynthesizer>
