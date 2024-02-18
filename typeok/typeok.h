/*
	TODO: Write a description of it's use.

	Examples

		int_ok safe_add(int a, int b) {
			int_ok n = {1, a + b};

			if (a > 0 && b > 0 && INT_MAX - a >= b) {
				n.ok = 0;
			}

			if (a < 0 && b < 0 && INT_MIN - a >= b) {
				n.ok = 0;
			}

			return n;
		}

		// ....

		if (x = safe_add(INT_MAX, 1), !x.ok) {
			printf("Integer overflow!");
		}
 */

#ifndef _TYPEOK_H_
#define _TYPEOK_H_

/* Warning: Compiler specific macros are used here */
typedef __INT8_TYPE__         i8;
typedef __UINT8_TYPE__        u8;
typedef __INT16_TYPE__       i16;
typedef __UINT16_TYPE__      u16;
typedef __INT32_TYPE__       i32;
typedef __UINT32_TYPE__      u32;
typedef __INT64_TYPE__       i64;
typedef __UINT64_TYPE__      u64;
typedef float                f32;
typedef double               f64;
typedef char                byte;
typedef unsigned char      ubyte;
typedef unsigned long long  size;

#define TYPEDEF_OK(T) \
typedef struct {      \
	byte ok;      \
	T value;      \
} T##_ok;

/* Vanilla C types */
TYPEDEF_OK(char);
TYPEDEF_OK(short);
TYPEDEF_OK(int);
TYPEDEF_OK(long);
TYPEDEF_OK(float);
TYPEDEF_OK(double);

/* Non-vanilla types */
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

/* Helpers */
#define is_ok(ptr) (((char*)(ptr))[0] != 0)
#define init_ok(v) {0, v}

#endif /* _TYPEOK_H_ */
