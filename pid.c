#include "shell.h"

int main(void)
{
	pid_t ourPid;

	ourPid = getpid();

	printf("this is our pid: %u\n", ourPid);

	return (0);
}
