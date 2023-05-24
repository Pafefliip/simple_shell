#include "shell.h"
#include <string.h>
#include <stdlib.h>
#include "shell.h"

char *_strcat(char *dest, const char *src)
{
    char *temp = dest;

    while (*temp)
        temp++;

    while (*src)
    {
        *temp = *src;
        temp++;
        src++;
    }

    *temp = '\0';
    return dest;
}
