#ifndef SHELL_H
#define SHELL_H

/**
 * prompt - Displays the prompt and waits for user input to execute commands.
 * @argv: An array of command-line argument strings.
 * @env: An array of environment strings.
 */
void prompt(char **argv, char **env);

/**
 * exit_shell - Exits the shell program.
 */
void exit_shell(void);

/**
 * print_environment - Prints the current environment.
 * @env: An array of environment strings.
 */
void print_environment(char **env);

#endif
