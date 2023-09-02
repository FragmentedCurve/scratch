CFLAGS = -Wall -Werror  -O3 -D_BITARRAY8

tests: test test_perform
	./test
	./test_perform

test: bitarray.h test.c
	$(CC)  $(CFLAGS) -o test test.c

test_perform: bitarray.h test_perform.c
	$(CC) $(CFLAGS) -o test_perform test_perform.c

clean:
	rm -f test test_perform

.PHONY: tests clean