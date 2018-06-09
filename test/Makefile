CC 		  = gcc
SRCDIR  = ../src
LFLAG  = -L$(SRCDIR)
LDFLAGS = -ldeck

all: test-runner

test: test-runner
	./test-runner

test-runner: munit/munit.o deck_tests.o
	$(CC) $(LFLAG) deck_tests.o munit/munit.o $(LDFLAGS) -o test-runner

deck_tests.c:
	$(CC) $(CFLAGS) -c deck_tests.c

munit/munit.o:
	$(CC) -c munit/munit.c -o munit/munit.o

.PHONY: clean
clean:
	-rm *.o **/*.o test-runner
