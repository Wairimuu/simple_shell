nclude <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 256
#define MAX_NUM_ARGS 64

extern char **environ;

char **split_string(char *str) {
	    char **result = malloc(MAX_NUM_ARGS * sizeof(char *));
	        int i = 0;
		    while (*str != '\0') {
			            while (*str == ' ') ++str;  // skip spaces
				            if (*str == '\0') break;

					            char *start = str;
						            while (*str != ' ' && *str != '\0') ++str;
							            int len = str - start;

								            result[i] = malloc(len + 1);
									            strncpy(result[i], start, len);
										            result[i][len] = '\0';
											            ++i;
												        }
		        result[i] = NULL;
			    return result;
}

char *search_path(char *cmd) {
	    char *path = getenv("PATH");
	        char *path_copy = strdup(path);
		    char *dir = strtok(path_copy, ":");

		        while (dir != NULL) {
				        char *cmd_path = malloc(strlen(dir) + strlen(cmd) + 2);
					        strcpy(cmd_path, dir);
						        strcat(cmd_path, "/");
							        strcat(cmd_path, cmd);

								        if (access(cmd_path, F_OK) != -1) {
										            free(path_copy);
											                return cmd_path;
													        }

									        free(cmd_path);
										        dir = strtok(NULL, ":");
											    }

			    free(path_copy);
			        return NULL;
}

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
							//         char **argv = split_string(cmd);
							//
							//                 // Check if command is "exit" or "env"
							//                         if (strcmp(argv[0], "exit") == 0) {
							//                                     exit(0);
							//                                             } else if (strcmp(argv[0], "env") == 0) {
							//                                                         for (char **env = environ; *env != NULL; ++env) {
							//                                                                         printf("%s\n", *env);
							//                                                                                     }
							//                                                                                                 continue;
							//                                                                                                         }
							//
							//                                                                                                                 // Search for command in PATH
							//                                                                                                                         char *cmd_path = search_path(argv[0]);
							//                                                                                                                                 if (cmd_path != NULL) {
							//                                                                                                                                             if (fork() == 0) {
							//                                                                                                                                                             if (execve(cmd_path, argv, environ) == -1) {
							//                                                                                                                                                                                 perror("Error executing command");
							//                                                                                                                                                                                                     exit(1);
							//                                                                                                                                                                                                                     }
							//                                                                                                                                                                                                                                 } else {
							//                                                                                                                                                                                                                                                 wait(NULL);
							//                                                                                                                                                                                                                                                             }
							//                                                                                                                                                                                                                                                                         free(cmd_path);
							//                                                                                                                                                                                                                                                                                 } else {
							//                                                                                                                                                                                                                                                                                             printf("%s: command not found\n", argv[0]);
							//                                                                                                                                                                                                                                                                                                     }
							//                                                                                                                                                                                                                                                                                                         }
							//                                                                                                                                                                                                                                                                                                             return 0;
							//                                                                                                                                                                                                                                                                                                             }
