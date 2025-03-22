/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:22 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/22 21:28:06 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_initialize(int c, char **ar, t_list2 *data)
{
	data->i = 0;
	data->c = c - 3;
	data->fd2 = ft_open(ar[c - 1], 2);
	data->fd1 = ft_open(ar[1], 1);
	data->pi = ft_pipe(data);
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			return (perror("initialze Error: line 31"), -1);
		fd = open(t, O_RDONLY);
		if (fd == -1)
			return (perror("initialze Error: line 34"), -1);
	}
	else if (f == 2)
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(t, O_RDONLY);
	if (fd == -1)
		(perror("initialze Error: line 41"), exit(1));
	return (fd);
}

int	**ft_pipe(t_list2 *data)
{
	int (s), (**pi), i = 0;
	s = data->c - 1;
	pi = malloc(sizeof(int *) * s);
	if (!pi)
		(perror("initialze Error: line 51"), exit(1));
	while (i < s)
	{
		pi[i] = malloc(sizeof(int) * 2);
		if (!pi[i])
		{
			while (i >= 0)
				free(pi[i--]);
			free(pi);
			(perror("initialze Error: line 60"), exit(1));
		}
		if (pipe(pi[i]) == -1)
		{
			while (i >= 0)
				free(pi[i--]);
			free(pi);
			(perror("initialze Error: line 67"), exit(1));
		}
		i++;
	}
	return (pi);
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

void	ft_free2(int **t, int c)
{
	int	i;

	i = 0;
	while (i < c)
	{
		free(t[i]);
		i++;
	}
	free(t);
}
