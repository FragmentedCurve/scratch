#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "typeok.h"
#include "typeok_safe_math.h"

int
main(int argc, char** argv)
{
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
}
