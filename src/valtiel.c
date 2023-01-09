#include <stdio.h>

#include <valtiel.h>
#include <terminal.h>
#include <string.h>

#define VALTIEL_CMP_CTX(source, ctx)\
    if (strncmp(source->func_name, ctx, strlen(ctx)) == 0)
i32 valtiel_context(const valtiel_source_t* val_source)
{
    VALTIEL_CMP_CTX(val_source, "valtiel_init") return ASTRAL_EVENT_INSIDE_INIT;
    return -1;
}
#undef VALTIEL_CMP_CTX

i32 valtiel_do(astral_ctx_t* astral_ctx, valtiel_level_e level,
               const valtiel_source_t* val_source, const char* message)
{
    if (astral_ctx != NULL)
    {
        astral_ctx->event_caught(astral_ctx, valtiel_context(val_source), message, NULL);
    }

    if (level == VALTIEL_LEVEL_ERROR)
        return fprintf(stderr, "Valtiel error: %s", message);

    return 0;
}

i32 valtiel_eputs(astral_ctx_t* astral_ctx, const valtiel_source_t* val_source, const char* message)
{
    if (astral_ctx == NULL)
    {
        term_advise_eprintf(NULL, NULL);
    }

    return valtiel_do(astral_ctx, VALTIEL_LEVEL_ERROR, val_source, message);
}