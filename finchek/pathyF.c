#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int pathyF(char *command, char **fullPath)
{
	char *path = "/bin/";
	*fullPath = malloc(strlen(path) + strlen(command) + 1);
	if (!*fullPath)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	strcpy(*fullPath, path);
	strcat(*fullPath, command);
	
	if (access(*fullPath, X_OK) == 0)
		return 1;
	return 0;
}
