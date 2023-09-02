#include <stdio.h>
#include <time.h>

#include "bitarray.h"

#define ARRAY_SIZE 0xfffffff

int
main(int argc, char** argv)
{
	bitarray_t arr[BITARRAY_LEN(ARRAY_SIZE)] = {0};

	clock_t start = clock();

	for (size_t i = 0; i < ARRAY_SIZE; ++i) {
		bitarray_set(arr, i);
	}

	clock_t end = clock();

	printf("Write Time: %d\n", end - start);


	start = clock();

	for (size_t i = 0; i < ARRAY_SIZE; ++i) {
		bitarray_set(arr, i);
	}

	end = clock();

	printf("Read Time: %d\n", end - start);

	return 0;
}