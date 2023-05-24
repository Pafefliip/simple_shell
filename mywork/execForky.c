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
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execForky(char **stringer)
{
	pid_t our_pid;
	int status;

	our_pid = fork();
	if (our_pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	if (our_pid == 0)
	{
		if (execve(stringer[0], stringer, NULL) == -1)
		{
			perror("Execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
