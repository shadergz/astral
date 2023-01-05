#include <objects.h>
#include <heap_objects.h>

#include <valtiel.h>
#include <terminal.h>

#define MAIN_SYMBOL main
#define MAIN_ENTRY(...) MAIN_SYMBOL(__VA_ARGS__)

int MAIN_ENTRY(int argc, char** argv)
{
    astral_ctx_t* astral_main = (astral_ctx_t*)amalloc_object(astral_ctx_t);

    if (astral_main == NULL)
    {
        term_advise_eprintf(NULL, "Can't allocate (%ld) for a Main Astral object, this is a seriously "
                                  "error!\n", sizeof(astral_ctx_t));

        valtiel_log_eputs(NULL, "Main Astral context wasn't initialized, this error may be reported\n");
        return -1;
    }

    afree(astral_main);

    return 0;
}
