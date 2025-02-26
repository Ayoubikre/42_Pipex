/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:24 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/26 07:19:33 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	main(int c, char **ar, char **env)
{
	int		i;
	t_list2	data;

	atexit(leaks);
	if (c != 5 || !env || !*env)
		(perror("main Error: line 22"), exit(1));
	ft_initialize(c, ar, &data);
	ft_process(c, ar, env, &data);
	ft_close(c, &data);
	i = 0;
	while (i < c - 3)
	{
		wait(NULL);
		i++;
	}
	i = 0;
	while (i < c - 3 - 1)
		free(data.pi[i++]);
	free(data.pi);
	return (0);
}

void	leaks(void)
{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
}
