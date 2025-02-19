/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.h                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:18:42 by noctis            #+#    #+#             */
/*   Updated: 2025/02/19 02:37:17 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_H
#define T_H

# include "./42_Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
//---------
# include <stdio.h>
# include <string.h>
# include <errno.h>

int main(int c, char **ar, char **env);
void ft_exit(char *t);


#endif