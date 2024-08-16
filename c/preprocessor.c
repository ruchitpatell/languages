#include <stdio.h>

#include "preprocessor.h"

void define(void) {
    // redefine
    #define PI 3.14
    printf("the value of pi is: %.2f\n", PI);

    int num = 5;
    printf("the square of %d is: %d\n", num, SQUARE(num));
    
    // undefining PI
    #undef PI
    // comp error
    // printf("pi is now undefined: %.2f\n", PI);
}

void conditional_compilation(void) {
    #if DEBUG
        printf("debug mode is on\n");
    #else
        printf("debug mode is off\n");
    #endif
}

void macro_operators(void) {
    // token pasting
    int MAKE_VAR(myVar, 0) = 30; // creates myVar0
    printf("myvar = %d\n", myVar0);

    // stringification
    printf("the name of the variable is: %s\n", STRINGIFY(myVar0));
}

void predefined_macros(void) {
    printf("this file is: %s\n", __FILE__);
    printf("this line is: %d\n", __LINE__);
    printf("compilation date: %s\n", __DATE__);
    printf("compilation time: %s\n", __TIME__);
    printf("the function name is: %s\n", __func__);
}

void error_directive(void) {
    #if __STDC_VERSION__ < 199901L
    #error "C99 or later is required!"
    #endif
}

void pragma(void) {
    #pragma message("compiling with pragma message directive")
    printf("this demonstrates the #pragma directive.\n");

    // disabling a specific warning
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wunused-variable"
    int unused_var = 42; // no warning
    #pragma GCC diagnostic pop
}

int main(void) {
    define();
    conditional_compilation();
    macro_operators();
    predefined_macros();
    error_directive();
    pragma();

    return 0;
}
