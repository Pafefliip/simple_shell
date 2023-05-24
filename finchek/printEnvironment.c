#include "shell.h"
#include <stdio.h>

extern char **environ;

void printEnvironment(void)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
