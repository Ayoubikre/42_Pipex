/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:06 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/25 04:03:56 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	f;
	size_t	x;
	size_t	count;

	i = 0;
	f = 0;
	x = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\'')
			x = !x;
		if (s[i] != c && f == 0 && x == 0)
		{
			count++;
			f = 1;
		}
		else if (s[i] == c)
			f = 0;
		i++;
	}
	return (count);
}

static void	ft_filter(const char *s, char c, size_t *i)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
}

static char	*ft_copy(const char *s, char c, size_t *i)
{
	size_t	j;
	size_t	k;
	size_t	x;
	char	*t;

	x = 0;
	k = 0;
	j = *i;
	while (s[j] && (s[j] != c || x == 1))
	{
		if (s[j] == '\'')
			x = !x;
		j++;
	}
	t = malloc((j - *i + 1) * 1);
	if (!t)
		return (NULL);
	while (*i < j)
	{
		if (s[*i] != '\'')
			t[k++] = s[*i];
		(*i)++;
	}
	t[k] = '\0';
	return (t);
}

char	**ft_split2(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**t;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	t = malloc((ft_count(s, c) + 1) * sizeof(char *));
	if (!t)
		return (NULL);
	while (k < ft_count(s, c))
	{
		ft_filter(s, c, &i);
		t[k] = ft_copy(s, c, &i);
		if (!t[k])
		{
			ft_free(t);
			return (NULL);
		}
		k++;
	}
	t[k] = NULL;
	return (t);
}
