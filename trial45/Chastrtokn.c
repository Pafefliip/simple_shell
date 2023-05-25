#include "Shell.h"
#include <stdlib.h>
#include <string.h>

char **chastrtokn(char *stringer)
{
	char **args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc error");
		return NULL;
	}

	args[0] = stringer;
	args[1] = NULL;

	return args;
}
