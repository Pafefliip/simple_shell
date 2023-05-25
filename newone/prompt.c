#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define BUFFER_SIZE 1024

void prompt()
{
    char buffer[BUFFER_SIZE];
    ssize_t charNum;
    pid_t child_pid;
    int status;

    char *args[2];

    while (1)
    {
        printf("#cisfun$ ");

        charNum = read(STDIN_FILENO, buffer, BUFFER_SIZE);

        if (charNum == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        buffer[charNum - 1] = '\0';

        args[0] = buffer;
        args[1] = NULL;

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            if (execve(buffer, args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            waitpid(child_pid, &status, 0);
        }
    }
}
