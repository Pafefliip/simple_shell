#include "shell.h"

void _executor(char **my_comd, int dcout, char **argv)
{
	pid_t our_pid;
	int status;
	char *myW = NULL;
	(void)dcout;
	(void)argv;

	our_pid = fork();
	if (our_pid == 0)
	{
		myW = _findWay(my_comd[0]);
		if (myW == NULL)
		{
			free(myW);
			_myFreedom(my_comd);
			return;
		}
		else
		{
			if (execve(myW, my_comd, env) == -1)
				perror("Error ");
		}
	}
	else
		wait(&status);
}
