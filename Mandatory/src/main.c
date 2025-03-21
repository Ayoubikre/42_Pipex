/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:24 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/21 13:44:38 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	main(int c, char **ar, char **env)
{
	int		i;
	t_list2	data;

	if (c != 5 || !env || !*env)
		(perror("main Error: line 21"), exit(1));
	ft_initialize(c, ar, &data);
	ft_process(c, ar, env, &data);
	i = 0;
	while (i < c - 3)
	{
		wait(NULL);
		i++;
	}
	ft_close(c, &data);
	i = 0;
	while (i < c - 3 - 1)
		free(data.pi[i++]);
	free(data.pi);
	return (0);
}



/*

4/ leak function
	atexit(leaks);
	void	leaks(void)
	{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
	}

5/exit status function .

6/		printf("\n child [%d] pid is -> %d \n", i + 1, pid);
	printf("\n parent pid is -> %d \n",getpid());


fix this
	➜  41_Pipex git:(master) ✗ ls < f/z1.txt | wc -l >> out
	➜  41_Pipex git:(master) ✗ ./pipex f/z1.txt ls "wc -l" out

and this
	rm -rf herdoc tmpfile , unlik befor or smthing	

	
	perror infile not found and skip first cmd

	

*/