#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *checkerF(char *command)
{
	char *path = "/bin/";
	char *fullPath = malloc(strlen(path) + strlen(command) + 1);
	if (!fullPath)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	strcpy(fullPath, path);
	strcat(fullPath, command);
	return fullPath;
}
