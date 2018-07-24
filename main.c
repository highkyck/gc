#include <stdio.h>

#include "types.h"
#include "vm.h"
#include "gc.h"
#include "object.h"

void test1() 
{
    printf("Test 1: Objects on stack are preserved.\n");
    VM *vm = new_vm();
    push_int(vm, 1);
    push_int(vm, 2);

    __gc(vm);
    free_vm(vm);
}

void test2()
{
    printf("Test 2: Unreached objects are collected.\n");
    VM *vm = new_vm();
    push_int(vm, 1);
    push_int(vm, 2);
    pop(vm);
    pop(vm);

    __gc(vm);
    free_vm(vm);
}

void test3()
{
    printf("Test 3: Reach nested objects.\n");
    VM *vm = new_vm();
    push_int(vm, 1);
    push_int(vm, 2);
    push_pair(vm);
    push_int(vm, 3);
    push_int(vm, 4);
    push_pair(vm);
    push_pair(vm);

    __gc(vm);
    free_vm(vm);
}

int main(int argc, char *argv[]) 
{
    test1();
    test2();
    test3();
    return 0;
}
