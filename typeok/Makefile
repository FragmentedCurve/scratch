.include "../config.mk"

CFLAGS +=  -I.

test: test.c typeok.h
	${CC} ${CFLAGS} -o test test.c
	./test

clean:
	rm -f test

.PHONY:	clean
