.include "../config.mk"

test: test.c typeok.h typeok_safe_math.h
	${CC} ${CFLAGS} -o test test.c
	./test

clean:
	rm -f test

.PHONY: run clean
