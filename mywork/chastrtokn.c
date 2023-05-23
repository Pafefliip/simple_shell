#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * chastrtokn - print "$ " first line
 * @stringer: string parameter
 * Return: array of string
 */

char **chastrtokn(char *stringer)
{
	char **token = NULL;
	char *pms = NULL;
	int b = 0;
	const char *delimiter = " ";
	char *tempString = strdup(stringer);

	if (tempString == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = malloc(sizeof(char *) * 8);
	if (token == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	pms = strtok(tempString, delimiter);
	while (pms != NULL)
	{
		token[b] = strdup(pms);
		if (token[b] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		b++;
		pms = strtok(NULL, delimiter);
	}
	token[b] = NULL;

	free(tempString);
	return token;
}
