#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

/**
 * inbuilty - functions that check if inbuilt command is present
 * @stringer: string to check if inbuilt command is present
 * Return: 0 if true and 1 if false
 */

int inbuilty(char *stringer)
{
	char *a[] = {"cd", "exit", "hello"};
	int num = sizeof(a) / sizeof(a[0]);

	for (int i = 0; i < num; i++)
	{
		if (_strcmp(a[i], stringer) == 0)
		{
			switch (i)
			{
				case 0:
					chdir(stringer);
					return 1;
				case 1:
					printf("bye\n");
					return 2;
				case 2:
					char *myName = getenv("HOSTNAME");
					printf("hello %s\n", myName);
					return 1;
			}
		}
	}
	return 0;
}
