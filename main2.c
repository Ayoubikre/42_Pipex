/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 02:40:49 by noctis            #+#    #+#             */
/*   Updated: 2025/02/17 02:21:26 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int ft_outils(char t,int f)
{
    if(f==1)
    {
        perror(t);
        exite(1);
    }
    else if (f==2)
    {
        if (accesse(t,R_OK)==-1)
            ft_outil("cant fid the file",1);
    }
    else
    {
        
    }
}

int ft_open(char *t)
{
    if(ft_outils(t,2)==-1)
        ft_outils("cat find files",1);    
}

void ft_prosses(int t[2],char **av,char **env, int f)
{
    if(f==1)
    {
        int fd=ft_open(av[1],f);
        dup2(fd,STDIN_FILENO);
        dup2(t[2]=STDOUT_FILENO);
        close (fd);
        closse (t[2]);
        ft_execve(char av[2],char **env);
    }
    else
    {
        int fd=ft_open(av[4],f);
        dup2(fd,STDOUT_FILENO);
        dup2(t[1],STDIN_FILENO);
        close (fd);
        close(t[1]);
        ft_execve(char av[3],char **env);
    }
}

int main(int c, char **av, char **env)
{
    pid_t pid1;
    pid_t pid2;
    int t[2];
    
    if(pipe(t)==-1)
        return 0;
    pid1=fork();
    if(pid==0)
    {
        ft_prosses(t,av,env,1);
    }
    pid2=fork();
    if(pid2==0)
    {
        ft_prosses(t,av,env,2);
    }
    
    

}