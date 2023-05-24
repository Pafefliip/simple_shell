#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define MAX_ARGS 64

pid_t pid;

void execute_command(char *command)
{
/* Check if the command is "exit"*/
	if (strcmp(command, "exit\n") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	pid = fork();
	
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
        /* Child process*/

        /* Split command and arguments*/
		char *args[MAX_ARGS];
		char *token;
		int i = 0;
		
		token = strtok(command, " \n");
		while (token != NULL)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		args[i] = NULL;

        /* Check if the command exists in PATH*/
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
        /* Parent process*/
		int status;
		waitpid(pid, &status, 0);
	}
}
