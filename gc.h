#ifndef GC_H
#define GC_H

#include "types.h"

void mark_all(VM *);
void mark(Object *);
void __gc(VM *);

#endif /* GC_H */
