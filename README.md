# mhkd - mini hotkey daemon
originally written by [Peter Hofmann](https://www.uninformativ.de/contact.html), mhkd is a extended fork of [nhkd](https://www.uninformativ.de/git/nhkd/)

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
while sleep 0.25; do nhkd; done &
```

The loop ensures that you can easily restart the daemon by killing it.

---
# Thanks

