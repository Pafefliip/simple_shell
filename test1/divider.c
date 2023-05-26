#include "shell.h"

char **_divider(int nToken, char *pLiner, const char *myDelimeter)
{
	char **tokMan = NULL;
	char *tk = NULL;
	int c = 0;
	char *myCopoint = NULL;

	nToken = _myCount(pLiner, myDelimeter);
	myCopoint = strdup(pLiner);
	if (myCopoint == NULL)
	{
		free(pLiner);
		return (NULL);
	}
	tokMan = malloc(sizeof(char *) * (nToken) + 1);
	if (tokMan == NULL)
		return (NULL);
	tk = strtok(myCopoint, myDelimeter);
	while (tk != NULL)
	{
		tokMan[c] = malloc(sizeof(char) * strlen(tk));
		strcpy(tokMan[c], tk);
		tk = strtok(NULL, myDelimeter);
		c++;
	}
	if (tokMan == NULL)
	{
		_myFreedom(tokMan);
		return (NULL);
	}
	tokMan[c] = '\0';
	return (tokMan);
}
