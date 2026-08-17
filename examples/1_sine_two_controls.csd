<CsoundSynthesizer>
<CsOptions>
; This section DOES work - the external reads and applies it itself,
; by hand, before starting Csound (see the README: csoundStart() runs
; before csoundCompileCSD(), so csoundCompileCSD()'s own normal
; <CsOptions> handling would be too late). sr/nchnls are still always
; forced from the external regardless of anything you put here (Max
; needs to know them before this file is even read); ksmps comes from
; this file's own "ksmps" line below (or force it with a creation
; arg / @ksmps if you want Max to decide instead).
</CsOptions>
<CsInstruments>

nchnls   = 2
nchnls_i = 2
0dbfs    = 1
ksmps    = 32

; Example 1: single oscillator, two live controls from Max.
; Send to the control inlet:
;   freq 880   -> sets frequency in Hz
;   amp  0.3   -> sets amplitude (0-1)
; Defaults kick in the first time each channel is read, before you've
; sent anything.
instr 1
    kfreq chnget "freq"
    kamp  chnget "amp"

    aSig oscili kamp, kfreq
    out aSig, aSig
endin

</CsInstruments>
<CsScore>
; held note (negative duration), turned off with "event i -1 0 0" if
; you ever want to silence it completely.
i 1 0 -1
</CsScore>
</CsoundSynthesizer>
