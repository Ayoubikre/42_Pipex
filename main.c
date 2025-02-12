/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:46:07 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/12 01:17:32 by noctis           ###   ########.fr       */
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
char	*ft_fix_path(char *cmd, char **env)
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
		exit(1);
	i = 0;
	free(tmp);
	while (t[i])
	{
		tmp = ft_strjoin(t[i], "/");
		tmp = ft_strjoin(tmp, cmd);
		if (!tmp)
			exit(0);
		if (access(tmp, R_OK) != -1)
		{
			j = 1;
			break ;
		}
	}
	if (j == 0)
		exit(0);
	return (tmp);
}

void	ft_process(int c, char **ar, char **env, int pip_arr[2])
{
	int		fd1;
	char	**cmd;
	char	*path;

	fd1 = open(ar[1], O_RDONLY);
	if (fd1 == -1)
		ft_exit("failed fd");
	dup2(fd1, STDIN_FILENO);
	dup2(pip_arr[1], STDOUT_FILENO);
	close(fd1);
	close(pip_arr[1]);
	cmd = ft_split(ar[3], ' ');
	if (!cmd)
		exit(0);
	path = ft_fix_path(cmd[0], env);
	if (!path)
		exit(0);
	
	execve(path, cmd, env);
	ft_printf("\n -- done2 -- \n");
	ft_exit("failed execve");
}

int	main(int c, char **ar, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pip_arr[2];

	// int		i=0;
	// atexit(leaks);
	if (c != 3)
		ft_exit("failed");
	else
	{
		if (pipe(pip_arr) == -1)
			ft_exit("failed pipe");
		pid1 = fork();
		if (pid1 < 0)
			ft_exit("failed fork");
		if (pid1 == 0)
		{
			ft_process(c, ar, env, pip_arr);
		}
		// pid2 = fork();
		// if (pid2 < 0)
		// 	ft_exit("failed");
		// if (pid2 == 0)
		// {
		// 	path = ft_fix_path(env);
		// }
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