#ifndef _TYPEOK_SAFE_MATH_H_
#define _TYPEOK_SAFE_MATH_H_

int_ok   typeok_safe_addi(int a, int b);
short_ok typeok_safe_adds(short a, short b);
long_ok  typeok_safe_addl(long a, long b);

#ifdef TYPEOK_SAFE_MATH_IMPLEMENTATION
int_ok
typeok_safe_addi(int a, int b)
{
	return (int_ok){
		   (a <= 0 && b >= 0)
		|| (a >= 0 && b <= 0)
		|| (a > 0 && INT_MAX - a >= b)  // overflow
		|| (a < 0 && INT_MIN - a <= b), // underflow
		a + b
	};
}

short_ok
typeok_safe_adds(short a, short b)
{
	return (short_ok){
		   (a <= 0 && b >= 0)
		|| (a >= 0 && b <= 0)
		|| (a > 0 && SHRT_MAX - a >= b)  // overflow
		|| (a < 0 && SHRT_MIN - a <= b), // underflow
		a + b
	};
}

long_ok
typeok_safe_addl(long a, long b)
{
	return (long_ok){
		   (a <= 0 && b >= 0)
	        || (a >= 0 && b <= 0)
		|| (a > 0 && LONG_MAX - a >= b)  // overflow
		|| (a < 0 && LONG_MIN - a <= b), // underflow
		a + b
	};
}

/* TODO: Implement subtraction, multiplication, and division. */

int_ok
typeok_safe_subi(int a, int b)
{
	return (int_ok){
		   (a <= 0 && b <= 0)
	        || (a >= 0 && b >= 0)
		|| (a > 0 && INT_MAX + a >= b)  // overflow
		|| (a < 0 && INT_MIN + a <= b), // underflow
		a + b
	};
}

short_ok
typeok_safe_subs(short a, short b)
{
	// TODO
}

long_ok
typeok_safe_subl(long a, long b)
{
	// TODO
}
#endif // TYPEOK_SAFE_MATH_IMPLEMENTATION

#endif // _TYPEOK_SAFE_MATH_H_
