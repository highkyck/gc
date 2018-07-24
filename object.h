#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

Object *new_object(VM *, _type);
void dump(Object *object);

#endif /* OBJECT_H */
