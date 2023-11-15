#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

void execute_command(const char *cmd) {
    // Check if the input is too long
    if (strlen(cmd) >= MAX_CMD_LEN - 1) {
        printf("Command is too long\n");
        return;
    }

    if (access(cmd, F_OK) != -1) {
        char *argv[] = {cmd, NULL};
        // Display an error message before execve
        perror("");  // Will print the error message if execve fails
        if (execve(cmd, argv, environ) == -1) {
            perror("Error executing command");
            exit(EXIT_FAILURE);  // Exit with failure status
        }
    } else {
        printf("%s: command not found\n", cmd);
    }
}
