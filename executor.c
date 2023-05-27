#include "shell.h"

void _executor(char **my_comd)
{
	pid_t our_pid;
	int status;

	our_pid = fork();
	if (our_pid == 0)
	{
		if (execve(my_comd[0], my_comd, NULL) == -1)
			perror("Error ");
	}
	else
		wait(&status);
}
