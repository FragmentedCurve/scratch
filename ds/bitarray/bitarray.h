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

#ifndef _BITARRAY_H_
#define _BITARRAY_H_

#ifdef _BITARRAY64
#include <stdint.h>
#define __BITS_T uint64_t
#define __BITS_LEN 64
#endif

#ifdef _BITARRAY32
#include <stdint.h>
#define __BITS_T uint32_t
#define __BITS_LEN 32
#endif

#ifdef _BITARRAY16
#include <stdint.h>
#define __BITS_T uint16_t
#define __BITS_LEN 16
#endif

#ifdef _BITARRAY8
#include <stdint.h>
#define __BITS_T uint8_t
#define __BITS_LEN 8
#endif

typedef __BITS_T bitarray_t;

#define BITARRAY_LEN(n) ((((n) - 1) / __BITS_LEN) + 1)

inline static int
bitarray_get(bitarray_t* barr, size_t index)
{
	if (index < __BITS_LEN) {
		return (1 & (barr[0] >> index));
	}

	return (1 & (barr[index / __BITS_LEN] >> (index % __BITS_LEN)));
}

inline static void
bitarray_set(bitarray_t* barr, size_t index)
{
	if (index < __BITS_LEN) {
		barr[0] |= 1 << index;
	}

	barr[index / __BITS_LEN] |= 1 <<  (index % __BITS_LEN);
}

inline static void
bitarray_unset(bitarray_t* barr, size_t index)
{
	if (index < __BITS_LEN) {
		barr[0] &= ~(1 << index);
	}

	barr[index / __BITS_LEN] &= ~(1 <<  (index % __BITS_LEN));
}

#endif /* _BITARRAY_H_ */
