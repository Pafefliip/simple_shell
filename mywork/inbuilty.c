#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <strings.h>

/**
 * inbuilty - functions that check if inbuilt command is present
 * @stringer: string to check if inbuilt command is present
 * Return: 0 if true and 1 if false
 */

int inbuilty(char *stringer)
{
	if (_strcmp(stringer, "exit") == 0)
		return 1;
	if (_strcmp(stringer, "env") == 0)
	{
		print_env();
		return 1;
	}
	return 0;
}

void print_env(void)
{
	extern char **environ;
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
