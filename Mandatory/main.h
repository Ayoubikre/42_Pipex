/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:58:27 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/23 12:54:03 by aakritah         ###   ########.fr       */
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
int		**ft_pipe(t_list2 *data);
void	ft_free(char **t);
void	ft_free2(int **t, int c);

void	ft_process(int c, char **ar, char **env, t_list2 *data);
void	ft_dup(t_list2 *data);
void	ft_close(t_list2 *data);

void	ft_execve(char *t, char **env, t_list2 *data);
char	*ft_path(char *cmd, char **env);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
int		ft_check(char *t);

char	**ft_split2(char const *s, char c);

#endif
