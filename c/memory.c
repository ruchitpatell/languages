#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/* 
c memory model
 
three main regions:
    1. text (code) segment: where the executable code is stored
    2. data segment: 
        initialized data segment: contains global and static variables initialized by the user
        uninitialized data segment (bss): contains global and static variables that are not initialized by the user
    3. heap: used for dynamic memory allocation
       stack: stores local variables, function parameters, and return addresses
*/

/* 
memory allocation on the stack
 
stack memory is automatically managed it grows downwards, meaning that newer allocations 
are at lower memory addresses
*/
void stack_memory_example(void) {
    int a = 10;  // local variable, stored on the stack
    int b = 20;  // local variable, stored on the stack
    printf("stack memory example:\n");
    printf("address of a: %p\n", (void*)&a);
    printf("address of b: %p\n\n", (void*)&b);
}

/* 
memory allocation on the heap
 
heap memory is dynamically allocated and managed by the user and grows upwards
*/
void heap_memory_example(void) {
    int *p = (int *) malloc(sizeof(int));
    if (p != NULL) {
        *p = 30;
        printf("heap memory example:\n");
        printf("address of dynamically allocated integer: %p\n", (void*)p);
        printf("value at allocated memory: %d\n\n",p);
        free(p);  // always free dynamically allocated memory
    } else {
        printf("memory allocation failed\n");
    }
}

/* 
memory alignment
 
memory alignment ensures that variables are stored in memory in a way that improves 
performance on the underlying hardware the alignment requirements are typically 
determined by the cpu architecture
*/
struct alignedstruct {
    char c;       // 1 byte
    int i;        // 4 bytes (but may be aligned to 4 bytes)
    double d;     // 8 bytes (but may be aligned to 8 bytes)
};

void memory_alignment_example(void) {
    struct alignedstruct s;
    printf("memory alignment example:\n");
    printf("address of struct s: %p\n", (void*)&s);
    printf("address of sc: %p\n", (void*)&s.c);
    printf("address of si: %p\n", (void*)&s.i);
    printf("address of sd: %p\n", (void*)&s.d);
    printf("size of struct alignedstruct: %zu bytes\n\n", sizeof(struct alignedstruct));
}

/* 
memory padding
 
memory padding is added to ensure proper alignment this can lead to "wasted" memory but is 
necessary for performance reasons
*/
struct paddedstruct {
    char c1;      // 1 byte, 3 bytes padding (if required by architecture)
    int i;        // 4 bytes
    char c2;      // 1 byte, 7 bytes padding (if required by architecture)
    double d;     // 8 bytes
};

void memory_padding_example(void) {
    struct paddedstruct ps;
    printf("memory padding example:\n");
    printf("size of struct paddedstruct: %zu bytes\n\n", sizeof(struct paddedstruct));
}

/* 
dynamic memory management functions
 
malloc: allocates memory of a specified size and returns a pointer to it
calloc: allocates memory for an array and initializes it to zero
realloc: resizes previously allocated memory
free: frees dynamically allocated memory
*/
void dynamic_memory_management(void) {
    int *arr = (int *) malloc(5 * sizeof(int));  // allocate memory for an array of 5 integers
    if (arr == NULL) {
        printf("memory allocation failed\n");
        return;
    }

    // initialize and print the array
    for (int i = 0; i < 5; i++) {
        arr[i] = i + 1;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // resize the array using realloc
    int *new_arr = (int *)realloc(arr, 10 * sizeof(int));
    if (new_arr == NULL) {
        printf("memory reallocation failed\n");
        free(arr);  // free the original array if realloc fails
        return;
    }

    // initialize the new elements and print the new array
    for (int i = 5; i < 10; i++) {
        new_arr[i] = i + 1;
        printf("new_arr[%d] = %d\n", i, new_arr[i]);
    }

    free(new_arr);  // free the resized array
}

/* 
garbage collection in c
 
c does not have built-in garbage collection
the user is responsible for manually managing memory using `malloc`, `free`, etc
*/


int main(void) {
    stack_memory_example();
    heap_memory_example();
    memory_alignment_example();
    memory_padding_example();
    dynamic_memory_management();

    return 0;
}
