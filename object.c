#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "types.h"
#include "object.h"
#include "gc.h"

Object *new_object(VM *vm, _type t)
{
    if (vm->num_objects == vm->max_objects)
        __gc(vm);

    Object *object = malloc(sizeof(Object));
    assert(object);

    object->type = t;
    object->marked = 0;
    object->next = vm->first_object;
    vm->first_object = object;
    vm->num_objects++;

    return object;
}

void dump(Object *object)
{
    switch (V_TYPE_P(object)) {
    case IS_INT:
        printf("INT:%lld", V_LVAL_P(object));
        break;
    case IS_PAIR:
        printf("PAIR:{");
        dump(V_PVAL_P(object).head);
        printf(", ");
        dump(V_PVAL_P(object).tail);
        printf("}");
    default:
        break;
    }
}
