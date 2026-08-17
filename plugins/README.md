# plugins/

Folder for extra Csound opcodes loaded **dynamically** at runtime
(`csoundLoadPlugins()`, called by the external as soon as it creates the
Csound instance — see `csound7_load_plugins_dir()` in `csound7_tilde.c`).

The external's static core does NOT include faust, fluidsynth, STK, OSC,
etc. — if you need them, drop the `.dylib` compiled for Csound 7 in here
(matching architecture/ABI of your build; if you built universal you need
either a universal plugin or at least the right one for your machine), and
it will be loaded automatically on the next startup, with no rebuild
required.

Handy source of precompiled binaries for many extra opcodes:
https://github.com/csound-plugins/csound-plugins

## Dynamic loading verification test

The tracked task ("plugins/ folder for dynamic opcodes + loading test")
still needs, here, a patch/procedure that:

1. drops a known, simple `.dylib` plugin into this folder,
2. restarts/recreates the `csound7~` object,
3. verifies from the Max console (`csoundSetMessageCallback` — already
   wired to Max's console post, see `cs7_msg_callback` in the code) that
   the plugin loaded without errors,
4. calls one of the new opcodes from a test orchestra and confirms it
   makes sound.

This piece isn't in the first round of code yet — the actual test with a
real `.dylib` is left for the next round once the base build works.
