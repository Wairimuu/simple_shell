#include "simple_shell.h"

int main() {
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("$ ");
        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        // Remove newline at the end
        cmd[strlen(cmd) - 1] = '\0';

        execute_command(cmd);
    }
    return 0;
}
