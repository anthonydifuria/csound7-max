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

; Example 3: simple buffer~ -> table sample player (no granular
; synthesis, just phasor + tablei reading a table end to end and
; looping).
;
; gitab1 is a named global i-variable holding the Csound table
; number, instead of a bare "1" scattered around the file - makes it
; obvious what the number means, and easy to add gitab2, gitab3, etc.
; if you extend this example with more players.
;
; Starts as a 1-sample silent stub, right here so it's visible in the
; file instead of appearing "out of nowhere" - "buf2tab" (see
; csound7_buf2tab() in csound7_tilde.c) resizes it to EXACTLY fit
; whatever buffer~ you load, no wasted preallocation.
;
; This resize is only safe because instr 1 below is NOT auto-started
; in the score - nothing is reading table 1 when buf2tab runs. Never
; send buf2tab while instr 1 is already playing: recreating a table
; that a running tablei is actively reading frees memory out from
; under it and crashes Max, confirmed for real. Always stop first
; ("event i -1 0 0"), reload, then (re)start ("event i 1 0 -1") - see
; the workflow below.
;
; IMPORTANT: gitab1's value (1) is only a name INSIDE this file - the
; Max side has no idea what "gitab1" is, so the number you send with
; "buf2tab mybuf 1" has to match it by hand. If you change gitab1's
; value below, update the message you send from Max too - and also the
; "buf_sr_1" channel name read in instr 1 below (buf2tab always names
; it "buf_sr_<tabnum>", set automatically, nothing to send from Max).
gitab1 ftgen 1, 0, 1, -2, 0

; NOTE: buffer~ stores multichannel audio interleaved (L,R,L,R,... for
; stereo) - buf2tab copies raw samples 1:1 with no de-interleaving, so
; for a clean read here load a MONO soundfile into your buffer~ (a
; stereo one will still copy, just alternating L/R samples into the
; table - noisy, not a crash, just wrong).
;
; Workflow (first load, nothing playing yet):
;   1. Load a MONO soundfile into a buffer~ in Max (any name, e.g.
;      "mybuf").
;   2. Send "buf2tab mybuf 1" to the control inlet - resizes table 1
;      to exactly the buffer~'s length and copies its samples in.
;   3. Send "event i 1 0 -1" to start playback. Important: do this
;      AFTER buf2tab, not before - the table's length is only read
;      once, at the instant this instrument instance starts.
;   4. Optional controls while it plays:
;        rate 2     -> double speed (also raises pitch, like a sampler)
;        rate -1    -> reverse
;        rate 0.5   -> half speed
;        amp  0.5   -> volume
;   5. "event i -1 0 0" to stop.
;
; Loading a DIFFERENT sample later: always stop first ("event i -1 0
; 0"), send buf2tab with the new buffer~, then start again ("event i 1
; 0 -1") - same three-step workflow as above, never buf2tab while
; instr 1 is still playing.
instr 1
    itab = gitab1
    ilen = ftlen(itab)
    krate chnget "rate"
    kamp  chnget "amp"

    ; ifsr is the buffer~'s OWN native samplerate (set by buf2tab, see
    ; csound7_buf2tab() in csound7_tilde.c), NOT the engine's "sr" - do
    ; NOT use the engine sr here. A table is just a bag of numbers with
    ; no built-in notion of time; the only thing that tells you how many
    ; of those numbers correspond to one real second is the samplerate
    ; the source was RECORDED at. The engine's sr only says how many
    ; numbers per second Csound computes while performing - a totally
    ; different thing that happens to equal the source's sr only by
    ; coincidence. Using the engine sr here "worked" for a same-rate
    ; file and played back at the wrong speed for a different-rate one
    ; (confirmed for real: a file recorded at double the engine's sr
    ; played back at double speed - fixed by switching to this channel
    ; instead of "sr").
    ifsr chnget "buf_sr_1"

    ; phasor cycling once over the table's full length per "rate"
    ; seconds' worth of *source* samples - ixmode=1 on tablei means the
    ; index is read as a 0-1 normalized phase.
    ; MUST be the a-rate phasor/tablei pair here, not k-rate: tablei's
    ; a-rate output (ares tablei andx, ...) requires an a-rate index -
    ; feeding it a k-rate one throws "table: index type inconsistent
    ; with output" at init (confirmed from a real run).
    aphase phasor krate * (ifsr / ilen)
    aSig tablei aphase, itab, 1, 0, 1
    aSig = aSig * kamp
    out aSig, aSig
endin

</CsInstruments>
<CsScore>
; nothing here on purpose - trigger manually with "event i 1 0 -1"
; after loading the table with buf2tab, see the instructions above.
</CsScore>
</CsoundSynthesizer>
