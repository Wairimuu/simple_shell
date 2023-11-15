nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256

extern char **environ;

int main() {
	    char cmd[MAX_CMD_LEN];
	        while (1) {
			        printf("$ ");
				        if (fgets(cmd, sizeof(cmd), stdin) == NULL) {
						            printf("\n");
							                exit(0);
									        }
					        cmd[strlen(cmd) - 1] = '\0';  // remove newline at the end
						        if (access(cmd, F_OK) != -1) {
								            char *argv[] = {cmd, NULL};
									                if (execve(cmd, argv, environ) == -1) {
												                perror("Error executing command");
														            }
											        } else {
													            printf("%s: command not found\n", cmd);
														            }
							    }
		    return 0;
}

