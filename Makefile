# mhkd - mini hotkey daemon
# See LICENSE file for copyright and license details.

include config.mk

SRC = mhkd.c
OBJ = $(SRC:.c=.o)

all: options mhkd

options:
	@echo mhkd build options:
	@echo "CFLAGS   = $(CFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"
	@echo "CC       = $(CC)"

.c.o:
	$(CC) -c $(CFLAGS) $<

config.h:
	cp config.def.h $@

$(OBJ): config.h config.mk

mhkd: mhkd.o
	$(CC) -o $@ mhkd.o $(LDFLAGS)

clean:
	rm -f mhkd $(OBJ) mhkd-$(VERSION).tar.gz

dist: clean
	mkdir -p mhkd-$(VERSION)
	cp LICENSE Makefile README.md config.def.h config.mk mhkd.1 $(SRC) mhkd-$(VERSION)
	tar -cf mhkd-$(VERSION).tar mhkd-$(VERSION)
	gzip mhkd-$(VERSION).tar
	rm -rf mhkd-$(VERSION)

install: all
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f mhkd $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/mhkd
	mkdir -p $(DESTDIR)$(MANPREFIX)/man1
	sed "s/VERSION/$(VERSION)/g" < mhkd.1 > $(DESTDIR)$(MANPREFIX)/man1/mhkd.1
	chmod 644 $(DESTDIR)$(MANPREFIX)/man1/mhkd.1

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/mhkd $(DESTDIR)$(MANPREFIX)/man1/mhkd.1

.PHONY: all options clean dist install uninstall

