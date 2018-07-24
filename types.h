#ifndef TYPES_H
#define TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef enum { IS_INT, IS_PAIR } _type;

typedef struct _Object {
    _type type;
    union {
        int64_t l;
        struct {
            struct _Object *head;
            struct _Object *tail;
        } p;
    } v;
    unsigned char marked;
    struct _Object *next;
} Object;

#define V_TYPE(_o) (_o).type
#define V_TYPE_P(_p) V_TYPE(*(_p))
#define V_LVAL(_o) (_o).v.l
#define V_LVAL_P(_p) V_LVAL(*(_p))
#define V_PVAL(_o) (_o).v.p
#define V_PVAL_P(_p) V_PVAL(*(_p))

#define STACK_MAX 256

typedef struct {
    Object *stack[STACK_MAX];
    Object *first_object;
    size_t num_objects;
    size_t max_objects;
    size_t stack_size;
} VM;

#endif /* TYPES_H */
