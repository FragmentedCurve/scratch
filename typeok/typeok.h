#ifndef _TYPEOK_H_
#define _TYPEOK_H_

#include <stdint.h>

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

// Helpers
#define is_ok(ptr) (((char*)(ptr))[0] != 0)
#define init_ok(v) {0, v}

#endif // _TYPEOK_H_
