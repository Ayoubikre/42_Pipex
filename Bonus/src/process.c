/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:17:47 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/26 05:56:17 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_process(int c, char **ar, char **env, t_list2 *data)
{
	pid_t	pid;
	int		i;

	while (data->i < data->c)
	{
		i = data->i;
		pid = fork();
		if (pid < 0)
			(unlink(ar[c - 1]), perror("process Error: line 1"), exit(1));
		if (pid == 0)
		{
			ft_dup(data);
			ft_close(data);
			if (data->f == 1)
				ft_execve(ar[i + 3], env);
			else
				ft_execve(ar[i + 2], env);
		}
		if (i > 0)
			close(data->pi[i - 1][0]);
		if (i < data->c - 1)
			close(data->pi[i][1]);
		data->i += 1;
	}
}

void	ft_dup(t_list2 *data)
{
	int	i;

	i = data->i;
	if (data->i == 0)
		dup2(data->fd1, STDIN_FILENO);
	else
		dup2(data->pi[i - 1][0], STDIN_FILENO);
	if (data->i == data->c - 1)
		dup2(data->fd2, STDOUT_FILENO);
	else
		dup2(data->pi[i][1], STDOUT_FILENO);
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
