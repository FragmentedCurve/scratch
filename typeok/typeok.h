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

#ifndef _TYPEOK_H_
#define _TYPEOK_H_

#include <stdint.h>

#define I8_MIN  INT8_MIN
#define I16_MIN INT16_MIN
#define I32_MIN INT32_MIN
#define I64_MIN INT64_MIN
#define I8_MAX  INT8_MAX
#define I16_MAX INT16_MAX
#define I32_MAX INT32_MAX
#define I64_MAX INT64_MAX
#define U8_MAX  UINT8_MAX
#define U16_MAX UINT16_MAX
#define U32_MAX UINT32_MAX
#define U64_MAX UINT64_MAX

typedef int8_t                i8;
typedef uint8_t               u8;
typedef int16_t              i16;
typedef uint16_t             u16;
typedef int32_t              i32;
typedef uint32_t             u32;
typedef int64_t              i64;
typedef uint64_t             u64;
typedef float                f32;
typedef double               f64;
typedef char                byte;
typedef unsigned char      ubyte;
typedef unsigned long long  size;
typedef unsigned int        uint;

#define TYPEDEF_OK(T) \
typedef struct {      \
	byte ok;      \
	T value;      \
} T##_ok

// Vanilla C types
TYPEDEF_OK(char);
TYPEDEF_OK(short);
TYPEDEF_OK(int);
TYPEDEF_OK(long);
TYPEDEF_OK(float);
TYPEDEF_OK(double);
TYPEDEF_OK(uint);

// Non-vanilla types
TYPEDEF_OK(i8);
TYPEDEF_OK(u8);
TYPEDEF_OK(i16);
TYPEDEF_OK(u16);
TYPEDEF_OK(i32);
TYPEDEF_OK(u32);
TYPEDEF_OK(i64);
TYPEDEF_OK(u64);
TYPEDEF_OK(f32);
TYPEDEF_OK(f64);
TYPEDEF_OK(byte);
TYPEDEF_OK(ubyte);
TYPEDEF_OK(size);

// Pointer type defs
typedef char*   char_ptr;
typedef short*  short_ptr;
typedef int*    int_ptr;
typedef long*   long_ptr;
typedef float*  float_ptr;
typedef double* double_ptr;

typedef int8_t*                i8_ptr;
typedef uint8_t*               u8_ptr;
typedef int16_t*              i16_ptr;
typedef uint16_t*             u16_ptr;
typedef int32_t*              i32_ptr;
typedef uint32_t*             u32_ptr;
typedef int64_t*              i64_ptr;
typedef uint64_t*             u64_ptr;
typedef float*                f32_ptr;
typedef double*               f64_ptr;
typedef char*                byte_ptr;
typedef unsigned char*      ubyte_ptr;
typedef unsigned long long*  size_ptr;

// Vanilla C pointer types
TYPEDEF_OK(char_ptr);
TYPEDEF_OK(short_ptr);
TYPEDEF_OK(int_ptr);
TYPEDEF_OK(long_ptr);
TYPEDEF_OK(float_ptr);
TYPEDEF_OK(double_ptr);

// Non-vanilla pointer types
TYPEDEF_OK(i8_ptr);
TYPEDEF_OK(u8_ptr);
TYPEDEF_OK(i16_ptr);
TYPEDEF_OK(u16_ptr);
TYPEDEF_OK(i32_ptr);
TYPEDEF_OK(u32_ptr);
TYPEDEF_OK(i64_ptr);
TYPEDEF_OK(u64_ptr);
TYPEDEF_OK(f32_ptr);
TYPEDEF_OK(f64_ptr);
TYPEDEF_OK(byte_ptr);
TYPEDEF_OK(ubyte_ptr);
TYPEDEF_OK(size_ptr);


typedef char_ptr error;
#define TYPEDEF_ERR(T) \
typedef struct {       \
	error err;     \
	T     value;   \
} T##_err;


#ifdef TYPEOK_EXTRA

// Expression enhancers (Inspired by Handmade Hero)
#define internal static
#define global   static
#define persist  static
#define _        (void)

// Byte Units
#define Bytes(n)     (n##L)
#define KiloBytes(n) (Bytes(n)*1024)
#define MegaBytes(n) (KiloBytes(n)*1024)
#define GigaBytes(n) (MegaBytes(n)*1024)

#endif // TYPEOK_EXTRA

#endif // _TYPEOK_H_
