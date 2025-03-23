/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 04:16:10 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/23 12:44:52 by aakritah         ###   ########.fr       */
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
		if (!t || ft_check3(t, ar[2]) == 1)
		{
			free(t);
			break ;
		}
		if (write(data->pi_herdoc[1], t, ft_strlen(t)) == -1)
			(perror("herdoc Error: line 31"), free(t), exit(1));
		free(t);
	}
}

int	ft_check2(char *t)
{
	if (ft_strnstr(t, "here_doc", ft_strlen("here_doc")) != NULL
		&& (ft_strlen(t) == ft_strlen("here_doc")))
		return (1);
	return (0);
}

int	ft_check3(char *t, char *ar)
{
	if ((ft_strnstr(t, ar, ft_strlen(ar)) != NULL) && (ft_strlen(t)
			- 1 == ft_strlen(ar)))
		return (1);
	return (0);
}
