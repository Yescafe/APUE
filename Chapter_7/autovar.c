#include <stdio.h>

FILE *
open_data(void)
{
    FILE *fp;
    char databuf[BUFSIZ];
    
    if ((fp = fopen("datafile", "r")) == NULL)     // setvbuf makes this the stdio buffer
        return(NULL);
    if (setvbuf(fp, databuf, _IOLBF, BUFSIZ) != 0)
        return(NULL);
    return(fp);               // error
}