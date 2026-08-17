// pageswitch.js - shows exactly one of the 6 "pageN" bpatchers (varname
// page1..page6) and hides the rest, driven by an int 0-5 coming from the
// number message boxes above them in csound7~.maxhelp.
outlets = 0;

function msg_int(v) {
    for (var i = 1; i <= 6; i++) {
        var b = patcher.getnamed("page" + i);
        if (b) {
            b.hidden = (i - 1 === v) ? 0 : 1;
        }
    }
}
