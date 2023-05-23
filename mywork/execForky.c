#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

/**
 * execForky - system execution with fork
 * @star: array of strings gotten from line command
 */

void execForky(char **star)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork error");
		return;
	}

	if (pid == 0)
	{
		if (execvp(star[0], star) == -1)
		{
			perror("./shell: No such directory or file");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
	waitpid(pid, &status, 0);
	}
}
