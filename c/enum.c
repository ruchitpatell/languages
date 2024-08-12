#include <stdio.h>
#include <stdarg.h>
#include "enum.h"

void printDirection(enum Direction dir) {
    switch (dir) {
        case NORTH: printf("North\n"); break;
        case EAST:  printf("East\n"); break;
        case SOUTH: printf("South\n"); break;
        case WEST:  printf("West\n"); break;
        default:    printf("Unknown direction\n"); break;
    }
}

void printPermissions(int permissions) {
    if (permissions & READ)    printf("Read ");
    if (permissions & WRITE)   printf("Write ");
    if (permissions & EXECUTE) printf("Execute ");
    printf("\n");
}

void logMessage(enum Direction level, ...) {
    va_list args;
    va_start(args, level);
    printf("Logging message for direction: ");
    printDirection(level);
    va_end(args);
}

void printStatus(enum Status status) {
    const char* StatusMessages[STATUS_COUNT] = {
        "OK",
        "Warning",
        "Error"
    };
    if (status < STATUS_COUNT) {
        printf("Status: %s\n", StatusMessages[status]);
    } else {
        printf("Unknown status\n");
    }
}

int main(void) {
    enum Direction myDirection = EAST;
    printDirection(myDirection);

    int myPermissions = READ | EXECUTE;
    printPermissions(myPermissions);

    logMessage(WEST);

    Route myRoute;
    myRoute.direction = NORTH;
    myRoute.distance = 100;
    printf("Route: ");
    printDirection(myRoute.direction);
    printf("Distance: %d\n", myRoute.distance);

    enum Status currentStatus = WARNING;
    printStatus(currentStatus);

    return 0;
}
