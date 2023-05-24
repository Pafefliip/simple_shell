#include "shell.h"
#include <string.h>

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + strlen(dest);
	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = '\0';
	return dest;
}
