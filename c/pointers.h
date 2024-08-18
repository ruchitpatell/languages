#ifndef POINTERS_H
#define POINTERS_H



// Function declarations

void pointer_basics(void);
void pointer_arithmetic(void);
void null_pointers(void);
void pointer_to_pointer(void);
void dynamic_memory_allocation(void);
void array_pointers(void);
void pointer_to_structures(void);
void void_pointers(void);
void function_pointer_with_args(void);
void pointer_typecasting(void);
void const_pointers(void);
void dangling_pointers(void);

typedef struct {
    int id;
    char name[50];
} Person;

#endif /* POINTERS_H */
