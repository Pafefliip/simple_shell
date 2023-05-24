#include <stdio.h>
#include <stdlib.h>

char *read_command(void)
{
	char *command = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	characters = getline(&command, &bufsize, stdin);
	
	if (characters == -1)
	{
		free(command);
		exit(EXIT_SUCCESS);
	}

	return command;
}
