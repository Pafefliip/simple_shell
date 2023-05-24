#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t charNum;
	char **args;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleShelly $ ");

		charNum = getline(&line, &bufsize, stdin);
		if (charNum == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}

		if (*line != '\n')
		{
			args = chastrtokn(line);
			if (_strcmp("exit", args[0]) == 0)
			{
				free(line);
				free(args);
				exit(EXIT_SUCCESS);
			}
			else if (_strcmp("env", args[0]) == 0)
			{
				printEnvironment();
			}
			else
			{
				executeCommand(args);
			}
		}
	}

	free(line);
	free(args);
	exit(EXIT_SUCCESS);
}
