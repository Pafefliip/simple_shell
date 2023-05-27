#include "shell.h"

void _myFreedom(char **stringer)
{
	int c;

	for (c = 0; stringer[c] != NULL; c++)
		free(stringer[c]);
	free(stringer);
}
