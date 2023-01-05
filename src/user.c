#include <user.h>

i32 user_init(astral_ctx_t* astral_ctx)
{
    user_options_t* user_options = astral_ctx->user_options;

    user_options->verbosity_level = MAXIMUM_EVENT_PERM_VERBOSITY;

    return 0;
}
