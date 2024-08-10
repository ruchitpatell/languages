#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <wchar.h>

int main(void)
{
    // Integer Types

    // int: 4 bytes, range: -2,147,483,648 to 2,147,483,647, format: %d
    int i = 10;

    // unsigned int: 4 bytes, range: 0 to 4,294,967,295, format: %u
    unsigned int ui = 10U;

    // short: 2 bytes, range: -32,768 to 32,767, format: %hd
    short s = 5;

    // unsigned short: 2 bytes, range: 0 to 65,535, format: %hu
    unsigned short us = 5U;

    // long: 4 or 8 bytes, range: platform-dependent, format: %ld
    long l = 1000L;

    // unsigned long: 4 or 8 bytes, range: platform-dependent, format: %lu
    unsigned long ul = 1000UL;

    // long long: 8 bytes, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807, format: %lld
    long long ll = 100000LL;

    // unsigned long long: 8 bytes, range: 0 to 18,446,744,073,709,551,615, format: %llu
    unsigned long long ull = 100000ULL;


    // Character Types

    // char: 1 byte, range: -128 to 127, format: %c or %d
    char c = 'A';

    // unsigned char: 1 byte, range: 0 to 255, format: %c or %u
    unsigned char uc = 'A';

    // wchar_t: 2 or 4 bytes, range: platform-dependent, format: %lc
    wchar_t wc = L'A';


    // Floating-Point Types

    // float: 4 bytes, range: 1.2E-38 to 3.4E+38, format: %.xf (for x decimal places)
    float f = 3.14f;

    // double: 8 bytes, range: 2.3E-308 to 1.7E+308, format: %.xf (for x decimal places)
    double d = 3.141592653589793;

    // long double: 10, 12, or 16 bytes, range: platform-dependent, format: %.xLf (for x decimal places)
    long double ld = 3.141592653589793238L;


    // Boolean Type

    // bool: 1 byte, range: 0 or 1, format: %d
    bool b = true;


    // Fixed-Width Integer Types

    // int8_t: 1 byte, range: -128 to 127, format: %d
    int8_t i8 = INT8_MAX;

    // uint8_t: 1 byte, range: 0 to 255, format: %u
    uint8_t u8 = UINT8_MAX;

    // int16_t: 2 bytes, range: -32,768 to 32,767, format: %d
    int16_t i16 = INT16_MAX;

    // uint16_t: 2 bytes, range: 0 to 65,535, format: %u
    uint16_t u16 = UINT16_MAX;

    // int32_t: 4 bytes, range: -2,147,483,648 to 2,147,483,647, format: %d
    int32_t i32 = INT32_MAX;

    // uint32_t: 4 bytes, range: 0 to 4,294,967,295, format: %u
    uint32_t u32 = UINT32_MAX;

    // int64_t: 8 bytes, range: -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807, format: %lld
    int64_t i64 = INT64_MAX;

    // uint64_t: 8 bytes, range: 0 to 18,446,744,073,709,551,615, format: %llu
    uint64_t u64 = UINT64_MAX;


    // Special Types

    // size_t: platform-dependent, unsigned integer type, format: %zu
    size_t st = sizeof(int);

    // ptrdiff_t: platform-dependent, signed integer type, format: %td
    ptrdiff_t pt = &i - &i;

    // intptr_t: platform-dependent, signed integer type, format: %td
    intptr_t iptr = (intptr_t)&i;

    // uintptr_t: platform-dependent, unsigned integer type, format: %zu
    uintptr_t uptr = (uintptr_t)&i;


    // Pointers

    // Pointer to int
    int *p = &i;

    // Pointer to float
    float *pf = &f;

    printf("int: %d\n", i);
    printf("unsigned int: %u\n", ui);
    printf("short: %hd\n", s);
    printf("unsigned short: %hu\n", us);
    printf("long: %ld\n", l);
    printf("unsigned long: %lu\n", ul);
    printf("long long: %lld\n", ll);
    printf("unsigned long long: %llu\n", ull);
    printf("char as character: %c\n", c);
    printf("char as integer: %d\n", c);
    printf("unsigned char as character: %c\n", uc);
    printf("unsigned char as integer: %u\n", uc);
    printf("wchar_t: %lc\n", wc);
    printf("float: %.2f\n", f);
    printf("double: %.2f\n", d);
    printf("long double: %.2Lf\n", ld);
    printf("bool: %d\n", b);
    printf("int8_t: %d\n", i8);
    printf("uint8_t: %u\n", u8);
    printf("int16_t: %d\n", i16);
    printf("uint16_t: %u\n", u16);
    printf("int32_t: %d\n", i32);
    printf("uint32_t: %u\n", u32);
    printf("int64_t: %lld\n", i64);
    printf("uint64_t: %llu\n", u64);
    printf("size_t: %zu\n", st);
    printf("ptrdiff_t: %td\n", pt);
    printf("intptr_t: %td\n", iptr);
    printf("uintptr_t: %zu\n", uptr);
    printf("Pointer to int: %p\n", (void *)p);
    printf("Pointer to float: %p\n", (void *)pf);

    return 0;
}
