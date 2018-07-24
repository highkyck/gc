#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "gc.h"
#include "object.h"
#include "types.h"
#include "vm.h"

VM *new_vm()
{
    VM *vm = malloc(sizeof(VM));
    vm->stack_size = 0;
    vm->first_object = NULL;
    vm->num_objects = 0;
    vm->max_objects = 8;
    return vm;
}

void push(VM *vm, Object *value)
{
    assert(vm->stack_size < STACK_MAX);
    vm->stack[vm->stack_size++] = value;
}

Object *pop(VM *vm)
{
    assert(vm->stack_size > 0);
    return vm->stack[--vm->stack_size];
}

void push_int(VM *vm, int64_t lval)
{
    Object *object = new_object(vm, IS_INT);
    V_LVAL_P(object) = lval;
    push(vm, object);
}

Object *push_pair(VM *vm)
{
    Object *object = new_object(vm, IS_PAIR);
    V_PVAL_P(object).tail = pop(vm);
    V_PVAL_P(object).head = pop(vm);

    push(vm, object);
    return object;
}

void free_vm(VM *vm)
{
    vm->stack_size = 0;
    __gc(vm);
    free(vm);
}

