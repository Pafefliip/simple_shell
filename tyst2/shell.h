#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

void _dControl(char *myLine);
char **_divider(int nToken, char *pLiner, const char *myDelimeter);
int _myCount(char *pLiner, const char *myDelimeter);
void _myFreedom(char **stringer);
void _executor(char **my_comd);
void _siggy(int lin);
char *_jenga(char **tRoady, char *my_comd);
char *_findWay(char *my_comd);

extern char **env;

#endif
