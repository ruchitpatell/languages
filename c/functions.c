#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <errno.h>

#include "functions.h"

// // GCC-specific (does not return)
// __attribute__((noreturn)) void fatal_error(const char *message) {
//     printf("Fatal error: %s\n", message);
//     exit(1);
// }

// hints dont care if unused
// static restricts the scope to current c file
__attribute__((unused)) static void unused_function(void) {
    return;
}

__attribute__((constructor)) static void init_function(void) {
    printf("initialization before main.\n");
}


__attribute__((destructor)) static void destructor_function(void) {
    printf("cleanup after main.\n");
}

void original_function(void) {
    printf("original function.\n");
}

int add(int a, int b) {
    return a + b;
}

// alias
// void also_add() __attribute__((alias("add")));

// // inline
// inline int square(int x) {
//     return x * x;
// }

// const paramete
void printMessage(const char* message) {
    printf("%s\n", message);
}

// pass by reference
void increment(int* a) {
    if(!a) { return; }
    (*a)++;
}

// variadic function example
void printNumbers(int count, ...) {
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int num = va_arg(args, int);
        printf("number: %d\n", num);
    }
    va_end(args);
}

// Function pointers
void functionPointerExample(void) {
    int (*operation)(int, int) = add;
    int result = operation(5, 3);
    printf("result using function pointer: %d\n", result);
}

// callback
void callbackFunction(int n) {
    printf("callback function called with value: %d\n", n);
}

void processCallback(void (*callback)(int)) {
    for (int i = 0; i < 3; i++) {
        callback(i);
    }
}

// return a pointer
int* createArray(int size) {
    return (int*)malloc(size * sizeof(int));
}

// dynamic function dispatching
void dynamicFunctionDispatchingExample(void) {
    // returns an int, takes in int, int
    typedef int (*operation_t)(int, int);
    operation_t operations[1] = {add};
    printf("add: %d\n", operations[0](5, 2));
}

// struct w/ function pointers
typedef struct {
    int (*operation)(int, int);
} Calculator;

void structureFunctionPointerExample(void) {
    Calculator calc;
    calc.operation = add;
    printf("\ncalc result: %d\n", calc.operation(3, 4));
}

// recursion
void recursionExample(int n) {
    if (n > 0) {
        printf("%d ", n);
        recursionExample(n - 1);
    }
}

// cleanup function registered with atexit()
void cleanup_function(void) {
    printf("\nCleanup function executed.\n");
}

int main(void) {
    atexit(cleanup_function);

    printf("Add: %d\n", add(3, 4));

    // inline
    // printf("Square: %d\n", square(5));

    // pass by reference
    int x = 5;
    increment(&x);
    printf("Incremented value: %d\n", x);

    // variadic function example
    printNumbers(4, 10, 20, 30);

    functionPointerExample();

    processCallback(callbackFunction);

    dynamicFunctionDispatchingExample();

    int *array = createArray(5);
    if (array) {
        free(array);
    }

    printf("recursion: \n");
    recursionExample(5);
    printf("\n");

    structureFunctionPointerExample();

    return EXIT_SUCCESS;
}
