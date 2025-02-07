/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:54:23 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/08 00:38:25 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);

char	*ft_fix_str(char *str, int i);
char	*ft_get_line(char *str, int *i);
char	*ft_get_str(int fd, char *str);

char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strchr2(const char *s, int c);
size_t	ft_strlen2(const char *s);
char	*ft_strdup2(const char *s1);

#endif