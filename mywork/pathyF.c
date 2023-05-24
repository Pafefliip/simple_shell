#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * pathyF - function to check if the string has the path "/bin/"
 * @stringer: the string to carryout the check
 * Return: 0 if false and 1 if true that the path is found
 */

int pathyF(char *stringer)
{
	const char *comP = "/bin/";
	size_t prefix_len = strlen(comP);

	if (strlen(stringer) <= prefix_len)
		return 0;
	
	if (strncmp(comP, stringer, prefix_len) == 0)
	{
		char *command = stringer + prefix_len;
		if (checkerF(command) != NULL)
			return 1;
	}

	return 0;
}
