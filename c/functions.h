#ifndef __FUNCTINOS_H__
#define __FUNCTINOS_H__

int add(int a, int b);

void printMessage(const char* message);

void increment(int* a);

// inline
// inline int square(int x) {
//     return x * x;
// }

void printNumbers(int count, ...);

void callbackFunction(int n);

void processCallback(void (*callback)(int));

int* createArray(int size);

void dynamicFunctionDispatchingExample(void);

void recursionExample(int n);

// int also_add(int, int) __attribute__((alias("add")));

#endif
