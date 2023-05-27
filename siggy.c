#include "shell.h"

void _siggy(int lin)
{
	(void)lin;
	write(STDIN_FILENO, "\n$ ", 3);
}
