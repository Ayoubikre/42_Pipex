/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 18:30:39 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/18 04:11:00 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../42_Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
//---------
# include <stdio.h>
# include <string.h>

int		main(int c, char **av, char **env);
void	ft_prosses(int t[2], char **av, char **env, int f);
int		ft_open(char *t, int f);
void	ft_execve(char *ar, char **env);

char	*ft_fix_path(char *cmd, char **env);
char	**ft_fix_path2(char **env);
void	ft_free(char **t);
void	ft_exit(char *t);

void	leaks(void);
// fix header name noctis

#endif