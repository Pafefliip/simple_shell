#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>


/**
 * main - main for built shell
 * @argc: argument number
 * @argv: argument arrays
 * @env: array of enviroment variables
 * Return: Always 0
 */

int main(int argc, char *argv[], char *env[])
{
	char **string;
	size_t s = 20;
	size_t qr = 4;
	size_t nbut = 0;
	ssize_t charNum;
	char *pointer, *mb;

	if (argc > 1)
		argv[1] = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("simpleShelly $ ");
		pointer = malloc(sizeof(char) * s);
		if (charNum == -1)
		{
			free(pointer);
			exit(EXIT_FAILURE);
		}
		if (*pointer != '\n')
		{
			string = charstrtokn(pointer);
			if (_strcmp("exit", string[0]) == 0)
				break;
			nbut = inbuilty(string[0]);
			mb = checkerF(string[0]);
			if (nbut ==  0 && mb != NULL)
				string[0] = mb;
			qr = pathyF(string[0]);
			if (qr == 1)
				execForky(string, env);
			if (mb == NULL && qr == 0 && nbut == 0)
				printf("./shell: No such directory or file\n");
		}
	}
	free(mb);
	free(pointer);
	free(string);
	exit(0);
}
