#include <objects.h>
#include <heap_objects.h>

#include <valtiel.h>
#include <terminal.h>
#include <user.h>

#define MAIN_SYMBOL main
#define MAIN_ENTRY(...) MAIN_SYMBOL(__VA_ARGS__)

i32 main_event(astral_ctx_t* astral_ctx, i32 event_holder, __attribute__((unused)) const char* format,
               __attribute__((unused)) va_list init_args)
{
    const user_options_t* user_options = astral_ctx->user_options;

    if (user_options->verbosity_level < CAUGHT_EVENT_PERM_VERBOSITY) return -1;

    switch (event_holder)
    {
    case ASTRAL_EVENT_INSIDE_INIT:
    case ASTRAL_EVENT_INSIDE_ASSERT:
    default: break;
    }
    return 0;
}

i32 astral_init(astral_ctx_t* astral_ctx)
{
    astral_ctx->event_caught = (i32 (*)(struct astral_ctx*, astral_event_e,
            const char*, va_list)) main_event;
    astral_ctx->user_options = (user_options_t*)amalloc_object(user_options_t);

    return 0;
}

i32 astral_deinit(astral_ctx_t* astral_ctx)
{
    afree(astral_ctx->user_options);

    return 0;
}

i32 MAIN_ENTRY(i32 argc, char** argv)
{
    astral_ctx_t* astral_main = (astral_ctx_t*)amalloc_object(astral_ctx_t);

    if (astral_main == NULL)
    {
        term_advise_eprintf(NULL, "Can't allocate (%ld) for a Main Astral object, this is a seriously "
                                  "error!\n", sizeof(astral_ctx_t));

        valtiel_log_eputs(NULL, "Main Astral context wasn't initialized, this error may be reported\n");
        return -1;
    }

    astral_init(astral_main);

    user_init(astral_main);

    astral_deinit(astral_main);

    afree(astral_main);
    return 0;
}
