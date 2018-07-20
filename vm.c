#include <assert.h>
#include <stdlib.h>

#include "types.h"

VM *newVm()
{
    VM *vm = malloc(sizeof(VM));
    vm->stackSize = 0;
    return vm;
}

void push(VM *vm, Object *value)
{
    assert(vm->stackSize < STACK_MAX, "Stack overflow!");
    vm->stack[vm->stackSize++] = value;
}

Object *pop(VM *vm)
{
    assert(vm->stackSize > 0, "Stack underflow!");
    return vm->stack[--vm->stackSize];
}

void pushInt(VM *vm, int intValue)
{
    Object *object = newObject(vm, OBJ_INT);
    object->value = intValue;
    push(vm, object);
}

Object *pushPair(VM *vm)
{
    Object *object = newObject(vm, OBJ_PAIR);
    object->tail = pop(vm);
    object->head = pop(vm);

    push(vm, object);
    return object;
}
