#include "shell.h"
/*_dcontrol - Function to handle the termination of the shell program*/

void _dControl(char *myLine)
{
	free(myLine);
	exit(0);
}
