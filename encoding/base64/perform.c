#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "base64.h"

const char* version =
#ifdef _BASE64_SWITCH
	"_BASE64_SWITCH";
#endif
#ifdef _BASE64_IFELSE
	"_BASE64_IFELSE";
#endif
#ifdef _BASE64_TABLE
	"_BASE64_TABLE";
#endif

#ifndef BUFSIZE
#define BUFSIZE 1024*1024
#endif

int
main(int argc, char** argv)
{
	unsigned char* src = malloc(BUFSIZE);
	unsigned char* dst = malloc(BUFSIZE * 2);

	int m, n = 0;
	while ((m = read(STDIN_FILENO, src + n, BUFSIZE - n)) > 0) {
		n += m;
	}

	printf("READ %d BYTES\n", n);

	clock_t start = clock();
	for (int i = 0; i < 1000; i++) {
		base64_encode(dst, src, n);
	}
	clock_t end = clock();

	printf("ENCODING DATA WITH %s 1000 TIMES TOOK %d SECONDS.\n", version, (end - start) / CLOCKS_PER_SEC);

	return 0;
}
