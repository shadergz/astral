
#ifndef ASTRAL_HEAP_OBJECTS_H
#define ASTRAL_HEAP_OBJECTS_H

#include <objects.h>

u0* amalloc(usize esize);
u0  afree(u0* pointer);

#define amalloc_object(object_type)\
    amalloc(sizeof(object_type))

#endif
