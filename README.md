# mhkd - mini hotkey daemon
originally written by [Peter Hofmann](https://www.uninformativ.de/contact.html), mhkd is a fork of [nhkd](https://www.uninformativ.de/git/nhkd/)

---
## Installation

nhkd depends on `libx11` and expects to be run on a POSIX-ish operating system.

You must customize the program by creating your own config.h based on
config.def.h. In any case, config.h must exist in order to build the
program.

To build the program and install it to /usr/local:

```
$ make
# make install
```

## Running

Run it from your ~/.xinitrc:

```bash
while sleep 0.25; do mhkd; done &
```

The loop ensures that you can easily restart the daemon by killing it.

---
## My Personal Config

```bash
# ~/.xinitrc

mhkd &
```

```c
// config.h

bool debug_print_spawned_command = false;

struct MouseEvent mouse_events[] = {
    { 0, 0, 0, 0, NULL }
};

struct KeyEvent key_events[] = {
    { KeyPress, 0, XF86XK_AudioLowerVolume, "sh -c \"bash ~/.local/bin/volume down; bash ~/.local/bin/dwmbar once;\"" },
    { KeyPress, 0, XF86XK_AudioMute, "sh -c \"bash ~/.local/bin/volume toggle; bash ~/.local/bin/dwmbar once;\"" },
    { KeyPress, 0, XF86XK_AudioRaiseVolume, "sh -c \"bash ~/.local/bin/volume up; bash ~/.local/bin/dwmbar once;\"" },
};
```

My config is simple, it runs a command on volume up, down & mute.

---
# Thanks

