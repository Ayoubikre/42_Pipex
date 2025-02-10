/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:01 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/10 16:20:59 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	leaks(void)
// {
// 	system("leaks a");
//  atexit(leaks);
// }

int	main(int c, char **t)
{
	int		fd;
	int		i;
	int		j;
	// int		x;
	const char	path_t;
	const char	**path;
	const char	**cmd;
	const char	*envp;

	if (c == 2)
	{
		i = 0;
		j = 0;
		// x = 0;
		path = (const char ** )ft_split("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",':');
		cmd =(const char ** )f ft_split(t[2], ' ');
		envp = NULL;
		if (access(t[1], F_OK) != 0)
			exit(0);
		fd = open(t[1], O_RDWR);
		if (fd < 0)
			exit(0);
		while (path[i])
		{
			path_t = (const char * )ft_strjoin(path[i], cmd[0]);
			if (access(path_t, F_OK) == 0)
			{
				j = 1;
				break ;
			}
			free(path_t)
		}
		if (j == 0)
		{
			free(path); // stiil ned to free all the table
			exit(0);
		}
		execve(path_t, cmd, envp);
	}
	return (0);
}
