/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:16:49 by noctis            #+#    #+#             */
/*   Updated: 2025/02/19 17:41:14 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int	main(int c, char **ar, char **env)
{
	int (**p), (i = 0);
	if (c != 5 || !env || !*env)
		ft_exit("Error: line 21");
	p = ft_pipe(c);
    ft_prosses(c-3,ar,env,p);
    
	return (0);
}

void	ft_prosses(int c, char **ar, char **env, int **p,)
{
    int(fd1), (fd2),(i = 0);
    pid_t	pid;
    fd1 = ft_open(ar[1], 1);
	fd2 = ft_open(ar[4], 2);

    while (i < c - 3)
	{
		pid = fork();
		if (pid < 0)
			ft_exit("Error: line29");
		else if (pid < 0)
			ft_prosses(c - 3, ar, env, p fd1, fd2);
		waitpid(pid, NULL, 0);
		i++;
	}
    
	close(fd1);
	close(fd2);
}

char	*ft_pipe(int c)
{
	int(i = 0), (**p);
	p = malloc((c - 3 - 1) * sizeof(int *));
	if (!p)
		ft_exit("Error: line 34");
	while (i < c - 3 - 1)
	{
		p[i] = malloc(2 * sizeof(int));
		if (!p[i])
		{
			while (i >= 0)
				free(p[i--]);
			free(p);
			ft_exit("Error: line 43");
		}
		if (pipe(p[i]) == -1)
		{
			while (i >= 0)
				free(p[i--]);
			free(p);
			ft_exit("Error: line 46");
		}
		i++;
	}
	return (p);
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			ft_exit("Error: access file1");
		fd = open(t, O_RDONLY);
		if (fd == -1)
			ft_exit("Error: fd1 > -1");
	}
	else
	{
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_exit("Error: fd2 > -1");
	}
	return (fd);
}

void	ft_exit(char *t)
{
	ft_printf(" \n ---> %s \n", t);
	exit(EXIT_FAILURE);
}
