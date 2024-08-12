#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>

struct Point {
    int x;
    int y;
};

struct Example {
    char a;
    int b;
    char c;
};

// 1 byte boundary
#pragma pack(1)
struct PackedExample {
    char a;
    int b;
    char c;
};
#pragma pack()

// typedef
typedef struct {
    int x;
    int y;
} PointTypedef;

// passing as reference
void movePoint(PointTypedef* p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

// dynamically allocate
PointTypedef* createPoint(int x, int y) {
    PointTypedef* p = (PointTypedef*)malloc(sizeof(PointTypedef));
    if (p != NULL) {
        p->x = x;
        p->y = y;
    }
    return p;
}

// static
PointTypedef createAndReturnPoint(int x, int y) {
    PointTypedef p;
    p.x = x;
    p.y = y;
    return p;
}

struct Flags {
    unsigned int is_on : 1;
    unsigned int mode : 2;
};

// nesting
struct Rectangle {
    PointTypedef topLeft;
    PointTypedef bottomRight;
};

struct FlexibleArray {
    int length;
    int data[];
};

// linked list
struct Node {
    int data;
    struct Node* next;
};

union Data {
    int i;
    float f;
};

struct ExampleWithUnion {
    int type;
    union Data data;
};

// optimize
struct Optimized {
    int a;    // 4 bytes
    char b;   // 1 byte
    char c;   // 1 byte
    short d;  // 2 bytes
};

// anonymous
struct {
    int x;
    union {
        float f;
        int i;
    };
} data;

// tree
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

// function pointers in struct
struct Operations {
    int (*add)(int, int);
    int (*sub)(int, int);
};

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

struct PackedData {
    uint16_t header;
    uint32_t value;
} __attribute__((packed));

struct Tagged {
    int tag;
    union {
        int i;
        float f;
        char* s;
    } data;
};

struct Person {
    char* name;
    int age;
};

struct Person shallow_copy(struct Person* p) {
    return *p; // shallow copy
}

struct Person deep_copy(struct Person* p) {
    struct Person copy;
    copy.name = strdup(p->name); // deep copy the string
    copy.age = p->age;
    return copy;
}

// thread safety
struct SharedData {
    int counter;
    pthread_mutex_t lock;
};

void increment(struct SharedData* data) {
    pthread_mutex_lock(&data->lock);
    data->counter++;
    pthread_mutex_unlock(&data->lock);
}

// polymorphism
struct Animal {
    void (*speak)(void);
};

void dog_speak(void) {
    printf("Woof!\n");
}

void cat_speak(void) {
    printf("Meow!\n");
}

// serialization and deserialization
struct Record {
    int id;
    char name[20];
};

void save_record(struct Record* r, FILE* f) {
    fwrite(r, sizeof(struct Record), 1, f);
}

void load_record(struct Record* r, FILE* f) {
    fread(r, sizeof(struct Record), 1, f);
}

int main(void) {

    // typedef
    PointTypedef pt = {10, 20};
    printf("Point: (%d, %d)\n", pt.x, pt.y);

    // dynamic malloc
    PointTypedef* dynamicPoint = createPoint(15, 25);
    if (dynamicPoint) {
        printf("Dynamic Point: (%d, %d)\n", dynamicPoint->x, dynamicPoint->y);
        free(dynamicPoint);
    }

    // bit field
    struct Flags flags = {1, 3}; // is_on = 1, mode = 3
    printf("Flags: is_on = %u, mode = %u\n", flags.is_on, flags.mode);

    // function pointers
    struct Operations ops = { add, sub };
    printf("Add: %d\n", ops.add(5, 3));
    printf("Sub: %d\n", ops.sub(5, 3));

    // polymorphism simulator
    struct Animal dog = { dog_speak };
    struct Animal cat = { cat_speak };
    dog.speak();
    cat.speak();

    // // serialization and deserialization
    // struct Record rec = {1, "Example"};
    // FILE* file = fopen("record.bin", "wb");
    // if (file) {
    //     save_record(&rec, file);
    //     fclose(file);
    // }

    // struct Record loadedRec;
    // file = fopen("record.bin", "rb");
    // if (file) {
    //     load_record(&loadedRec, file);
    //     fclose(file);
    //     printf("Loaded Record: id = %d, name = %s\n", loadedRec.id, loadedRec.name);
    // }

    return 0;
}
