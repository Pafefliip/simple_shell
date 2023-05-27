#include "shell.h"

void _dControl(char *myLine)
{
	free(myLine);
	exit(0);
}
