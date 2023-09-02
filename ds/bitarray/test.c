#include <stdio.h>
#include <assert.h>

#include "bitarray.h"

int
main(int argc, char** argv)
{
	assert(BITARRAY_LEN(0)   == 1);
	assert(BITARRAY_LEN(1)   == 1);
	assert(BITARRAY_LEN(8)   == 1);
	assert(BITARRAY_LEN(16)  == 2);
	assert(BITARRAY_LEN(129) == 17);
	assert(BITARRAY_LEN(333) == 42);

	bitarray_t a[BITARRAY_LEN(333)] = {0};

	assert(bitarray_get(a,   0) == 0);
	assert(bitarray_get(a,  16) == 0);
	assert(bitarray_get(a, 331) == 0);

	bitarray_set(a,   0);
	bitarray_set(a,  16);
	bitarray_set(a, 331);

	assert(bitarray_get(a,   0) == 1);
	assert(bitarray_get(a,  16) == 1);
	assert(bitarray_get(a, 331) == 1);

	bitarray_unset(a,   0);
	bitarray_unset(a, 331);

	assert(bitarray_get(a,   0) == 0);
	assert(bitarray_get(a,  16) == 1);
	assert(bitarray_get(a, 331) == 0);

	printf("passed\n");

	return 0;
}