nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define MAX_NUM_ARGS 64

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

						        // Split command into arguments
							//         char *argv[MAX_NUM_ARGS];
							//                 char *word = strtok(cmd, " ");
							//                         int i = 0;
							//                                 while (word != NULL) {
							//                                             argv[i++] = word;
							//                                                         word = strtok(NULL, " ");
							//                                                                 }
							//                                                                         argv[i] = NULL;  // end of arguments
							//
							//                                                                                 // Check if command is executable
							//                                                                                         if (access(argv[0], F_OK) != -1) {
							//                                                                                                     if (execve(argv[0], argv, environ) == -1) {
							//                                                                                                                     perror("Error executing command");
							//                                                                                                                                 }
							//                                                                                                                                         } else {
							//                                                                                                                                                     printf("%s: command not found\n", argv[0]);
							//                                                                                                                                                             }
							//                                                                                                                                                                 }
							//                                                                                                                                                                     return 0;
							//                                                                                                                                                                     }
