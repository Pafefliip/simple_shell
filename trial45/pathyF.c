#include "Shell.h"
#include <stdlib.h>
#include <string.h>

int pathyF(char *command, char **fullPath)
{
	char *path = "/bin/";
	*fullPath = malloc(strlen(path) + strlen(command) + 1);
	if (*fullPath == NULL)
	{
		perror("malloc error");
		return 0;
	}

	strcpy(*fullPath, path);
	strcat(*fullPath, command);

	return 1;
}
