#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pathyF - function to check if the string has the path "/bin/"
 * @stringer: the string to carryout the check
 * Return: 0 if false and 1 if true that the path is found
 */

int pathyF(char *stringer)
{
	const char *comP = "/bin/";
	char *pointer;
	int b = 0, m = 0;

	pointer = malloc(sizeof(char) * (strlen(stringer) + 1));
	if (pointer == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	while (comP[b] != '\0')
	{
		if (comP[b] != stringer[b])
		{
			free(pointer);
			return 0;
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

	if (checkerF(pointer) != NULL)
	{
		free(pointer);
		return 1;
	}

	free(pointer);
	return 0;
}
