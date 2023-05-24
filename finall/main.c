#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - The entry point of the simple shell program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * @env: An array of environment strings.
 *
 * Return: The exit status of the program.
 */
int main(int __attribute__((unused)) argc, char **argv, char **env)
{
	prompt(argv, env);
	return (EXIT_SUCCESS);
}
