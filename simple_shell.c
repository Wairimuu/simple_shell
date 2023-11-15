#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

/**
 * handle_error - Prints an error message and exits with failure status.
 * @message: The error message to be printed.
 */
void handle_error(const char *message)
{
    perror(message);
    exit(EXIT_FAILURE);
}

/**
 * execute_command - Executes a given command.
 * @cmd: The command to be executed.
 */
void execute_command(const char *cmd)
{
    // Check if the input is too long
    if (strlen(cmd) >= MAX_CMD_LEN - 1)
    {
        printf("Command is too long\n");
        return;
    }

    if (access(cmd, F_OK) != -1)
    {
        char *argv[] = {cmd, NULL};
        // Display an error message before execve
        handle_error(""); // Will print the error message if execve fails
        if (execve(cmd, argv, environ) == -1)
        {
            handle_error("Error executing command");
        }
    }
    else
    {
        printf("%s: command not found\n", cmd);
    }
}
