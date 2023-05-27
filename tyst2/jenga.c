#include "shell.h"

char _jenga(char **tRoady, char *my_comd)
{
	char *execRd = NULL;
	int c;
	struct stat buf;

	for (c = 0; tRoady[c] != NULL; c++)
	{
		execRd = malloc(sizeof(char) * (strlen(tRoady[c]) + strlen(my_comd) + 2));
		strcpy(execRd, tRoady[c]);
		strcat(execRd, "/");
		strcat(execRd, my_comd);
		strcat(execRd, "\0");

		if (stat(execRd, &buf) == 0)
		{
			return (execRd);
		}
	}
	if (stat(my_comd, &buf) == 0)
	{
		free(execRd);
		return (my_comd);
	}
	free(execRd);
	return (NULL);
}
