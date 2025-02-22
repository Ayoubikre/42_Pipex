/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 03:45:43 by noctis            #+#    #+#             */
/*   Updated: 2025/02/22 13:48:57 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*ft_fix_path(char *cmd, char **env)
{
	int		i;
	char	**t;
	char	*tmp;
	char	*path;

	t = ft_fix_path2(env);
	if (!t)
		return (NULL);
	i = 0;
	while (t[i])
	{
		tmp = ft_strjoin(t[i], "/");
		if (!tmp)
			return (ft_free(t), NULL);
		path = ft_strjoin(tmp, cmd);
		if (!path)
			return (ft_free(t), free(tmp), NULL);
		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
			return (ft_free(t), free(tmp), path);
		free(tmp);
		free(path);
		i++;
	}
	return (ft_free(t), NULL);
}

char	**ft_fix_path2(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) == NULL)
		i++;
	if (!env[i])
		return (NULL);
	return (ft_split(env[i] + 5, ':'));
}

void	ft_free(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
	t = NULL;
}

void	ft_exit(char *t)
{
	perror(t);
	exit(1);
}

void	leaks(void)
{
	char	command[50];

	sprintf(command, "leaks %d", getpid());
	system(command);
}
