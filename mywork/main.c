#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * main - main for built my own shell
 * return: always 0
 */

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t charNum;
	char **string;
	int nbut, qr;
	char *mb;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("simple_shell $ ");
		
		charNum = getline(&line, &bufsize, stdin);
		if (charNum == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (*line != '\n')
		{
			string = chastrtokn(line);
			if (_strcmp("exit", string[0]) == 0)
				break;
			nbut = inbuilty(string[0]);
			mb = checkerF(string[0]);
			if (nbut == 0 && mb != NULL)
				string[0] = mb;
			qr = pathyF(string[0]);
			if (qr == 1)
				execForky(string);
			if (mb == NULL && qr == 0 && nbut == 0)
				printf("simple_shell: command not found: %s\n", string[0]);
		}
	}

	free(line);
	free(string);
	exit(0);
}
