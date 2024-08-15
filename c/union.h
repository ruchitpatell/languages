#ifndef UNIOON_H
#define UNIOON_H

#include <stdlib.h>

// memory pptimization
union SensorData {
    int rawValue;
    float scaledValue;
};

// variant ds networking
union IPAddress {
    uint32_t ipv4;
    uint8_t ipv6[16];
};

struct Packet {
    int version;
    union IPAddress address;
};

// type punning graphics
union FloatInt {
    float f;
    uint32_t i;
};

// type punning undefined behavior
union RegisterData {
    uint32_t allBits;
    struct {
        uint16_t lowerBits;
        uint16_t upperBits;
    };
};

// anonymous for os
struct Task {
    int id;
    union {
        int priority;
        int niceValue;
    };
};

// variant data types
struct Transaction {
    int type;  // 0 for int, 1 for float, 2 for string
    union {
        int intValue;
        float floatValue;
        char stringValue[20];
    } data;
};

void memory_optimization(void);
void variant_data_structures(void);
void type_punning(void);
void type_punning_undefined_behavior(void);
void anonymous_unions(void);
void variant_data_types(void);

#endif // UNIOON_H
