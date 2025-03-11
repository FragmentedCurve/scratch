.include "../../config.mk"

.ifdef _BASE64_SWITCH
CFLAGS+= -D _BASE64_SWITCH
.elifdef _BASE64_IFELSE
CFLAGS+= -D _BASE64_IFELSE
.else
CFLAGS+= -D _BASE64_TABLE
.endif

BUFSIZE=1048576

test: validate data.bin encode decode perform_table perform_switch perform_ifelse
	./validate
	./encode < data.bin | ./decode > out.bin
	cmp data.bin out.bin
	./perform_table  < data.bin
	./perform_switch < data.bin
	./perform_ifelse < data.bin

perform_table perform_switch perform_ifelse:
	${CC} ${CFLAGS} -U _BASE64_SWITCH -U _BASE64_IFELSE -U _BASE64_TABLE -D BUFSIZE=${BUFSIZE} -D _BASE64_TABLE  -o perform_table   perform.c
	${CC} ${CFLAGS} -U _BASE64_SWITCH -U _BASE64_IFELSE -U _BASE64_TABLE -D BUFSIZE=${BUFSIZE} -D _BASE64_SWITCH -o perform_switch  perform.c
	${CC} ${CFLAGS} -U _BASE64_SWITCH -U _BASE64_IFELSE -U _BASE64_TABLE -D BUFSIZE=${BUFSIZE} -D _BASE64_IFELSE -o perform_ifelse  perform.c

data.bin:
	dd if=/dev/random of=data.bin bs=1 count=${BUFSIZE}

perform: perform.c
	${CC} ${CFLAGS} -o perform perform.c

encode: encode.c
	${CC} ${CFLAGS} -o encode encode.c

decode: decode.c
	${CC} ${CFLAGS} -o decode decode.c

validate: validate.c
	${CC} ${CFLAGS} -o validate validate.c

clean:
	rm -f perform_table perform_switch perform_ifelse encode decode validate out.bin

distclean: clean
	rm -f data.bin

.PHONY: test clean
