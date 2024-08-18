#include <stdio.h>
#include <stdlib.h>

#include "pointers.h"

void pointer_basics(void) {
    int x = 10;
    int *p = &x;  // pointer p stores the address of x

    printf("pointer basics:\n");
    printf("value of x: %d\n", x);
    printf("address of x: %p\n", (void*)&x);
    printf("value of p (address of x): %p\n", (void*)p);
    printf("value at the address stored in p (dereferencing p): %d\n\n", *p);
}

void pointer_arithmetic(void) {
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;  // p points to the first element of arr

    printf("pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(p + %d) = %d, address: %p\n", i, arr[i], i, *(p + i), (void*)(p + i));
    }
    printf("\n");
}

void null_pointers(void) {
    int *p = NULL;

    printf("null pointers:\n");
    if (p == NULL) {
        printf("pointer p is null\n\n");
    }
}

void pointer_to_pointer(void) {
    int x = 20;
    int *p = &x;
    int **pp = &p;  // pp is a pointer to p

    printf("pointer to pointer:\n");
    printf("value of x: %d\n", x);
    printf("address of p (pp): %p\n", (void*)pp);
    printf("value at address stored in pp (*pp): %p\n", (void*)*pp);
    printf("value at the address stored in *pp (**pp): %d\n\n", **pp);
}

void dynamic_memory_allocation(void) {
    int *p = (int*)malloc(sizeof(int));

    if (p) {
        *p = 50;
        printf("dynamic memory allocation:\n");
        printf("value stored in allocated memory: %d\n", *p);
        printf("address of allocated memory: %p\n\n", (void*)p);
        free(p);
    } else {
        printf("memory allocation failed!\n\n");
    }
}

void array_pointers(void) {
    int arr[3] = {10, 20, 30};
    int *p = arr;
    int *arr_of_pointers[3];  // array of pointers

    for (int i = 0; i < 3; i++) {
        arr_of_pointers[i] = &arr[i];
    }

    printf("array of pointers:\n");
    for (int i = 0; i < 3; i++) {
        printf("arr_of_pointers[%d] points to %d, address: %p\n", i, *arr_of_pointers[i], (void*)arr_of_pointers[i]);
    }
    printf("\n");

    printf("pointer to array:\n");
    for (int i = 0; i < 3; i++) {
        printf("*(p + %d) = %d, address: %p\n", i, *(p + i), (void*)(p + i));
    }
    printf("\n");
}

void pointer_to_structures(void) {
    Person p1 = {1, "john doe"};
    Person *p = &p1;  // pointer to structure

    printf("pointer to structures:\n");
    printf("person id: %d\n", p->id);
    printf("person name: %s\n\n", p->name);
}

void void_pointers(void) {
    int x = 10;
    void *p = &x;  // can point to any data type

    printf("void pointers:\n");
    printf("address stored in void pointer p: %p\n", p);
    printf("value at the address stored in p (after typecasting to int*): %d\n\n", *(int*)p);
}

static int subtract(int a, int b) {
    return a - b;
}

void function_pointer_with_args(void) {
    int (*func_ptr)(int, int) = subtract;

    int result = func_ptr(20, 10);
    printf("function pointer with arguments:\n");
    printf("result of subtraction (20 - 10): %d\n\n", result);
}

void pointer_typecasting(void) {
    int x = 100;
    void *p = &x;

    printf("pointer typecasting:\n");
    printf("original value: %d\n", *(int*)p);

    char *char_ptr = (char*)p;  // typecast to char pointer
    printf("value after typecasting to char*: %d\n\n", *char_ptr);
}

void const_pointers(void) {
    int x = 100;
    const int *ptr_to_const = &x;  // pointer to a constant value
    int *const const_ptr = &x;  // constant pointer to an int
    const int *const const_ptrr = &x; // constant pointer to a constant value

    printf("const pointers:\n");
    printf("value pointed by ptr_to_const: %d\n", *ptr_to_const);
    printf("value pointed by const_ptr: %d\n\n", *const_ptr);
    printf("value pointed by const_ptrr: %d\n\n", *const_ptrr);
}

void dangling_pointers(void) {
    int *p = NULL;
    {
        int x = 50;
        p = &x;
        printf("inside block: value pointed by p: %d\n", *p);
    }
    // dangling
    printf("dangling pointers:\n");
    printf("outside block: dangling pointer p might still point to the old memory: %p\n\n", (void*)p);
}

int main(void) {
    pointer_basics();
    pointer_arithmetic();
    null_pointers();
    pointer_to_pointer();
    dynamic_memory_allocation();
    array_pointers();
    pointer_to_structures();
    void_pointers();
    function_pointer_with_args();
    pointer_typecasting();
    const_pointers();
    dangling_pointers();
    return 0;
}
