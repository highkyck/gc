#ifndef VM_H
#define VM_H

#include "types.h"

VM *new_vm();
void free_vm(VM *);
void push(VM *, Object *);
Object *pop(VM *);
void push_int(VM *, int64_t);
Object *push_pair(VM *);

#endif /* VM_H */
