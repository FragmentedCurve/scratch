#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "base64.h"

struct {
	char* raw;
	char* base64;
} vectors[] = {
	{ "",       ""         },
	{ "f",      "Zg=="     },
	{ "fo",     "Zm8="     },
	{ "foo",    "Zm9v"     },
	{ "foob",   "Zm9vYg==" },
	{ "fooba",  "Zm9vYmE=" },
	{ "foobar", "Zm9vYmFy" },
};

int
main()
{
	char buf[1024];
	
	for (size_t i = 0; i < sizeof(vectors) / sizeof(vectors[0]); ++i) {
		size_t raw_len = strlen(vectors[i].raw);
		size_t base64_len = strlen(vectors[i].base64);

		printf("validating %s\n", vectors[i].base64);
		assert(base64_valid(vectors[i].base64, base64_len));

		printf("encoding %s\n", vectors[i].raw);
		memset(buf, 0, sizeof(buf));
		base64_encode(buf, vectors[i].raw, strlen(vectors[i].raw));
		assert(strcmp(buf, vectors[i].base64) == 0);

		printf("decoding %s\n", vectors[i].base64);
		memset(buf, 0, sizeof(buf));
		base64_decode(buf, vectors[i].base64, strlen(vectors[i].base64));
		assert(strcmp(buf, vectors[i].raw) == 0);

		printf("decoded size is %zu, expected %zu\n", raw_len, base64_decoded_size(vectors[i].base64, base64_len));
		assert(raw_len == base64_decoded_size(vectors[i].base64, base64_len));

		printf("decoded size is %zu, expected %zu <= %zu\n", raw_len, raw_len, base64_decoded_max(base64_len));
		assert(raw_len <= base64_decoded_size(vectors[i].base64, base64_len));

		printf("encoded size is %zu, expected %zu\n", base64_len, base64_encoded_size(raw_len));
		assert(base64_len == base64_encoded_size(raw_len));
	}
	printf("passed.\n");
	
	return 0;
}
