// #include <unistd.h>
// #include <stdlib.h>
// #include <fcntl.h>
// #include <stdio.h>
// #include <string.h>
// #include <sys/wait.h>

// int main(int argc, char **argv) {
//     if (argc < 5) {
//         write(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 ... cmdN file2\n", 45);
//         return 1;
//     }

//     int num_cmds = argc - 3;
//     int **pipes = malloc((num_cmds - 1) * sizeof(int *));
//     if (pipes == NULL) {
//         perror("malloc");
//         return 1;
//     }

//     for (int i = 0; i < num_cmds - 1; i++) {
//         pipes[i] = malloc(2 * sizeof(int));
//         if (pipes[i] == NULL) {
//             perror("malloc");
//             goto cleanup_pipes;
//         }
//         if (pipe(pipes[i]) == -1) {
//             perror("pipe");
//             goto cleanup_pipes;
//         }
//     }

//     int fd_in = open(argv[1], O_RDONLY);
//     if (fd_in == -1) {
//         perror("open");
//         goto cleanup_pipes;
//     }

//     int fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd_out == -1) {
//         perror("open");
//         goto cleanup_in;
//     }

//     pid_t pid;
//     for (int i = 0; i < num_cmds; i++) {
//         pid = fork();
//         if (pid == -1) {
//             perror("fork");
//             goto cleanup_out;
//         }
//         if (pid == 0) { // Child process
//             if (i == 0) {
//                 dup2(fd_in, STDIN_FILENO);
//             } else {
//                 dup2(pipes[i - 1][0], STDIN_FILENO);
//             }

//             if (i == num_cmds - 1) {
//                 dup2(fd_out, STDOUT_FILENO);
//             } else {
//                 dup2(pipes[i][1], STDOUT_FILENO);
//             }

//             // Close all pipe ends in child
//             for (int j = 0; j < num_cmds - 1; j++) {
//                 close(pipes[j][0]);
//                 close(pipes[j][1]);
//             }

//             close(fd_in);
//             close(fd_out);

//             char **cmd_args = parse_command(argv[i + 2]); // Skip file1
//             execve(find_path(cmd_args[0]), cmd_args, environ);
//             perror("execve");
//             exit(1); // This line won't be reached if execve succeeds
//         }
//         // Parent process closes pipe ends it won't use further
//         if (i > 0) close(pipes[i - 1][0]);
//         if (i < num_cmds - 1) close(pipes[i][1]);
//     }

//     // Wait for all children to complete
//     for (int i = 0; i < num_cmds; i++) {
//         wait(NULL);
//     }

//     // Close file descriptors in parent
//     close(fd_in);
//     close(fd_out);

//     // Clean up pipes in parent
//     for (int i = 0; i < num_cmds - 1; i++) {
//         free(pipes[i]);
//     }
//     free(pipes);
//     return 0;

// cleanup_out:
//     close(fd_out);
// cleanup_in:
//     close(fd_in);
// cleanup_pipes:
//     for (int i = 0; i < num_cmds - 1; i++) {
//         if (pipes[i]) {
//             free(pipes[i]);
//         }
//     }
//     free(pipes);
//     return 1;
// }

































// int main(int argc, char **argv) {

//     pid_t pid;
//     for (int i = 0; i < num_cmds; i++) {
//         pid = fork();
//         if (pid == -1) {
//             perror("fork");
//             exit(1);
//         }
//         if (pid == 0) { // Child process
//             // Input redirection
//             if (i == 0) {
//                 dup2(fd_in, STDIN_FILENO);
//             } else {
//                 dup2(pipes[i - 1][0], STDIN_FILENO);
//             }

//             // Output redirection
//             if (i == num_cmds - 1) {
//                 dup2(fd_out, STDOUT_FILENO);
//             } else {
//                 dup2(pipes[i][1], STDOUT_FILENO);
//             }

//             // Close all pipe ends in child
//             for (int j = 0; j < num_cmds - 1; j++) {
//                 close(pipes[j][0]);
//                 close(pipes[j][1]);
//             }

//             close(fd_in);
//             close(fd_out);

//             // Parse command and execute
//             char **cmd_args = parse_command(argv[i + 2]); // Skip file1
//             execve(find_path(cmd_args[0]), cmd_args, environ);
//             perror("execve");
//             exit(1);
//         }
//         // Parent process closes pipe ends it won't use further
//         if (i > 0) close(pipes[i - 1][0]); // Close read end of previous pipe
//         if (i < num_cmds - 1) close(pipes[i][1]); // Close write end of current pipe
//     }

//     // Close remaining pipe ends in parent
//     for (int i = 0; i < num_cmds - 1; i++) {
//         close(pipes[i][0]);
//         free(pipes[i]);
//     }
//     free(pipes);

//     // Wait for all children to complete
//     for (int i = 0; i < num_cmds; i++) {
//         wait(NULL);
//     }

//     close(fd_in);
//     close(fd_out);
//     return 0;
// }


// // Implement parse_command and find_path here, similar to before
