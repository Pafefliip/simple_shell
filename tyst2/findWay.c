#include "shell.h"

char *_findWay(char *my_comd)
{
	char *path = NULL;
	char *tRoady = NULL;
	char *bossRoad = NULL;
	const char *myDelimeter = ":";
	int count = 0;

	path = getenv("PATH");
	tRoady = _divider(count, path, myDelimeter);
	if (tRoady == NULL)
	{
		free(tRoady);
		return (NULL);
	}
	bossRoad = _jenga(tRoady, my_comd);
	if (bossRoad == NULL)
	{
		_myFreedom(tRoady);
		return (NULL);
	}
	_myFreedom(tRoady);
	return (bossRoad);
}
