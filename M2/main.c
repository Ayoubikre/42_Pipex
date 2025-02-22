/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:24 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/22 21:33:42 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
 
int	main(int c, char **ar, char **env)
{
	atexit(leaks);
	int		i;
	t_list2	data;

	i = 0;
	if (c < 5 || !env || !*env)
		ft_exit("error: line 19");
	ft_initialize(c, ar, &data);
	ft_process(c, ar, env, &data);
	while (i < c - 3)
	{
		wait(NULL);
		i++;
	}
	return (0);
}

void	ft_exit(char *t)
{
	perror(t);
	exit(EXIT_FAILURE);
}

void	leaks(void)
{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
}
