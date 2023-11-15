#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

extern char **environ;

void execute_command(const char *cmd);
void handle_error(const char *message);

#endif 
