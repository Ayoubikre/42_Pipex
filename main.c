/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 18:46:07 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/11 21:47:48 by aakritah         ###   ########.fr       */
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
char	**ft_fix_path(char **env)
{
	char	**t;
	char	*tmp;
	int		i;

	i = 0;
	while (strnstr(env[i], "PATH=", ft_strlen(env[i])) == NULL)
		i++;
	tmp = ft_strdup((const char *)env[i]);
	t = ft_split((const char *)tmp + 5, ':');
	if (!t)
		exit(1);
	return (t);
}

int	main(int c, char **ar, char **env)
{
	// int		i;
	char	**path;
	// char	**cmd;
	pid_t	pid1;
	pid_t	pid2;
	int		pip_arr[2];

	// atexit(leaks);
	if (c != 3)
		ft_exit("failed");
	else
	{
		if (pipe(pip_arr) == -1)
			ft_exit("failed");
		pid1 = fork();
		if (pid1 < 0)
			ft_exit("failed");
		if (pid1 == 0)
		{
			path = ft_fix_path(env);
			printf("---\n");
		}
		pid2 = fork();
		if (pid2 < 0)
			ft_exit("failed");
		if (pid2 == 0)
		{
			path = ft_fix_path(env);
			printf("---");
		}
	}
}

// ft_printf("\n\n-----------------\n\n");
// i = 0;
// while (path[i])
// {
// 	ft_printf("--> %s\n", path[i]);
// 	i++;
// }