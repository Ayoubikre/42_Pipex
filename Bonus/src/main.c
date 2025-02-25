/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:24 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/25 07:24:29 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void ft_read(char **ar, t_list2 *data)
{
	char *t;
	t=get_next_line(0);
	if(!t)
		(perror("main Error: line 20"), exit(1));
	while(ft_strnstr(ar[2],t,ft_strlen(ar[2])) != NULL)
	{
		write(data->fd1,t,ft_strlen(t));
		t=get_next_line(0);
		if(!t)
			(perror("main Error: line 26"), exit(1));
	}
}

int	main(int c, char **ar, char **env)
{
	atexit(leaks);
	int		i;
	t_list2	data;

	if (c < 5 || !env || !*env)
		(perror("main Error: line 41"), exit(1));
	ft_initialize(c, ar, &data);
	if(data.f==1)
		ft_read(ar,&data);
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
	if(data.f==1)
		if (unlink("/tmp/infile.txt") == -1)
			(perror("main Error: line 41"), exit(1));
	return (0);
}

void	leaks(void)
{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
}

// void ft_check_fd(int c)
// {
// 	int status, last_status = 0;
// 	i = 0;
// 	while (i < c - 3)
// 	{
// 		wait(&status);
// 		if (WIFEXITED(status))
// 			last_status = WEXITSTATUS(status);
// 		else if (WIFSIGNALED(status))
// 			last_status = 128 + WTERMSIG(status);
// 		i++;
// 	}
// return (last_status);
// }
