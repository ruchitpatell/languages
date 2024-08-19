#include <stdio.h>
#include <stdlib.h>

#include "undefined.h"

void uninitialized_variable(void) {
    int x;
    printf("uninitialized variable:\n");
    printf("value of x: %d\n\n", x);  // ub: x is not initialized
    return;
}

void division_by_zero(void) {
    int a = 10;
    int b = 0;
    printf("division by zero:\n");
    printf("%d / %d = %d\n", a, b, a / b);  // ub: division by zero
    return;
}

void signed_integer_overflow(void) {
    int x = INT32_MAX;
    printf("signed integer overflow:\n");
    printf("before overflow: x = %d\n", x);
    x = x + 1;  // ub: signed integer overflow
    printf("after overflow: x = %d (undefined behavior)\n\n", x);
    return;
}

void dereferencing_null_pointer(void) {
    int *p = NULL;
    printf("dereferencing null pointer:\n");
    // printf("value at p: %d\n", *p);  // ub: dereferencing null pointer
    return;
}

void out_of_bounds_array_access(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("out-of-bounds array access:\n");
    printf("arr[0] = %d\n", arr[0]);
    printf("arr[5] (out-of-bounds) = %d (undefined behavior)\n\n", arr[5]);  // ub: accessing out-of-bounds
    return;
}

void modifying_string_literal(void) {
    char *str = "hello, world!";
    printf("modifying string literal:\n");
    printf("original string: %s\n", str);
    // str[0] = 'h';  // ub: modifying a string literal
    // printf("modified string: %s\n", str);
    return;
}

void use_after_free(void) {
    int *p = (int *)malloc(sizeof(int));
    *p = 10;
    printf("use after free:\n");
    printf("before free: *p = %d\n", *p);
    free(p);
    printf("after free: *p = %d\n", *p);  // ub: using memory after it has been free
    return;
}

void strict_aliasing_violation(void) {
    int x = 42;
    float *p = (float *)&x;  // type-punning in violation of strict aliasing
    printf("strict aliasing violation:\n");
    printf("value of x (int): %d\n", x);
    printf("interpreted as float: %f (undefined behavior)\n\n", *p);
    return;
}

int missing_return(void) {
    printf("missing return:\n");
    // ub: missing return statement for a non-void function
}

void invalid_bit_shift(void) {
    int x = 1;
    printf("invalid bit shift:\n");
    printf("shifting left by -1: %d\n", x << -1);  // ub: negative shift
    printf("shifting left by 32: %d\n", x << 32);  // ub: too large shift
    return;
}

void modifying_const_data(void) {
    const int x = 10;
    int *p = (int *)&x;  // cast away constness
    printf("modifying const data:\n");
    printf("original x = %d\n", x);
    *p = 20;  // ub: modifying const data
    printf("modified x = %d (undefined behavior)\n\n", x);
    return;
}

void passing_pointer_to_realloc(void) {
    int *arr = (int *)malloc(3 * sizeof(int));
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    printf("passing pointers to realloc:\n");
    printf("original array: %d, %d, %d\n", arr[0], arr[1], arr[2]);

    int *new_arr = (int *)realloc(arr, 5 * sizeof(int));
    if (new_arr != NULL) {
        new_arr[3] = 4;
        new_arr[4] = 5;
        printf("resized array: %d, %d, %d, %d, %d\n", new_arr[0], new_arr[1], new_arr[2], new_arr[3], new_arr[4]);
    } else {
        printf("realloc failed.\n");
    }

    printf("old pointer value (arr[0]): %d\n", arr[0]);  // ub: using arr after realloc

    free(new_arr);
    return;
}

void passing_pointer_to_free(void) {
    int *arr = (int *)malloc(3 * sizeof(int));
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    printf("passing pointers to free:\n");
    printf("array before free: %d, %d, %d\n", arr[0], arr[1], arr[2]);

    free(arr);  // correctly freeing the memory

    // free(arr);  // ub: double free

    int *p = (int *)0x12345678;
    // free(p);  // ub: freeing an invalid pointer
    return;
}

void memory_function_ub(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    printf("memory functions and pointers:\n");
    printf("original array: %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

    // incorrect use of memset, overwriting beyond the array bounds
    // memset(arr, 0, 10 * sizeof(int));  // ub: overwriting out-of-bounds memory

    // incorrect use of memcpy, overlapping memory
    // memcpy(arr + 1, arr, 4 * sizeof(int));  // ub: overlapping memory regions

    // correct use of memmove, which handles overlapping memory
    memmove(arr + 1, arr, 4 * sizeof(int));
    printf("after memmove (correct): %d, %d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    return;
}

int main(void) {
    uninitialized_variable();
    division_by_zero();
    signed_integer_overflow();
    dereferencing_null_pointer();
    out_of_bounds_array_access();
    modifying_string_literal();
    use_after_free();
    strict_aliasing_violation();
    missing_return();
    invalid_bit_shift();
    modifying_const_data();
    passing_pointer_to_realloc();
    passing_pointer_to_free();
    memory_function_ub();
    return 0;
}
