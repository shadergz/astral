
#include <stdio.h>
#include <stdarg.h>

#include <terminal.h>

i32 term_advise_eprintf(astral_ctx_t* astral_ctx, const char* format, ...)
{
    i32 result_out = 0;

    if (format != NULL)
    {
        va_list va_args;
        va_start(va_args, format);

        result_out = vfprintf(stderr, format, va_args);
        va_end(va_args);
    }

    if (astral_ctx == NULL) fputs("*** Main context is NULL, this may be reported!\n", stderr);

    return result_out;
}
