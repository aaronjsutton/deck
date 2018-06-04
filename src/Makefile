CC 		= gcc
CFLAGS  = -Wall
LIBNAME	= deck

all: deck.o shuffle.o
	ar -r lib$(LIBNAME).a *.o

deck.o:
	$(CC) -c $(CFLAGS) deck.c

shuffle.o:
	$(CC) -c $(CFLAGS) shuffle.c

.PHONY: clean
clean:
	-rm *.o lib$(LIBNAME).a
