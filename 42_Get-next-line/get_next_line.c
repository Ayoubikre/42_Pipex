/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:30:31 by aakritah          #+#    #+#             */
/*   Updated: 2024/11/27 21:54:25 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fix_str(char *str, int i)
{
	char	*t;

	t = ft_strdup(str + i);
	if (!t)
		return (free(str), str = NULL, NULL);
	return (free(str), str = NULL, t);
}

char	*ft_get_line(char *str, int *i)
{
	char	*t;
	int		j;

	while (str[*i] && str[*i] != '\n')
		(*i)++;
	if (str[*i] == '\n')
		(*i)++;
	t = malloc(*i + 1);
	if (!t)
		return (NULL);
	j = 0;
	while (j < *i)
	{
		t[j] = str[j];
		j++;
	}
	t[j] = '\0';
	return (t);
}

char	*ft_get_str(int fd, char *str)
{
	char	*buffer;
	ssize_t	rs;

	if (!str)
		str = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), str = NULL, NULL);
	rs = 1;
	while (rs > 0)
	{
		rs = read(fd, buffer, BUFFER_SIZE);
		if ((rs == -1) || (rs == 0 && (!str || !str[0])))
			return (free(buffer), buffer = NULL, free(str), str = NULL, NULL);
		buffer[rs] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (free(buffer), buffer = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (free(str), str = NULL, NULL);
	str = ft_get_str(fd, str);
	if (!str)
		return (NULL);
	line = ft_get_line(str, &i);
	if (!line)
		return (free(str), str = NULL, NULL);
	str = ft_fix_str(str, i);
	return (line);
}
