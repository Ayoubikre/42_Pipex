/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:22 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/22 20:01:06 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_initialize(int c, char **ar, t_list2 *data)
{
	data->i = 0;
	data->c = c - 3;
	data->fd1 = ft_open(ar[1], 1);
	data->fd2 = ft_open(ar[c - 1], 2);
	data->pi = ft_pipe(c); // we didnt close fds
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			ft_exit("initialze Error: line 31");
		fd = open(t, O_RDONLY);
		if (fd == -1)
			ft_exit("initialze Error: line 34");
	}
	else
	{
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			ft_exit("initialze Error: line 40");
	}
	return (fd);
}

int	**ft_pipe(int c)
{
	int (s), (**pi), i = 0;
	s = c - 3 - 1;
	pi = malloc(sizeof(int *) * s);
	if (!pi)
		ft_exit("initialze Error: line 51");
	while (i < s)
	{
		pi[i] = malloc(sizeof(int) * 2);
		if (!pi[i])
		{
			while (i-- >= 0)
				free(pi[i]);
			free(pi);
			ft_exit("initialze Error: line 60");
		}
		if (pipe(pi[i]) == -1)
		{
			while (i-- >= 0)
				free(pi[i]);
			free(pi);
			ft_exit("initialze Error: line 67");
		}
		i++;
	}
	return (pi);
}
