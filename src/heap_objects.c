
#include <malloc.h>

#include <heap_objects.h>
#include <valtiel.h>

static const i32 ZERO_ALLOC_TROUBLESHOOT = 128;

u0* acalloc(usize ecount, usize esize)
{
    if (esize == 0 || ecount == 0)
    {
        valtiel_log_eputs(NULL, "`acalloc();` Can't allocate zero size elements\n");

        return NULL;
    }

    u0* calloc_ptr = calloc(ecount, esize);
    if (calloc_ptr == NULL) {}
    return calloc_ptr;
}

u0* amalloc(usize esize)
{
    if (esize >= ZERO_ALLOC_TROUBLESHOOT)
        // when leading with bigger allocations, acalloc is more safety and faster than amalloc
        return acalloc(1, esize);

    if (esize == 0)
    {
        valtiel_log_eputs(NULL, "Fill-up the structure/type, we can't allocate a zero size "
                                "memory buffer\n");
        return NULL;
    }

    return malloc(esize);
}

u0 afree(u0* pointer)
{
   if (pointer == NULL) return;

   if (malloc_usable_size(pointer) != 0)
   {
       free(pointer);
   }
}
