#include "shell.h"
#include <string.h>

#define MAX_ARGS 10

void prompt(char **argv, char **env)
{
	int status;
	char *string = NULL;
	size_t s;
	ssize_t charNum;
	pid_t our_pid;
	int g;
	char *token[MAX_ARGS];

	while (1)
	{
		printf("simpleShelly $ ");
		charNum = getline(&string, &s, stdin);
		if (charNum == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		string[strcspn(string, "\n")] = '\0';
		g = 0;
		token[g] = strtok(string, " ");

		while (token[g])
		{
			g++;
			token[g] = strtok(NULL, " ");
		}
		token[g] = NULL;
		our_pid = fork();
		if (our_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		else if (our_pid == 0)
		{
			if (execve(token[0], token, env) == -1)
			{
				printf("%s No such directory or file\n", token[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
}
