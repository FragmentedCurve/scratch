/*
 * Copyright (c) 2024 Paco Pascal <me@pacopascal.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _TYPEOK_SAFE_MATH_H_
#define _TYPEOK_SAFE_MATH_H_

#include <typeok.h>

int_ok  typeok_safe_addi(int a, int b);
int_ok  typeok_safe_subi(int a, int b);
int_ok  typeok_safe_muli(int a, int b);
int_ok  typeok_safe_divi(int a, int b);

uint_ok typeok_safe_addu(uint a, uint b);
uint_ok typeok_safe_subu(uint a, uint b);
uint_ok typeok_safe_mulu(uint a, uint b);
uint_ok typeok_safe_divu(uint a, uint b);

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

int_ok
typeok_safe_subi(int a, int b)
{
	return (int_ok){
		   (a <= 0 && b <= 0)
		|| (a >= 0 && b >= 0)
		|| (a > 0 && INT_MIN + a <= b)  // overflow
		|| (a < 0 && INT_MAX + a >= b), // underflow
		a - b
	};
}

int_ok
typeok_safe_muli(int a, int b)
{
	return (int_ok){
		   (a >= 0  && a <= 1)
		|| (b >= 0  && b <= 1)
		|| (
			   ((a == -1 && b > INT_MIN && b < INT_MAX) || (b == -1 && a > INT_MIN && a < INT_MAX))
			&& (((a * b) / b == a) && ((a * b) / a == b))),
		a * b
	};
}

int_ok
typeok_safe_divi(int a, int b)
{
	return (int_ok){
		b != 0,
		a / (b + (b == 0))
	};
}

uint_ok
typeok_safe_addu(uint a, uint b)
{
	return (uint_ok){
		a == 0 || b == 0 || (UINT_MAX - a >= b),  // overflow
		a + b
	};
}

uint_ok
typeok_safe_subu(uint a, uint b)
{
	return (uint_ok){a >= b, a - b};
}

uint_ok
typeok_safe_mulu(uint a, uint b)
{
	return (uint_ok){
		a == 0 || b == 0 || a == 1 || b == 1 || (a * b) / b == a,
		a * b
	};
}

uint_ok
typeok_safe_divu(uint a, uint b)
{
	return (uint_ok){
		b != 0,
		a / (b + (b == 0))
	};
}

#endif // TYPEOK_SAFE_MATH_IMPLEMENTATION
#endif // _TYPEOK_SAFE_MATH_H_
