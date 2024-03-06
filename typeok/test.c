#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "typeok.h"
#define TYPEOK_SAFE_MATH_IMPLEMENTATION
#include "typeok_safe_math.h"

void static
test_addi()
{
	int_ok n;

	printf("testing typeok_safe_addi\n");

	n = typeok_safe_addi(INT_MAX, 1);
	assert(!n.ok);

	n = typeok_safe_addi(INT_MAX - 1, 1);
	assert(n.ok);

	n = typeok_safe_addi(1, INT_MAX);
	assert(!n.ok);

	n = typeok_safe_addi(1, INT_MAX - 1);
	assert(n.ok);

	n = typeok_safe_addi(INT_MIN, 1);
	assert(n.ok);

	n = typeok_safe_addi(INT_MIN, -1);
	assert(!n.ok);

	n = typeok_safe_addi(INT_MIN, 0);
	assert(n.ok);

	n = typeok_safe_addi(0, INT_MIN);
	assert(n.ok);

	printf("passed.\n");
}

void static
test_subi()
{
	int_ok n;

	printf("testing typeok_safe_subi\n");

	n = typeok_safe_subi(INT_MAX, 1);
	assert(n.ok);

	n = typeok_safe_subi(INT_MAX, -1);
	assert(!n.ok);

	n = typeok_safe_subi(INT_MIN, 1);
	printf("%d\n", n.value);
	assert(!n.ok);

	n = typeok_safe_subi(INT_MIN, -1);
	assert(n.ok);


	n = typeok_safe_subi(1, INT_MAX);
	assert(n.ok);

	n = typeok_safe_subi(-1, INT_MAX);
	assert(!n.ok);

	n = typeok_safe_subi(1, INT_MIN);
	assert(!n.ok);

	n = typeok_safe_subi(-1, INT_MIN);
	assert(n.ok);


	n = typeok_safe_subi(INT_MIN, 0);
	assert(n.ok);

	n = typeok_safe_subi(0, INT_MIN);
	assert(n.ok);

	printf("passed.\n");
}

int
main(int argc, char** argv)
{
	test_addi();
	test_subi();
	/*
	int_ok n;

	printf("INT_MAX %d\n", INT_MAX);
	printf("INT_MIN %d\n\n", INT_MIN);

	n = typeok_safe_addi(INT_MAX, 1);
	assert(!n.ok);

	n = typeok_safe_addi(INT_MAX - 1, 1);
	assert(n.ok);

	n = typeok_safe_addi(1, INT_MAX);
	assert(!n.ok);

	n = typeok_safe_addi(1, INT_MAX - 1);
	assert(n.ok);

	n = typeok_safe_addi(INT_MIN, 1);
	assert(n.ok);

	n = typeok_safe_addi(INT_MIN, -1);
	assert(!n.ok);

	n = typeok_safe_addi(INT_MIN, 0);
	assert(n.ok);

	n = typeok_safe_addi(0, INT_MIN);
	assert(n.ok);

	printf("passed.\n");

	return 0;
	*/
}
