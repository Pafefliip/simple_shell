#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 *@param argc The number of command-line arguments.
 *@param argv An array of command-line argument strings.
 *@param env An environment string.
 *include the main function
 *in case of failure of the child process it returns -1
 *execve executes the command given by user
 *the child process gives a return value of 0 always
 *the parent process is told to wait till the child is terminated
 *child process will carry out the execution of the command
 *forking the child process
 */
void prompt(char **argv, char **env)
{
	char *string = NULL;
	size_t s = 0;
	int status;
	int a;
	ssize_t charNum;
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
		while (string[a])
		{
			if (string[a] == '\n')
			{
				string[a] = '\0';
				break;
			}
			a++;
		}
		argv[0] = string;

		our_pid = fork();
		if (our_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		else if (our_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				printf("%s : No such directory or file\n", argv[0]);
		}
		else
		{
			wait(&status);
		}
	}
}
