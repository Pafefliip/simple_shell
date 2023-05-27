#include "shell.h"

int _myCount(char *pLiner, const char *myDelimeter)
{
	int count = 0;
	char *tk = NULL;
	char *myCopoint = NULL;

	myCopoint = strdup(pLiner);
	tk = strtok(myCopoint, myDelimeter);
	while (tk != NULL)
	{
		count++;
		tk = strtok(NULL, myDelimeter);
	}
	free(myCopoint);
	return (count);
}
