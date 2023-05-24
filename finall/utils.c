#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "shell.h"

/**
 * prompt - Displays the prompt and waits for user input to execute commands.
 * @argv: An array of command-line argument strings.
 * @env: An array of environment strings.
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
	char *path;
	int found;

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
		argv[0] = string;

		/* Check if it is a built-in command */
		if (strcmp(argv[0], "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(argv[0], "env") == 0)
		{
			print_environment(env);
			continue;
		}

		/* Check if the command exists in the PATH */
		found = 0;

		path = strtok(getenv("PATH"), ":");
		while (path != NULL)
		{
			command = malloc(strlen(path) + strlen(argv[0]) + 2);
			sprintf(command, "%s/%s", path, argv[0]);
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
			printf("%s: command not found\n", argv[0]);
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
			if (execve(command, argv, env) == -1)
			{
				printf("%s: No such file or directory\n", argv[0]);
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

/**
 * exit_shell - Exits the shell program.
 */
void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * print_environment - Prints the current environment.
 * @env: An array of environment strings.
 */
void print_environment(char **env)
{
	int i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
