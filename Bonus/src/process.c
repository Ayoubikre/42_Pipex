/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:17:47 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/23 12:40:09 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_process(int c, char **ar, char **env, t_list2 *data)
{
	pid_t	pid;

	while (data->i < data->c)
	{
		pid = fork();
		if (pid < 0)
			(unlink(ar[c - 1]), perror("process Error: line 25"), exit(1));
		if (pid == 0)
		{
			if ((data->i == 0 && data->fd1 == -1) || (data->i == data->c - 1
					&& data->fd2 == -1))
				(ft_close(data), ft_free2(data->pi, data->c - 1), exit(1));
			(ft_dup(data), ft_close(data));
			if (data->f == 1)
				ft_execve(ar[data->i + 3], env, data);
			else
				ft_execve(ar[data->i + 2], env, data);
		}
		if (data->i > 0)
			close(data->pi[data->i - 1][0]);
		if (data->i < data->c - 1)
			close(data->pi[data->i][1]);
		data->i += 1;
	}
}

void	ft_dup(t_list2 *data)
{
	int	i;

	i = data->i;
	if (i == 0)
	{
		if (dup2(data->fd1, STDIN_FILENO) == -1)
			(perror("process Error: line 52"), exit(1));
	}
	else
	{
		if (dup2(data->pi[i - 1][0], STDIN_FILENO) == -1)
			(perror("process Error: line 58"), exit(1));
	}
	if (i == data->c - 1)
	{
		if (dup2(data->fd2, STDOUT_FILENO) == -1)
			(perror("process Error: line 62"), exit(1));
	}
	else
	{
		if (dup2(data->pi[i][1], STDOUT_FILENO) == -1)
			(perror("process Error: line 67"), exit(1));
	}
}

void	ft_close(t_list2 *data)
{
	int	i;

	i = 0;
	while (i < data->c - 1)
	{
		close(data->pi[i][0]);
		close(data->pi[i][1]);
		i++;
	}
	close(data->fd1);
	close(data->fd2);
}
