/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:46:07 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/12 13:57:38 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	leaks(void)
{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
}

void	ft_exit(char *t)
{
	perror(t);
	exit(1);
}
void	ft_free(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}

char	**ft_fix_path(char **env)
{
	char	**t;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) == NULL)
		i++;
	tmp = ft_strdup((const char *)env[i]);
	t = ft_split((const char *)tmp + 5, ':');
	if (!t)
		ft_exit("failes path split");
	return (free(tmp), t);
}

void	ft_execve(char *ar, char **env)
{
	int		i;
	char	*pathname;
	char	*tmp;
	char	**cmd;
	char	**path;

	cmd = ft_split(ar, ' ');
	if (!cmd)
		ft_exit("failes cmd split");
	path = ft_fix_path(env);
	i = 0;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		pathname = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(pathname, R_OK) != -1)
			break ;
		free(pathname);
		i++;
	}
	if (!path[i])
		ft_exit("failes to found cmd path");
	execve(pathname, cmd, env);
	ft_exit("failed axecve");
}

int	ft_file_check(char *t, int f)
{
	int	fd;

	if (access(t, R_OK) == -1)
		ft_exit("failed file not found");
	if (f == 1)
	{
		fd = open(t, O_RDONLY | O_CLOEXEC);
		if (fd == -1)
			ft_exit("failed fd");
		return (fd);
	}
	fd = open(t, O_WRONLY | O_CLOEXEC);
	if (fd == -1)
		ft_exit("failed fd");
	return (fd);
}

void	ft_process(char **ar, char **env, int pip_arr[2])
{
	int	fd;

	fd = ft_file_check(ar[1], 1);
	dup2(fd, STDIN_FILENO);
	close(fd);
	// dup2(pip_arr[1], STDOUT_FILENO);
	// close(pip_arr[1]);
	ft_execve(ar[2], env);
}

int	main(int c, char **ar, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip_arr[2];

	// int		i=0;
	atexit(leaks);
	if (c != 3)
		ft_exit("failed argv count ");
	else
	{
		// if (pipe(pip_arr) == -1)
		// 	ft_exit("failed pipe");
		pid1 = fork();
		if (pid1 < 0)
			ft_exit("failed fork");
		if (pid1 == 0)
		{
			ft_process(ar, env, pip_arr);
		}
		// pid2 = fork();
		// if (pid2 < 0)
		// 	ft_exit("failed");
		// if (pid2 == 0)
		// {
		// 	path = ft_fix_path(env);
		// }
		waitpid(pid1, NULL, WNOHANG);
		printf("\n -- done -- \n");
	}
}

// ft_printf("\n\n-----------------\n\n");
// i = 0;
// while (path[i])
// {
// 	ft_printf("--> %s\n", path[i]);
// 	i++;
// }