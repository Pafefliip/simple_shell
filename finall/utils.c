#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * prompt - Display the shell prompt and execute commands
 * @argv: The command-line arguments (unused)
 * @env: The environment variables
 */
void prompt(char **argv, char **env)
{
	char *string = NULL;
	size_t s = 0;
	ssize_t charNum;
	pid_t our_pid;
	int status;
	int a;
	char *command;

	while (1)
	{
		printf("simpleShell $ ");
		charNum = getline(&string, &s, stdin);
		if (charNum == -1)
		{
			free(string);
			exit_shell();
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

		/* Tokenize the command and arguments */
		int numArgs = 0;
		char *token;
		char *arguments[MAX_ARGS + 2]; /* +2 for command and NULL terminator */

		token = strtok(string, " ");
		while (token != NULL && numArgs < MAX_ARGS + 1)
		{
			arguments[numArgs++] = token;
			token = strtok(NULL, " ");
		}
		arguments[numArgs] = NULL;

		if (numArgs == 0)
			continue;

		/* Check if it is a built-in command */
		if (strcmp(arguments[0], "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(arguments[0], "env") == 0)
		{
			print_environment(env);
			continue;
		}

		/* Check if the command exists in the PATH */
		char *path;
		int found = 0;

		path = strtok(getenv("PATH"), ":");
		while (path != NULL)
		{
			command = malloc(strlen(path) + strlen(arguments[0]) + 2);
			sprintf(command, "%s/%s", path, arguments[0]);
			if (access(command, X_OK) == 0)
			{
				found = 1;
				break;
			}
			free(command);
			path = strtok(NULL, ":");
		}

		if (!found)
		{
			printf("%s: command not found\n", arguments[0]);
			continue;
		}

		our_pid = fork();
		if (our_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		else if (our_pid == 0)
		{
			if (execve(command, arguments, env) == -1)
			{
				printf("%s: No such file or directory\n", arguments[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}

		free(command);
	}
}
