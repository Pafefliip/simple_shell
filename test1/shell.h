#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void _dControl(char *line);
char **_divider(int nToken, char *pLiner, const char *myDelimeter);
int _myCount(char *pLiner, const char *myDelimeter);
void _myFreedom(char **str);
void _executor(char **cmd);
void _siggy(int lin);

#endif
