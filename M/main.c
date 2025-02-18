/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:46:36 by noctis            #+#    #+#             */
/*   Updated: 2025/02/18 03:47:23 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int c, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		t[2];

	// atexit(leaks);
	if (c != 5)
		ft_exit("Error: ./pipex file1 cmd1 | cmd2 file2");
	if (pipe(t) == -1)
		ft_exit("Error: pipe");
	pid1 = fork();
	if (pid1 < 0)
		ft_exit("fError: fork pid1");
	if (pid1 == 0)
		ft_prosses(t, av, env, 1);
	pid2 = fork();
	if (pid2 < 0)
		ft_exit("Error: fork pid2");
	if (pid2 == 0)
		ft_prosses(t, av, env, 2);
	close(t[0]);
	close(t[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

void	ft_prosses(int t[2], char **av, char **env, int f)
{
	int	fd;

	if (f == 1)
	{
		fd = ft_open(av[1], f);
		if ((dup2(fd, STDIN_FILENO) == -1) || (dup2(t[1], STDOUT_FILENO) == -1))
			ft_exit("Error: dup2");
		close(t[1]);
		close(t[0]);
		close(fd);
		ft_execve(av[2], env);
	}
	else
	{
		fd = ft_open(av[4], f);
		if ((dup2(fd, STDOUT_FILENO) == -1) || (dup2(t[0], STDIN_FILENO) == -1))
			ft_exit("Error: dup2");
		close(t[1]);
		close(t[0]);
		close(fd);
		ft_execve(av[3], env);
	}
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			ft_exit("Error: files access");
		fd = open(t, O_RDONLY);
		if (fd == -1)
			ft_exit("Error: fd1");
	}
	else
	{
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_exit("Error: fd2");
	}
	return (fd);
}

void	ft_execve(char *ar, char **env)
{
	char	**cmd;
	char	*path;

	if (!env)
		ft_exit("Error: env segf");
	cmd = ft_split(ar, ' ');
	if (!cmd)
		ft_exit("Error: cmd split");
	path = ft_fix_path(cmd[0], env);
	if (!path)
	{
		ft_free(cmd);
		ft_exit("path error");
	}
	execve(path, cmd, env);
	ft_free(cmd);
	free(path);
	ft_exit("exceve eroor");
}
