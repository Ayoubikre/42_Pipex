/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:16:10 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/26 07:36:10 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_read(char **ar, t_list2 *data)
{
	char	*t;

	while (1)
	{
		write(1, "heredoc> ", 9);
		t = get_next_line(0);
		if (!t)
			(perror("main Error: line 23"), exit(1));
		if ((ft_strnstr(t, ar[2], ft_strlen(ar[2])) != NULL)
			&& (ft_strlen(ar[2]) == ft_strlen(t) - 1))
			break ;
		write(data->fd1, t, ft_strlen(t));
		free(t);
	}
}

int	ft_check2(char *t)
{
	if (ft_strnstr(t, "here_doc", ft_strlen("here_doc")) != NULL)
		return (1);
	return (0);
}
