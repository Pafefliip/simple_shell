#include "Shell.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void execForky(char **args, char *fullPath)
{
	pid_t our_pid = fork();

	if (our_pid == 0)
	{
		if (execve(fullPath, args, NULL) == -1)
		{
			perror("execve error");
			exit(EXIT_FAILURE);
		}
	}
	else if (our_pid < 0)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
