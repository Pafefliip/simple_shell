#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * pathyF - function to check if the string has the path "/bin/"
 * @stringer: the string to carry out the check 
 * Return: 0 if false and 1 if true that the path is found
 */

int pathyF(char *stringer)
{
	char *comP = "/bin/", *pointer, *c;
	int b = 0, m = 0;

	pointer = malloc(sizeof(char) * 60);
	if (pointer == NULL)
		return (0);
	while (comP[b] != '\0')
	{
		if (comP[b] != stringer[b])
		{
			free(pointer);
			return (0);
		}
		b++;
	}
	while (stringer[b] != '\0')
	{
		pointer[m] = stringer[b];
		m++;
		b++;
	}
	pointer[m] = '\0';
	c = checkerF(pointer);
	if (c != NULL)
	{
		free(pointer);
		return (1);
	}
	return (0);
}
