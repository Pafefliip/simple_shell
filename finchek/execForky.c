#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execForky(char **args, char *fullPath)
{
	pid_t our_pid;

	our_pid = fork();
	if (our_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (our_pid == 0)
	{
		if (execve(fullPath, args, NULL) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
