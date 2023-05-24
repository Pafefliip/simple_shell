#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>

/**
 * checkerF - function to check if system command exist, if so avoid callinf fork
 * @stringer: string to apply the check
 * Return: the required path or NULL if false
 */

char *checkerF(char *stringer)
{
	DIR *dirc = opendir("/bin/");
	char *tempo = NULL;
	char *stc = NULL;
	struct dirent *enty;

	if (dirc == NULL)
		return NULL;

	enty = readdir(dirc);
	while (enty != NULL)
	{
		tempo = enty->d_name;
		if (_strcmp(tempo, stringer) == 0)
		{
			stc = _strcat("/bin/", stringer);
			closedir(dirc);
			return stc;
		}
		enty = readdir(dirc);
	}
	closedir(dirc);
	return NULL;
}
