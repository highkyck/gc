#include <assert.h>
#include <stdlib.h>

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
