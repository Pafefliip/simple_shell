#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(char **av, char **env)

	char *string = NULL;
	size_t s = 0;
	int status;
	int a;
	ssize_t charNum;
	char *argv[] = {NULL, NULL};
	pid_t our_pid;

while (1)
{
	printf("simpleShelly $ ");
	charNum = getline(&string, &s, stdin);

	if (charNum == -1)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	a = 0;
	while (string[1])
	{
		if (string[1] == '\n')
			string[1] = 0;
		a++;
	}
	argv[0] = string;
	/*forking the child process*/
	our_pid = fork();
	/*in case of failure of the child process it returns -1*/
	if (our_pid == -1)
	{
		free(string);
		exit(EXIT_FAILURE);
	}
	/*child process will carry out the execution of the command*/
	/*the child process gives a return value of 0 always*/
	if (our_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
			printf("%s : No such directory or file\n", av[0]);
	}
	/*execve executes the command given by user*/
	else
	{
		wait(&status);
		/*the parent process is told to wait till the child is terminated*/
	}
}
