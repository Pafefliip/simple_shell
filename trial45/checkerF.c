#include "Shell.h"
#include <stdlib.h>
#include <string.h>

char *checkerF(char *command)
{
	char *path = "/bin/";
	char *fullPath = malloc(strlen(path) + strlen(command) + 1);
	if (fullPath == NULL)
	{
		perror("malloc error");
		return NULL;
	}

	strcpy(fullPath, path);
	strcat(fullPath, command);

	return fullPath;
}
