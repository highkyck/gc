#ifndef TYPES_H
#define TYPES_H

typedef enum { OBJ_INT, OBJ_PAIR } ObjectType;

typedef struct sObject {
    ObjectType type;
    struct sObject *next;
    union {
        int value;
        struct {
            struct sObject *head;
            struct sObject *tail;
        };
    };
    unsigned char marked;
} Object;

#define STACK_MAX 256

typedef struct {
    Object *stack[STACK_MAX];
    Object *firstObject;
    int stackSize;
} VM;

VM *newVm();
void push(VM *, Object *);
Object *pop(VM *);
Object *newObject(VM *, ObjectType);
void pushInt(VM *, int);
Object *pushPair(VM *);

void markAll(VM *);
void mark(Object *);

#endif /* TYPES_H */
