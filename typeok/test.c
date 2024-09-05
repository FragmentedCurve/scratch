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
	assert(n.ok);

	n = typeok_safe_subi(INT_MIN, 1);
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

void static
test_muli()
{
	int_ok n;

	printf("testing typeok_safe_muli\n");

	n = typeok_safe_muli(INT_MAX, 1);
	assert(n.ok);

	n = typeok_safe_muli(1, INT_MAX);
	assert(n.ok);

	n = typeok_safe_muli(INT_MIN, 1);
	assert(n.ok);

	n = typeok_safe_muli(1, INT_MIN);
	assert(n.ok);

	n = typeok_safe_muli(-1, INT_MAX);
	assert(!n.ok);

	n = typeok_safe_muli(-1, INT_MIN);
	assert(!n.ok);

	n = typeok_safe_muli(-1, INT_MIN + 1);
	assert(n.ok);

	n = typeok_safe_muli(2, INT_MIN);
	assert(!n.ok);

	n = typeok_safe_muli(-2, INT_MIN);
	assert(!n.ok);

	n = typeok_safe_muli(INT_MIN, INT_MIN);
	assert(!n.ok);

	n = typeok_safe_muli(INT_MAX, INT_MAX);
	assert(!n.ok);

	printf("passed.\n");
}

void static
test_divi()
{
	int_ok n;

	printf("testing typeok_safe_divi\n");

	n = typeok_safe_divi(0, 0);
	assert(!n.ok);

	n = typeok_safe_divi(1, 0);
	assert(!n.ok);

	n = typeok_safe_divi(1, 2);
	assert(n.ok);

	n = typeok_safe_divi(INT_MAX, INT_MIN);
	assert(n.ok);

	n = typeok_safe_divi(INT_MAX, INT_MAX);
	assert(n.ok);

	printf("passed.\n");
}

void static
test_addu()
{
	uint_ok n;

	printf("testing typeok_safe_addu\n");

	n = typeok_safe_addu(UINT_MAX, 1);
	assert(!n.ok);

	n = typeok_safe_addu(UINT_MAX - 1, 1);
	assert(n.ok);

	n = typeok_safe_addu(1, UINT_MAX);
	assert(!n.ok);

	n = typeok_safe_addu(1, UINT_MAX - 1);
	assert(n.ok);

	printf("passed.\n");
}


void static
test_subu()
{
	uint_ok n;

	printf("testing typeok_safe_subu\n");

	n = typeok_safe_subu(UINT_MAX, 1);
	assert(n.ok);

	n = typeok_safe_subu(0, 1);
	assert(!n.ok);

	n = typeok_safe_subu(1, UINT_MAX);
	assert(!n.ok);

	n = typeok_safe_subu(UINT_MAX, UINT_MAX);
	assert(n.ok);

	n = typeok_safe_subu(1, 0);
	assert(n.ok);

	n = typeok_safe_subu(0, 0);
	assert(n.ok);

	printf("passed.\n");
}

void static
test_mulu()
{
	uint_ok n;

	printf("testing typeok_safe_mulu\n");

	n = typeok_safe_mulu(UINT_MAX, 1);
	assert(n.ok);

	n = typeok_safe_mulu(1, UINT_MAX);
	assert(n.ok);

	n = typeok_safe_mulu(0, 1);
	assert(n.ok);

	n = typeok_safe_mulu(1, 0);
	assert(n.ok);

	n = typeok_safe_mulu(0, 0);
	assert(n.ok);

	n = typeok_safe_mulu(UINT_MAX, UINT_MAX);
	assert(!n.ok);

	n = typeok_safe_mulu(5, UINT_MAX / 3);
	assert(!n.ok);

	printf("passed.\n");
}

int
main(int argc, char** argv)
{
	test_addi();
	test_subi();
	test_divi();
	test_muli();
	test_addu();
	test_subu();
	test_mulu();
}
