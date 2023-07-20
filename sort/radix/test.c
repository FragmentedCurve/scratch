#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

#include "radix.h"

size_t CHUNK_SIZE  = 0;
size_t CHUNK_COUNT = 0;
size_t BUF_SIZE    = 0;
int MSB_MODE       = 0;

static void
print_data(const char* prefix, const uint8_t* data)
{
	const size_t COLS = 5;
	
	printf("%s:\n", prefix);
	for (size_t i = 0; i < CHUNK_COUNT; i++) {
		printf("    0x");
		for (size_t j = 0; j < CHUNK_SIZE; j++)
			printf("%02x", data[i*CHUNK_SIZE+j]);
		if ((i+1) % COLS == 0) {
			puts("");
		}
	}
	puts("");
}

static int
cmp_msb_chunk(const void *a, const void *b)
{
	uint8_t* n = (uint8_t*) a;
	uint8_t* m = (uint8_t*) b;

	for (size_t i = 0; i < CHUNK_SIZE; i++) {
		if (n[i] < m[i])
			return -1;
		else if (n[i] > m[i])
			return 1;
	}

	return 0;
}

static int
cmp_lsb_chunk(const void *a, const void *b)
{
	uint8_t* n = (uint8_t*) a;
	uint8_t* m = (uint8_t*) b;

	for (size_t i = 0; i < CHUNK_SIZE; i++) {
		size_t j = CHUNK_SIZE - i - 1;
		if (n[j] < m[j])
			return -1;
		else if (n[j] > m[j])
			return 1;
	}

	return 0;
}

static void
parse_args(int argc, char** argv)
{
	for (size_t i = 1; i < argc; i++) {
		switch(argv[i][1]) {
		case 's':
			++i;
			CHUNK_SIZE = strtol(argv[i], NULL, 10);
			break;

		case 'n':
			++i;
			CHUNK_COUNT = strtol(argv[i], NULL, 10);
			break;
			
		case 'm':
			MSB_MODE = 1;
			break;
		case 'l':
			MSB_MODE = 0;
			break;
		default:
			fprintf(stderr, "Bad argument: %s\n", argv[i]);
			exit(-1);
		}
	}
	BUF_SIZE = CHUNK_SIZE * CHUNK_COUNT;
}

int
main(int argc, char** argv)
{
	if (argc != 6) {
		fprintf(stderr, "Usage: %s -[ml] -s [CHUNK SIZE] -n [CHUNK COUNT]\n", argv[0]);
		exit(-1);
	}

	parse_args(argc, argv);
	
	uint8_t* radix_data = malloc(BUF_SIZE);
	uint8_t* qsort_data = malloc(BUF_SIZE);
	uint8_t* output;
	time_t qstart, qend, rstart, rend;

	puts("GENERATING DATA");
	srand(time(NULL));
	for (size_t i = 0; i < BUF_SIZE; i++) {
		radix_data[i] = rand() & 0xff;
		qsort_data[i] = radix_data[i];
	}

	puts("SORTING DATA WITH RADIX");
	rstart = clock();
	if (MSB_MODE)
		output = radix_msb(radix_data, CHUNK_SIZE, CHUNK_COUNT);
	else
		output = radix_lsb(radix_data, CHUNK_SIZE, CHUNK_COUNT);
	rend = clock();
	rend -= rstart;
	
	puts("SORTING DATA WITH QSORT FROM LIBC");
	qstart = clock();
	qsort(qsort_data, CHUNK_COUNT, CHUNK_SIZE, MSB_MODE ? cmp_msb_chunk : cmp_lsb_chunk);
	qend = clock();
	qend -= qstart;

	puts("COMPARING RESULTS FROM RADIX AND QSORT");
	for (size_t i = 0; i < BUF_SIZE; i++) {
		if (qsort_data[i] != output[i]) {
			print_data("RAW DATA", radix_data);
			print_data("QSORT RESULT", qsort_data);
			print_data("RADIX RESULT", output);
			fprintf(stderr, "FAILED\n");
			return 1;
		}
	}
	puts("SUCCESS");
	printf("QSORT / RADIX = %f\n", (double)qend / rend);
	return 0;
}
