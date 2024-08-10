#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>

// Compile-time assertion
static_assert(sizeof(int) == 4, "int size is not 4 bytes");

// exit cleanup register
void cleanup_function(void) {
    printf("Cleanup function executed.\n");
}

void if_else(int value) {
    printf("If Else\n");

    if (value > 0) {
        printf("Value is positive.\n");
    } else if (value < 0) {
        printf("Value is negative.\n");
    } else {
        printf("Value is zero.\n");
    }

    printf("\n");
    return;
}

void switch_case(int value) {
    printf("Switch case\n");

    switch (value) {
        case 1:
            printf("Value is one.\n");
            break;
        case 2:
            printf("Value is two.\n");
            break;
        default:
            printf("Value is neither one nor two.\n");
            break;
    }

    printf("\n");
    return;
}

void loops(void) {
    // for loop
    printf("For loop\n");
    for (int i = 0; i < 3; i++) {
        printf("For loop iteration: %d\n", i);
    }
    printf("\n");

    // while loop
    printf("While loop\n");
    int count = 0;
    while (count < 3) {
        printf("While loop count: %d\n", count);
        count++;
    }
    printf("\n");

    // do-while loop
    printf("Do while loop\n");
    count = 0;
    do {
        printf("Do-while loop count: %d\n", count);
        count--;
    } while (count > 0);
    printf("\n");

    // goto statement
    goto label;
    printf("This line is skipped.\n");

    label:
        printf("Goto label reached.\n");

    return;
}

int main(void) {

    // register the cleanup function to be called on normal termination
    atexit(cleanup_function);

    // assertion
    int *ptr = NULL;
    assert(ptr == NULL);

    // abort
    if (1 == 2) {
        printf("Critical error occurred, aborting...\n");
        abort();
    }

    // exit
    if (0 == 1) {
        printf("Non-critical error occurred, exiting...\n");
        exit(EXIT_FAILURE);
    }

    if_else(2);
    switch_case(2);
    loops();

    exit(EXIT_SUCCESS);
}

#if __STDC_VERSION__ < 199901L
#error "This code requires C99 or later."
#endif
