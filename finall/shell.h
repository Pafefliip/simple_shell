#ifndef SHELL_H
#define SHELL_H

/*
 * Function: display_prompt
 * ------------------------
 * Displays the shell prompt.
 */
void display_prompt(void);

/*
 * Function: read_command
 * ----------------------
 * Reads a command entered by the user.
 *
 * Returns:
 *   - The command entered by the user as a string.
 *   - NULL if the end of file (Ctrl+D) is reached.
 */
char *read_command(void);

/*
 * Function: execute_command
 * -------------------------
 * Executes the given command.
 *
 * command: The command to be executed.
 */
void execute_command(char *command);

#endif /* SHELL_H */
