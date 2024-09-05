.include "../../config.mk"

CHUNK_SIZE  = 8
CHUNK_COUNT = 100000

test: test.c radix.c radix.h
	${CC} ${CFLAGS} -o test test.c radix.c
	./test -m -s ${CHUNK_SIZE} -n ${CHUNK_COUNT}

clean:
	rm -f radix.o test

.PHONY: clean
