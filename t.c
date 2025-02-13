/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:14:39 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/13 10:18:57 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

char *find_path(char *cmd, char **envp)
{
    int i = 0;
    char *full_cmd;
    char **paths;
    
    while (envp[i] && strncmp(envp[i], "PATH=", 5) != 0)
        i++;
    if (!envp[i])
        return cmd; // No PATH variable, return original cmd
    
    paths = ft_split(envp[i] + 5, ':');
    if (!paths)
        return cmd;

    i = 0;
    while (paths[i])
    {
        full_cmd = ft_strjoin(ft_strjoin(paths[i], "/"), cmd);
        if (access(full_cmd, X_OK) == 0)
            return full_cmd;
        free(full_cmd);
        i++;
    }
    return cmd; // Command not found in PATH
}

void execute_cmd(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    if (!args)
        error_exit("ft_split failed");

    char *path = find_path(args[0], envp);
    execve(path, args, envp);
    error_exit("execve failed");
}

int main(int argc, char *argv[], char *envp[])
{
    if (argc != 5)
    {
        printf("Usage: ./pipex file1 cmd1 cmd2 file2\n");
        return EXIT_FAILURE;
    }

    int pipe_fd[2];
    if (pipe(pipe_fd) == -1)
        error_exit("pipe failed");

    pid_t pid1 = fork();
    if (pid1 < 0)
        error_exit("fork failed");

    if (pid1 == 0) // First child process (cmd1)
    {
        int infile = open(argv[1], O_RDONLY);
        if (infile == -1)
            error_exit("open infile failed");

        dup2(infile, STDIN_FILENO);    // Redirect file1 -> stdin
        dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout -> pipe write end

        close(pipe_fd[0]); // Close unused read end
        close(pipe_fd[1]); // Close write end after duplication
        close(infile); 

        execute_cmd(argv[2], envp); // Run cmd1
    }

    pid_t pid2 = fork();
    if (pid2 < 0)
        error_exit("fork failed");

    if (pid2 == 0) // Second child process (cmd2)
    {
        int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (outfile == -1)
            error_exit("open outfile failed");

        dup2(pipe_fd[0], STDIN_FILENO);  // Redirect pipe read end -> stdin
        dup2(outfile, STDOUT_FILENO); // Redirect stdout -> file2

        close(pipe_fd[1]); // Close unused write end
        close(pipe_fd[0]); // Close read end after duplication
        close(outfile);

        execute_cmd(argv[3], envp); // Run cmd2
    }

    // Parent closes both pipe ends
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // Wait for both children to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return EXIT_SUCCESS;
}