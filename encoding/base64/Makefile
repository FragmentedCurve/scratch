.include "../../config.mk"

.if _BASE64_SWITCH
CFLAGS+= -D _BASE64_SWITCH
.elifdef _BASE64_IFELSE
CFLAGS+= -D _BASE64_IFELSE
.else
CFLAGS+= -D _BASE64_TABLE
.endif

test: validate perform data.bin encode decode
	./validate
	./encode < data.bin | ./decode > out.bin
	cmp data.bin out.bin
	./perform < data.bin

data.bin:
	dd if=/dev/random of=data.bin bs=1 count=1048576

perform: perform.c
	${CC} ${CFLAGS} -o perform perform.c

encode: encode.c
	${CC} ${CFLAGS} -o encode encode.c

decode: decode.c
	${CC} ${CFLAGS} -o decode decode.c

validate: validate.c
	${CC} ${CFLAGS} -o validate validate.c

clean:
	rm -f perform encode decode validate

.PHONY: test clean
