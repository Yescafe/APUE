#include "apue.h"

int
main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < argc/* || argv[argc] != NULL*/; ++i)
        printf("argv[%d]: %s\n", i, argv[i]);
}