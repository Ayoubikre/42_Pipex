/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:17:47 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/25 04:21:58 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_process(int c, char **ar, char **env, t_list2 *data)
{
	pid_t	pid;
	int		i;

	while (data->i < c - 3)
	{
		i = data->i;
		pid = fork();
		if (pid < 0)
			(unlink(ar[c - 1]), perror("process Error: line 40"), exit(1));
		if (pid == 0)
		{
			ft_dup(c, data);
			ft_close(c, data);
			ft_execve(ar[i + 2], env);
		}
		if (i > 0)
			close(data->pi[i - 1][0]); // read
		if (i < c - 3 - 1)
			close(data->pi[i][1]); // write
		data->i += 1;
	}
}

void	ft_dup(int c, t_list2 *data)
{
	int	i;

	i = data->i;
	if (data->i == 0)
		dup2(data->fd1, STDIN_FILENO);
	else
		dup2(data->pi[i - 1][0], STDIN_FILENO);
	if (data->i == c - 3 - 1)
		dup2(data->fd2, STDOUT_FILENO);
	else
		dup2(data->pi[i][1], STDOUT_FILENO);
}

void	ft_close(int c, t_list2 *data)
{
	int	i;

	i = 0;
	while (i < c - 3 - 1)
	{
		close(data->pi[i][0]);
		close(data->pi[i][1]);
		i++;
	}
	close(data->fd1);
	close(data->fd2);
}
