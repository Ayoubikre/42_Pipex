/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:40:49 by noctis            #+#    #+#             */
/*   Updated: 2025/02/17 17:27:28 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	ft_outils(char *t, int f)
{
	char	command[50];

	if (f == 0)
	{
		sprintf(command, "leaks %d", getpid());
		system(command);
	}
	else if (f == 1)
	{
		perror(t);
		exit(1);
	}
	else if (f == 2)
	{
		if (access(t, R_OK) == -1)
			ft_outils("cant fid the file", 1);
	}
	else if (f == 3)
	{
		free(t);
	}
	return (0);
}

char	*ft_fix_path(char *cmd, char **env)
{
	char	*t;
	char	**path;
	int		i;
	int		f;

	i = 0;
	f = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) != NULL)
		{
			f = 1;
			path = ft_split(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (f == 0)
		ft_outils("path not found error", 1);
	i = 0;
	while (path[i])
	{
		t = ft_strjoin(path[i], "/");
		t = ft_strjoin(t, cmd);
		// ft_outils(t, 1);
		if (access(t, R_OK) != -1)
			return (t);
        free(t);
		i++;
	}
	return (NULL);
}

void	ft_execve(char *ar, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(ar, ' ');
	if (!cmd)
		ft_outils("cmd split error", 1);
	path = ft_fix_path(cmd[0], env);
	if (!path)
		ft_outils("path error", 1);
	if (execve(path, cmd, env) == -1)
		ft_outils("exceve eroor", 1);
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		ft_outils(t, 2);
		fd = open(t, O_RDONLY);
		if (fd == -1)
			ft_outils("FD_1 error", 1);
	}
	else
	{
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_outils("FD_2 error", 1);
	}
	return (fd);
}

void	ft_prosses(int t, char **av, char **env, int f)
{
	int	fd;

	if (f == 1)
	{
		fd = ft_open(av[1], f);
		if (dup2(fd, STDIN_FILENO) == -1)
			ft_outils("dup2 error", 1);
		close(fd);
		if (dup2(t, STDOUT_FILENO) == -1)
			ft_outils("dup2 error", 1);
		close(t);
		ft_execve(av[2], env);
	}
	else
	{
		fd = ft_open(av[4], f);
		if (dup2(fd, STDOUT_FILENO) == -1)
			ft_outils("dup2 error", 1);
		close(fd);
		if (dup2(t, STDIN_FILENO) == -1)
			ft_outils("dup2 error", 1);
		close(t);
		ft_execve(av[3], env);
	}
}

int	main(int c, char **av, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		t[2];

	if (c != 5)
		ft_outils("argv error: ./pipex file1 cmd1 | cmd2 file2", 1);
	if (pipe(t) == -1)
		ft_outils("pipe errore", 1);
	pid1 = fork();
	if (pid1 == 0)
	{
		ft_prosses(t[1], av, env, 1);
		exit(0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		ft_prosses(t[0], av, env, 2);
		exit(0);
	}
	close(t[0]);
	close(t[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	printf("\n\n--done--\n\n");
}
