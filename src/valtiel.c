#include <stdio.h>

#include <valtiel.h>
#include <terminal.h>

i32 valtiel_do(astral_ctx_t* astral_ctx, valtiel_level_e level, const char* message)
{
    (void)astral_ctx;
    if (level == VALTIEL_LEVEL_ERROR)
        return fprintf(stderr, "Valtiel error: %s", message);

    return 0;
}

i32 valtiel_eputs(astral_ctx_t* astral_ctx, const valtiel_source_t* valtiel_source, const char* message)
{
    (void)valtiel_source;
    if (astral_ctx == NULL)
    {
        term_advise_eprintf(NULL, NULL);
    }
    return valtiel_do(astral_ctx, VALTIEL_LEVEL_ERROR, message);
}