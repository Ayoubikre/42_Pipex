/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:27 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/28 15:48:44 by noctis           ###   ########.fr       */
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
	int	f;
	int	fd1;
	int	fd2;
	int	**pi;
}		t_list2;

int		main(int c, char **ar, char **env);

void	ft_initialize(int c, char **ar, t_list2 *data);
int		ft_open(char *t, int f);
int		**ft_pipe(t_list2 *data);
void	ft_free(char **t);

void	ft_process(int c, char **ar, char **env, t_list2 *data);
void	ft_dup(t_list2 *data);
void	ft_close(t_list2 *data);

void	ft_execve(char *t, char **env, t_list2 *data);
char	*ft_path(char *cmd, char **env);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
int		ft_check(char *t);

void	ft_read(char **ar, t_list2 *data);
int		ft_check2(char *t);
int		ft_check3(char *t1, char *t2);

char	**ft_split2(char const *s, char c);

#endif

/*

1/ do things in mandatory and j = data->c - 1 so change th data structure

2/ free in hardc :
	if (ft_check3(t, ar[2]) == 1)
			{free(t);break ;}

3/ free str in get next line
	
	if (str && !str[0])  
    {
        free(str);
        str = NULL;
    }


*/