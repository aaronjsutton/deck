CC 		= gcc
CFLAGS  = -Wall
LDFLAGS = -shared
LIBNAME	= deck

all: deck.o shuffle.o
	$(CC) $(CFLAGS) *.o -o lib$(LIBNAME).so $(LDFLAGS)

deck.o:
	$(CC) -c $(CFLAGS) deck.c

shuffle.o:
	$(CC) -c $(CFLAGS) shuffle.c

.PHONY: clean
clean:
	-rm *.o lib$(LIBNAME).so
