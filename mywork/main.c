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
			string = chastrtokn(line);
			if (_strcmp("exit", string[0]) == 0)
				break;
			int nbut = inbuilty(string[0]);
			char *mb = checkerF(string[0]);
			if (nbut == 0 && mb != NULL)
				string[0] = mb;
			int qr = pathyF(string[0]);
			if (qr == 1)
				execForky(string);
			if (mb == NULL && qr == 0 && nbut == 0)
				printf("./shell: No such directory or file\n");
		}
	}

	free(line);
	free(string);
	exit(0);
}
