#include "shell.h"

int main(int argc, char **argv)
{
	char *pLiner = NULL;
	size_t sizy = 0;
	ssize_t meRead = 0;
	char **my_comd = NULL;
	int nToken = 0, dcout = 0;
	const char *myDelimeter = "\n\t ";
	(void)argc;
	signal(SIGINT, _siggy);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			fflush(stdout);
			write(STDIN_FILENO, "#cisfun$ ", 9);
		}
		dcout++;
		meRead = getline(&pLiner, &sizy, stdin);
		if (meRead != -1)
		{
			my_comd = _divider(nToken, pLiner, myDelimeter);
			if (my_comd == NULL)
			{
				free(pLiner);
				return (-1);
			}
			_executor(my_comd, dcout, argv);
		}
		else
		{
			_dControl(pLiner);
		}
	}
	_myFreedom(my_comd);
	free(pLiner);
	return (0);
}
