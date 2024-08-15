#include <stdio.h>
#include "union.h"

// memory optimization
void memory_optimization(void) {
    union SensorData data;
    data.rawValue = 100;
    printf("memory optimization: raw value: %d\n", data.rawValue);
    data.scaledValue = 3.14f;
    printf("memory optimization: Scaled value: %.2f\n", data.scaledValue);
    printf("memory optimization: Undefined raw value: %d\n", data.rawValue);
}

// variant ds networking
void variant_data_structures(void) {
    struct Packet packet;
    packet.version = 4;
    packet.address.ipv4 = 0x7F000001;
    printf("ip4 Address: %x\n", packet.address.ipv4);
}

// type punning graphics
void type_punning(void) {
    union FloatInt fi;
    fi.f = 1.0f;
    printf("type punning: float 1.0 as int: %08x\n", fi.i);
}

// type punning with undefined behavior
void type_punning_undefined_behavior(void) {
    union RegisterData reg;
    reg.allBits = 0xAABBCCDD;
    printf("type punning undefined behavior: Lower Bits: %04x, Upper Bits: %04x\n", reg.lowerBits, reg.upperBits);
}

// anonymous union - os
void anonymous_unions(void) {
    struct Task task;
    task.id = 1;
    task.priority = 5;

    printf("anonymous union: task ID: %d, priority: %d\n", task.id, task.priority);
}

// variant data types
void variant_data_types(void) {
    struct Transaction txn;
    txn.type = 2;
    snprintf(txn.data.stringValue, 20, "AAPL");
    printf("variant Data Types: ticker: %s\n", txn.data.stringValue);
}

int main(void) {
    memory_optimization();
    variant_data_structures();
    type_punning();
    type_punning_undefined_behavior();
    anonymous_unions();
    variant_data_types();

    return 0;
}
