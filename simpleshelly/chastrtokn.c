#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

/**
 * chastrtokn - print "$ " on the first line
 * @stringer: is a string parameter
 * Return: Array of string
 */

ssize_t getline(char **pointLine, size_t *s, FILE *stream);

char **chastrtokn(char *stringer)
{
	char **token, *pms;
	int b = 0;
	int c = 0;

	token = malloc(8 * sizeof(char *));
	if (token == NULL)
	{
		perror("unsuccesful");
		exit(1);
	}
	pms = strtok(stringer, " ");
	while (pms != NULL)
	{
		while (pms[c])
		{
			if (pms[c] == '\n')
				pms[c] = '\0';
			c++;
		}
		token[b] = pms;
		b++;
		c = 0;
		pms = strtok(NULL, " ");
	}
	token[b] = NULL;
	return (token);
}
