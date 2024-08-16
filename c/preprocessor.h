#ifndef PREPROCESSING_H
#define PREPROCESSING_H

#define PI 3.14159

// macro function
#define SQUARE(x) ((x) * (x))

// conditional compilation example
#define DEBUG 1

// undefine macro
#undef PI

#define MAKE_VAR(x, y) x ## y  // token pasting
#define STRINGIFY(x) #x         // stringification

void define(void);
void conditional_compilation(void);
void macro_operators(void);
void predefined_macros(void);
void error_directive(void);
void pragma(void);

#endif // PREPROCESSING_H
