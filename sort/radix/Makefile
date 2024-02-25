CFLAGS=-O3 -Wall -Werror -std=c99 -pedantic -pedantic-errors

radix.o: radix.c radix.h
	$(CC) $(CFLAGS) -c radix.c

test: radix.o test.c
	$(CC) $(CFLAGS) -o test test.c radix.o

clean:
	rm -f radix.o test

.PHONY: clean
