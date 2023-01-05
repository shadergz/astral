#include <stdio_ext.h>

#define MAIN_SYMBOL main
#define MAIN_ENTRY(...) MAIN_SYMBOL(__VA_ARGS__)

int MAIN_ENTRY(int argc, char** argv)
{
    fprintf(stderr, "Hello world of hell!");
    return 0;
}
