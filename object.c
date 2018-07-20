#include <assert.h>
#include <stdlib.h>

#include "types.h"

Object *newObject(VM *vm, ObjectType type)
{
    Object *object = malloc(sizeof(Object));
    assert(object);

    object->type = type;
    object->marked = 0;
    object->next = vm->firstObject;
    vm->firstObject = object;

    return object;
}
