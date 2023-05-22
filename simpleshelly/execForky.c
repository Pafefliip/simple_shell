#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <strings.h>
#include <unistd.h>

/**
 * execForky - system execution with fork
 * @star: array of strings gotten from line command
 * @env: enviroment variables from the parent
 * Return: void
 */

void execForky(char **star, char *env[])
{
	pid_t our_pid;
	int status;

	our_pid = fork();
	if (our_pid < 0)
	{
		perror("errorforky");
		return;
	}
	if (our_pid == 0)
	{
		if (execve(star[0], star, env) == -1)
			perror("./shell: No such directory or file\n");
	}
	else
	{
		wait(&status);
	}
}
