/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii                                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noctis <noctis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:51:03 by noctis            #+#    #+#             */
/*   Updated: 2025/02/15 20:49:45 by noctis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	ft_strlen(char *t)
{
	int	i;

	i = 0;
	while (t[i])
		i++;
	return (i);
}
char	*ft_strdup(char *str)
{
	int		s;
	int		i;
	char	*t;

	i = 0;
	s = ft_strlen(str);
	t = malloc(s + 1);
	if (!t)
		return (NULL);
	while (i < s)
	{
		t[i] = str[i];
		i++;
	}
	t[i] = '\0';
	return (t);
}

int	ft_check(char *t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		if (t[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *t1, char *t2)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	j = 0;
	t = malloc(ft_strlen(t1) + ft_strlen(t2) + 1);
	if (!t)
		return (free(t1),free(t2), NULL);
	while (t1[i])
	{
		t[i] = t1[i];
		i++;
	}
	while (t2[j])
	{
		t[i + j] = t2[j];
		j++;
	}
	t[i + j] = '\0';
	return (free(t1), t);
}

char	*ft_g_l(int fd, char *str)
{
	int		f;
	char	*t;

	f = 1;
	if (!str)
		str = ft_strdup("");
	t = malloc(BUFFER_SIZE + 1);
	if (!t)
		return (free(str), NULL);
	while (f != 0)
	{
		f = read(fd, t, BUFFER_SIZE);
        if ((f == -1) || (f == 0 && (!str || !str[0])))
            return (free(t), free(str),str=NULL, NULL);
        t[f]='\0';
		str = ft_strjoin(str, t);
		if (!str)
			return (NULL);
		if (ft_check(str) == 1)
			break ;
	}    
	return (free(t),str);
}

char	*ft_t_f(char *str, int *i)
{
	int		j;
	char	*t;

	j = 0;
	while (str[(*i)] && str[(*i)] != '\n')
		(*i)++;
	(*i)++;
	t = malloc((*i) + 1);
	if (!t)
		return (free(str), NULL);
	while (j < (*i))
	{
		t[j] = str[j];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_s_f(char *str,char *str1)
{
	char	*t;
    int i=0;
    int s=ft_strlen(str);

	t = malloc(s + 1);
	if (!t)
		return (free(str1),str1=NULL,NULL);
    while(i<s)
    {
        t[i]=str[i];
        i++;
    }
    t[i]='\0';
	return (free(str1),str1=NULL,t);
}

char	*get_next_line(int fd)
{
	char		*t;
	static char	*str;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (free(str), NULL);
	str = ft_g_l(fd, str);
	if (!str)
		return (NULL);
	t = ft_t_f(str, &i);
	if (!t)
		return (NULL);
	str = ft_s_f(str+i,str);
	if (!str)
		return (free(t),NULL);
	return (t);
}

// int	main(void)
// {
// 	int fd = open("../test", O_RDWR);
// 	int i = 0;

// 	while (i < 12)
// 	{
// 		char *t = get_next_line(fd);
// 		if (!t)
// 			return (0);
// 		printf("%s", t);
// 		free(t);
// 		i++;
// 	}
// }
