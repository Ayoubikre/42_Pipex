/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 02:16:49 by noctis            #+#    #+#             */
/*   Updated: 2025/02/19 02:53:51 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t.h"

int	main(int c, char **ar, char **env)
{
	int (fd1), (fd2), (**pipe);
	if (c != 5 || !env || !*env)
		ft_exit("Error: argv count");
	fd1 = ft_open(ar[1], 1);
	fd2 = ft_open(ar[4], 2);
	pipe = ft_creat_pipe(c);
    
}

int ft_open(char *t,f)
{
    int fd;
    
    if(f=1)
    {
        if(access(t, F_OK)== -1 || access(t, R_OK)==-1)
            ft_exit("Error: access file");
        fd=open(t, O_RDONLY);
        if(fd==-1)
            ft_exit("Error: open call");
    }else
    {
        fd=open("exone 11")
    }
}

void	ft_exit(char *t)
{
	ft_printf(" \n ---> %s \n", t);
	exit(EXIT_FAILURE);
}
