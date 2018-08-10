#include <stdio.h>
#include <stdlib.h>

#include "gc.h"
#include "types.h"

void mark_all(VM *vm)
{
    for (int i = 0; i < vm->stack_size; i++) {
        mark(vm->stack[i]);
    }
}

void mark(Object *object)
{
    if (object->marked)
        return;

    object->marked = 1;

    if (object->type == IS_PAIR) {
        mark(V_PVAL_P(object).head);
        mark(V_PVAL_P(object).tail);
    }
}

void sweep(VM *vm)
{
    Object **object = &vm->first_object;
    while (*object) {
        if (!(*object)->marked) {
            Object *unreached = *object;
            *object = unreached->next;
            free(unreached);
            vm->num_objects--;
        } else {
            (*object)->marked = 0;
            object = &(*object)->next;
        }
    }
}

void __gc(VM *vm)
{
    size_t num_objects = vm->num_objects;
    mark_all(vm);
    sweep(vm);
    vm->max_objects = vm->num_objects * 2;
    printf("Collected %lu objects, %lu remaining.\n",
           num_objects - vm->num_objects, vm->num_objects);
}
