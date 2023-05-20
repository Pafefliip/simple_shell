#include <stdio.h>
#include <stdio.h>
#include "shell.h"
#include <strings.h>

/**
 * This function serves as the entry point for the shell program.
 * It calls the `prompt` function if no command-line arguments are provided.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @param env An environment string.
 * @return The exit status of the program.
 */

int main(int argc, char **argv, char **env)
{
	if (argc == 1)
	{
		prompt(argv, env);
	}

	return (0);
}
