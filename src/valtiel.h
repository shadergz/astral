
#ifndef ASTRAL_VALTIEL_H
#define ASTRAL_VALTIEL_H

#include <objects.h>

typedef enum valtiel_level {
    VALTIEL_LEVEL_ERROR,
} valtiel_level_e;

typedef struct valtiel_source {
    const char* code_source;
    const char* func_name;
    i32         code_line;
} valtiel_source_t;

i32 valtiel_eputs(astral_ctx_t* astral_ctx, const valtiel_source_t* valtiel_source, const char* message);

#define valtiel_log_eputs(astral_ctx, message)          \
    do {                                                \
        static const valtiel_source_t log_eputs = {     \
            .code_source = __FILE_NAME__,               \
            .func_name = __func__,                      \
            .code_line = __LINE__                       \
        };                                              \
        valtiel_eputs(astral_ctx, &log_eputs, message); \
    } while (0)

#endif
