#include "apue.h"
#include <fcntl.h>

int
main(int argc, char *argv[])
{
    int             i, fd;
    struct stat     statbuf;
    struct timespec times[2];
    for (i = 1; i < argc; ++i) {
        if (stat(argv[1], &statbuf) < 0) {        // fetch current times
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {         // truncate
            err_ret("%s: open error", argv[1]);
        }
        times[0] = statbuf.st_atim;       // the latest access time
        times[1] = statbuf.st_mtim;       // the latest modify time
        if (futimens(fd, times) < 0)
            err_ret("%s: futimens error", argv[1]);
        close(fd);
    }
    exit(0);
}