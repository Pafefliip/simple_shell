#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <strings.h>

/**
 * inbuilty - functions that check if in built commands is present
 * @stringer: string to carry out the check
 * Return: 0 if true and 1 if false
 */

int inbuilty(char *stringer)
{
	char **a;
	int b = 0;
	char *myName;

	a = malloc(sizeof(char *) * 3);
	if (a == NULL)
		return (0);
	a[0] = "cd";
	a[1] = "exit";
	a[2] = "hello";
	for (b = 0; b = ; b++)
	{
		if (_strcmp(a[b], stringer) == 0)
		{
			break;
		}
		b++;
	}
	b++;
	switch (b)
	{
		case 1
			ch(stringer);
			free(a);
			return (1);
		case 2
			printf("bye");
			free(a);
			return (2);
		case 3
			myName = getemv("HOSTNAME");
			printf("hello %s\n", myName);
			free(a);
			return (1);
		default
			free(a);
			return (0);
	}
	return (0);
}
