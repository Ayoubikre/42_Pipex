/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:01 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/11 01:40:25 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	leaks(void)
// {
// 	system("leaks a");
//  atexit(leaks);
// }

// int	main(int c, char **t)
// {
// 	int			fd;
// 	int			i;
// 	int			j;
// 	const char	*path_j;
// 	const char	**path;
// 	char		**cmd;
// 	char		**envp;

// 	// int		x;
// 	if (c == 3)
// 	{
// 		i = 0;
// 		j = 0;
// 		// x = 0;
// 		path = (const char **)ft_split("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin",':');
// 		cmd = ft_split(t[2], ' ');
// 		envp = NULL;
// 		if (access(t[1], F_OK) != 0)
// 		{
// 			printf(" /....../ \n");
// 			exit(0);
// 		}
// 		fd = open(t[1], O_RDWR);
// 		if (fd < 0)
// 		{
// 			printf(" /....../ \n");
// 			exit(0);
// 		}
// 		while (path[i])
// 		{
// 			path_j = (const char *)ft_strjoin(path[i], cmd[0]);
// 			if (access(path_j, F_OK) == 0)
// 			{
// 				j = 1;
// 				break ;
// 			}
// 			free((char *)path_j);
// 			i++;
// 		}
// 		if (j == 0)
// 		{
// 			free(path); // stiil ned to free all the table
// 			exit(0);
// 		}
// 		execve(path_j, cmd, envp);
// 	}
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int	main(int c, char **t)
{
	int			fd;
	int			i;
	// int			j;
	char		*path_j;
	char		**path;
	char		**cmd;
	extern char **environ; // Get system environment variables

	if (c == 3)
	{
		i = 0;
		// j = 0;
		path = ft_split("/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin", ':');
		cmd = ft_split(t[2], ' ');

		// Check if file exists
		if (access(t[1], F_OK) != 0)
		{
			perror("File does not exist");
			// free_tab(path);
			// free_tab(cmd);
			exit(EXIT_FAILURE);
		}

		// Try opening file
		fd = open(t[1], O_RDWR);
		if (fd < 0)
		{
			perror("open");
			// free_tab(path);
			// free_tab(cmd);
			exit(EXIT_FAILURE);
		}
		close(fd);

		// Search for command in paths
		while (path[i])
		{
			path_j = ft_strjoin(path[i], "/");
			char *full_cmd = ft_strjoin(path_j, cmd[0]);
			free(path_j);

			if (access(full_cmd, F_OK) == 0)
			{
				// j = 1;
				execve(full_cmd, cmd, environ);
				perror("execve");
				// free(full_cmd);
				// free_tab(path);
				// free_tab(cmd);
				exit(EXIT_FAILURE);
			}
			free(full_cmd);
			i++;
		}

		// Cleanup if command not found
		// free_tab(path);
		// free_tab(cmd);
		fprintf(stderr, "Command not found: %s\n", cmd[0]);
		exit(EXIT_FAILURE);
	}
	return (0);
}
