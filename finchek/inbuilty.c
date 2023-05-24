#include "shell.h"
#include <string.h>

int inbuilty(char *command)
{
	if (strcmp(command, "exit") == 0 || strcmp(command, "env") == 0)
		return 1;
	return 0;
}
