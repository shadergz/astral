
#ifndef ASTRAL_OBJECTS_H
#define ASTRAL_OBJECTS_H

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef int32_t     i32;
typedef void        u0;
typedef uint16_t    usize;

typedef enum astral_event {
    ASTRAL_EVENT_INSIDE_INIT,
    ASTRAL_EVENT_INSIDE_ASSERT

} astral_event_e;

typedef struct user_options {
    i32 verbosity_level;
} user_options_t;

typedef struct astral_ctx {

    user_options_t* user_options;

    i32 (*event_caught)(struct astral_ctx* astral_ctx, astral_event_e event_id,
            const char* format, va_list va_args);

} astral_ctx_t;

#endif
