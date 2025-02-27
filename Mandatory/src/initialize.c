/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:22 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/27 07:22:03 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_initialize(int c, char **ar, t_list2 *data)
{
	data->i = 0;
	data->c = c - 3;
	data->fd2 = ft_open(ar[c - 1], 2);
	data->fd1 = ft_open(ar[1], 1);
	data->pi = ft_pipe(c);
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			return (ft_open("/dev/null", 3));
		fd = open(t, O_RDONLY);
		if (fd == -1)
			return (ft_open("/dev/null", 3));
	}
	else if (f == 2)
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(t, O_RDONLY);
	if (fd == -1)
		(perror("initialze Error: line 41"), exit(1));
	return (fd);
}

int	**ft_pipe(int c)
{
	int (s), (**pi), i = 0;
	s = c - 3 - 1;
	pi = malloc(sizeof(int *) * s);
	if (!pi)
		(perror("initialze Error: line 51"), exit(1));
	while (i < s)
	{
		pi[i] = malloc(sizeof(int) * 2);
		if (!pi[i])
		{
			while (i-- >= 0)
				free(pi[i]);
			free(pi);
			(perror("initialze Error: line 60"), exit(1));
		}
		if (pipe(pi[i]) == -1)
		{
			while (i-- >= 0)
				free(pi[i]);
			free(pi);
			(perror("initialze Error: line 67"), exit(1));
		}
		i++;
	}
	return (pi);
}

void	ft_free(char **t)
{
	size_t	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
}
