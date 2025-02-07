/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:15 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/28 19:03:59 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len,
		size_t *x)
{
	size_t	i;
	size_t	s1;

	i = 0;
	s1 = ft_strlen(needle);
	if (!haystack && len == 0)
		return (NULL);
	if (s1 == 0)
		return ((char *)haystack);
	while (haystack[i] && i + s1 <= len)
	{
		if (haystack[i] == needle[0])
		{
			if (ft_strncmp(haystack + i, needle, s1) == 0)
				return (*x = i, (char *)(haystack + i));
		}
		i++;
	}
	return (NULL);
}

										// test 1 :

// int	main(void)
// {
// 	int		fd;
// 	char	*t;
// 	char	*k;
// 	char	*tmp;
// 	char	*tmp1;
// 	char	*tmp2;
// 	char	*tmp3;
// 	size_t	i;
// 	size_t	j;
// 	size_t	a;
// 	size_t	x;
// 	int		z;

// 	tmp1 = "candidates";
// 	tmp2 = "12345678901234567890";
// 	i = 1;
// 	fd = open("./a.txt", O_RDWR | O_CREAT);
// 	t = ft_strdup("");
// 	printf("\n--------------------------------------------\n");
// 	while (1)
// 	{
// 		j = 0;
// 		k = get_next_line(fd);
// 		if (!k || !k[0])
// 			break ;
// 		if (i == 4)
// 		{
// 			x = 0;
// 			tmp = ft_strnstr(k, tmp1, ft_strlen(k), &x);
// 			if (tmp)
// 			{
// 				if (ft_strlen(tmp2) <= ft_strlen(tmp1))
// 				{
// 					while (j < ft_strlen(tmp2))
// 					{
// 						tmp[j] = tmp2[j];
// 						j++;
// 					}
// 					while (j < ft_strlen(tmp1))
// 					{
// 						tmp[j] = ' ';
// 						j++;
// 					}
// 				}
// 				else
// 				{
// 					tmp3 = malloc(ft_strlen(k) + ft_strlen(tmp2)
// 							- ft_strlen(tmp1) + 1);
// 					while (j < x)
// 					{
// 						tmp3[j] = k[j];
// 						j++;
// 					}
// 					a = j + ft_strlen(tmp1);
// 					z = 0;
// 					while (z < ft_strlen(tmp2))
// 					{
// 						tmp3[j] = tmp2[z];
// 						j++;
// 						z++;
// 					}
// 					while (k[a])
// 					{
// 						tmp3[j] = k[a];
// 						j++;
// 						a++;
// 					}
// 					tmp3[j] = '\0';
// 					free(k);
// 					k = tmp3;
// 				}
// 			}
// 		}
// 		t = ft_strjoin(t, k);
// 		i++;
// 	}
// 	printf("%s", t);
// 	printf("\n--------------------------------------------\n");
// }

										// test 2 :

// int	main(void)
// {
// 	int		fd;
// 	char	*k;
// 	char	*t;
// 	char	*tmp;
// 	char	*tmp2;
// 	size_t	i;
// 	size_t	j;

// 	tmp2 = "hello";
// 	j = 0;
// 	fd = open("./a.txt", O_RDWR);
// 	t = ft_strdup("");
// 	printf("\n--------------------------------------------\n");
// 	while (1)
// 	{
// 		i = 0;
// 		k = get_next_line(fd);
// 		if (!k || !k[0])
// 			break ;
// 		if (j < 3 || j >= 7 || j == 5)
// 		{
// 			tmp = ft_strnstr(k, "candidates", ft_strlen(k));
// 			while (i < ft_strlen(tmp2))
// 			{
// 				tmp[i] = tmp2[i];
// 				i++;
// 			}
// 			while (i < ft_strlen("candidates"))
// 			{
// 				tmp[i] = ' ';
// 				i++;
// 			}
// 		}
// 		t = ft_strjoin(t, k);
// 		j++;
// 	}
// 	printf("%s", t);
// 	printf("\n--------------------------------------------\n");
// }
