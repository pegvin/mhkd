# mhkd version
VERSION = 1.0

# paths
PREFIX = /usr/local
MANPREFIX = $(PREFIX)/share/man

# OpenBSD (uncomment)
#MANPREFIX = ${PREFIX}/man

# includes and libs
INCS = `pkg-config --cflags x11`
LIBS = `pkg-config --libs x11`

# flags
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Os $(INCS) -DVERSION=\"$(VERSION)\"
LDFLAGS  = $(LIBS)

# compiler and linker
CC = cc

