CC 		= clang


test: test-runner
	./test-runner

test-runner: munit/munit.o
	$(CC) tests.c munit/munit.o -o test-runner

munit/munit.o:
	$(CC) -c munit/munit.c -o munit/munit.o

.PHONY: clean
clean:
	-rm *.o **/*.o test-runner
