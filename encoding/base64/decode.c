#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include "base64.h"
#define CHUNK_SRC 3 * 256
#define CHUNK_DST 4 * 256

int
main(int argc, char** argv)
{
	int n;
	unsigned char src[CHUNK_SRC];
	unsigned char dst[CHUNK_DST];

	while ((n = read(STDIN_FILENO, src, CHUNK_SRC)) > 0) {
		if (!base64_valid((char*) src, n))
			return -1;
		size_t x = base64_decode(dst, src, n);
		write(STDOUT_FILENO, dst, x);
	}

	return 0;
}
