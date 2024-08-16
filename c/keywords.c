#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>
#include <complex.h>
#include <stdatomic.h>

#include "keywords.h"

void aauto(void) {
    auto int a = 10;  // 'auto' is optional since it's the default
    printf("auto variable a = %d\n", a);
}

void break_continue(void) {
    for (int i = 0; i < 10; i++) {
        if (i == 5)
            break;
        if (i % 2 == 0)
            continue;
        printf("%d ", i);
    }
    printf("\n");
}

void const_volatile(void) {
    const int a = 10;  // 'a' is read-only
    volatile int b = 20;  // 'b' can be modified by something outside the code's control
    printf("const a = %d, volatile b = %d\n", a, b);
}

void eenum(void) {
    enum week {sun, mon, tue, wed, thu, fri, sat};
    enum week today = wed;
    printf("today is %d\n", today);
}

int global_var = 0;
void eextern(void) {
    extern int global_var;
    global_var = 42;  // modify the external global variable
    printf("global variable value = %d\n", global_var);
}

void ggoto(void) {
    int x = 10;
    if (x == 10)
        goto label;
    printf("this won't be printed\n");
label:
    printf("jumped to label\n");
}

void if_else(void) {
    int num = 5;
    if (num > 0)
        printf("positive number\n");
    else
        printf("non-positive number\n");
}

void for_loop(void) {
    for (int i = 0; i < 5; i++) {
        printf("i = %d\n", i);
    }
}

void sswitch(void) {
    int num = 2;
    switch (num) {
        case 1:
            printf("one\n");
            break;
        case 2:
            printf("two\n");
            break;
        default:
            printf("other number\n");
    }
}

void struct_union(void) {
    struct point {
        int x;
        int y;
    };

    union data {
        int i;
        float f;
        char str[20];
    };

    struct point p = {10, 20};
    union data d;
    d.i = 10;

    printf("struct point: (%d, %d)\n", p.x, p.y);
    printf("union data int: %d\n", d.i);
}

void ttypedef(void) {
    typedef unsigned long ulong;
    ulong num = 123456789;
    printf("typedef unsigned long as ulong: %lu\n", num);
}

void while_loop(void) {
    int i = 0;
    while (i < 5) {
        printf("i = %d\n", i);
        i++;
    }
}

void ssizeof(void) {
    int a;
    double b;
    printf("size of int: %zu bytes\n", sizeof(a));
    printf("size of double: %zu bytes\n", sizeof(b));
}

void sstatic(void) {
    static int count = 0;
    count++;
    printf("static count = %d\n", count);
}

// inline int square(int x) {
//     return x * x;
// }

// void iinline(void) {
//     int num = 5;
//     printf("square of %d is %d\n", num, square(num));
// }

void rrestrict(void) {
    int a[5] = {1, 2, 3, 4, 5};
    int *restrict p = a;    // a only accessed through p, no other pointer than p will be used to access a
    for (int i = 0; i < 5; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

// // thread at a time
// void atomic(void) {
//     atomic_int atomicvar = atomic_var_init(0);
//     atomic_store(&atomicvar, 10);
//     printf("atomic variable = %d\n", atomic_load(&atomicvar));
// }

void signed_unsigned(void) {
    signed int a = -10;
    unsigned int b = 10;
    printf("signed a = %d, unsigned b = %u\n", a, b);
}

void rregister(void) {
    register int a = 10;    // store in register for fast access
    printf("register variable a = %d\n", a);
}

void vvoid(void) {
    printf("this function uses 'void' as the return type\n");
}

void rreturn(void) {
    printf("this function returns an int\n");
    return;
}

int main(void) {
    aauto();
    break_continue();
    const_volatile();
    eenum();
    eextern();
    ggoto();
    if_else();
    for_loop();
    sswitch();
    struct_union();
    ttypedef();
    while_loop();
    ssizeof();
    sstatic();
    // iinline();
    rrestrict();
    // atomic();
    signed_unsigned();
    rregister();
    vvoid();
    rreturn();

    return 0;
}
