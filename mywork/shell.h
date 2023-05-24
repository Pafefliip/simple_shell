#ifndef SHELL_H
#define SHELL_H

#include <stddef.h>

char **chastrtokn(char *stringer);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
int inbuilty(char *stringer);
void print_env(void);
char *checkerF(char *stringer);
int pathyF(char *stringer);
void execForky(char **stringer);

#endif 
