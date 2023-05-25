#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

char **chastrtokn(char *stringer);
char *checkerF(char *command);
int inbuilty(char *command);
int pathyF(char *command, char **fullPath);
void execForky(char **args, char *fullPath);
void printEnvironment(void);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
void executeCommand(char **args);

#endif
