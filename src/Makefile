CC 		= gcc
CFLAGS  = -Wall
LIBNAME	= deck
PREFIX = /usr/local/

all: deck.o shuffle.o
	ar -r lib$(LIBNAME).a *.o

deck.o: deck.c
	$(CC) -c $(CFLAGS) deck.c

shuffle.o: shuffle.c
	$(CC) -c $(CFLAGS) shuffle.c

.PHONY: clean
clean:
	-rm *.o lib$(LIBNAME).a

install: libdeck.a
	install -m 0755 $(PREFIX)/lib/
