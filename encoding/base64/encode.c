#include <unistd.h>
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
		base64_encode(dst, src, n);
		write(STDOUT_FILENO, dst, base64_encoded_size(n));
	}

	return 0;
}
