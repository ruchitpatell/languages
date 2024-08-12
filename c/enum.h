#ifndef ENUMS_H
#define ENUMS_H

enum Direction {
    NORTH = 1,
    EAST,
    SOUTH,
    WEST
};

enum FilePermissions {
    READ = 1 << 0,    // 0001
    WRITE = 1 << 1,   // 0010
    EXECUTE = 1 << 2  // 0100
};

enum Color {
    RED = 1,
    GREEN = 5,
    BLUE
};

typedef enum {
    SMALL,
    MEDIUM,
    LARGE
} Size;

typedef struct {
    enum Direction direction;
    int distance;
} Route;

enum Status {
    OK,
    WARNING,
    ERROR,
    STATUS_COUNT
};

#endif // ENUMS_H
