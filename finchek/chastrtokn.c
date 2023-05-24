#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **chastrtokn(char *string)
{
	const char *delim = " \t\r\n\a";
	char *token;
	int bufsize = 64;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}

	token = strtok(string, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("realloc error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return tokens;
}
