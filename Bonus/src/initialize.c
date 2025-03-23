/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:22 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/23 12:34:13 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_initialize(int c, char **ar, t_list2 *data)
{
	data->f = ft_check2(ar[1]);
	data->i = 0;
	if (data->f == 1)
	{
		data->c = c - 4;
		data->fd2 = ft_open(ar[c - 1], 3);
		if (pipe(data->pi_herdoc) == -1)
			(perror("initialze Error: line 24"), exit(1));
		ft_read(ar, data);
		close(data->pi_herdoc[1]);
		data->fd1 = data->pi_herdoc[0];
		data->pi = ft_pipe(data);
	}
	else
	{
		data->c = c - 3;
		data->fd2 = ft_open(ar[c - 1], 2);
		data->fd1 = ft_open(ar[1], 1);
		data->pi = ft_pipe(data);
	}
}

int	ft_open(char *t, int f)
{
	int	fd;

	if (f == 1)
	{
		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
			return (perror("initialze Error: line 46"), -1);
		fd = open(t, O_RDONLY);
		if (fd == -1)
			return (perror("initialze Error: line 49"), -1);
	}
	else if (f == 2)
		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (f == 3)
		fd = open(t, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd = open(t, O_RDWR);
	if (fd == -1)
		perror("initialze Error: line 58");
	return (fd);
}

int	**ft_pipe(t_list2 *data)
{
	int (s), (**pi), i = 0;
	s = data->c - 1;
	pi = malloc(sizeof(int *) * s);
	if (!pi)
		(perror("initialze Error: line 68"), exit(1));
	while (i < s)
	{
		pi[i] = malloc(sizeof(int) * 2);
		if (!pi[i])
		{
			while (i >= 0)
				free(pi[i--]);
			free(pi);
			(perror("initialze Error: line 77"), exit(1));
		}
		if (pipe(pi[i]) == -1)
		{
			while (i >= 0)
				free(pi[i--]);
			free(pi);
			(perror("initialze Error: line 84"), exit(1));
		}
		i++;
	}
	return (pi);
}

void	ft_free(char **t)
{
	int	i;

	i = 0;
	if (!t)
		return ;
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
	if (!t)
		return ;
	while (i < c)
	{
		free(t[i]);
		i++;
	}
	free(t);
}
