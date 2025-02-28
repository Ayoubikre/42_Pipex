/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:27 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/28 15:47:46 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../42_Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_list2
{
	int	i;
	int	c;
	int	fd1;
	int	fd2;
	int	**pi;
}		t_list2;

int		main(int c, char **ar, char **env);

void	ft_initialize(int c, char **ar, t_list2 *data);
int		ft_open(char *t, int f);
int		**ft_pipe(int c);
void	ft_free(char **t);

void	ft_process(int c, char **ar, char **env, t_list2 *data);
void	ft_dup(int c, t_list2 *data);
void	ft_close(int c, t_list2 *data);

void	ft_execve(char *t, char **env, t_list2 *data);
char	*ft_path(char *cmd, char **env);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
int		ft_check(char *t);

char	**ft_split2(char const *s, char c);
void leaks();

#endif

/*

1/ change i decremtation in ft_pipe
 			while (i >= 0)
				free(pi[i--]);
			free(pi);

2/add free [pi]in exeve !cmd and !path and !exeve:
			i= 0,j=1;

			while (i<j)
				{free(data->pi[i]); i++;}
			free(data->pi);

3/close fds if pipes fiald ?? and other things , end free pipe in all exits

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

*/