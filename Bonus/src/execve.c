/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 17:21:25 by aakritah          #+#    #+#             */
/*   Updated: 2025/03/23 12:38:05 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ft_execve(char *t, char **env, t_list2 *data)
{
	char	*pathname;
	char	**cmd;

	cmd = ft_split2(t, ' ');
	if (!cmd || !*cmd || cmd[0][0] == '.')
		(ft_free2(data->pi, data->c - 1), ft_free(cmd),
			perror("execve Error: line 23"), exit(1));
	if (ft_check(cmd[0]) == 0)
		pathname = ft_path(cmd[0], env);
	else
		pathname = ft_strdup(cmd[0]);
	if (!pathname)
	{
		(ft_free(cmd), ft_free2(data->pi, data->c - 1));
		(perror("execve Error: line 31"), exit(127));
	}
	execve(pathname, cmd, env);
	(ft_free2(data->pi, data->c - 1), ft_free(cmd), free(pathname));
	(perror("execve Error: line 35"), exit(126));
}

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**t;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH=", ft_strlen("PATH=")) == NULL)
		i++;
	if (!env[i])
		(perror("execve Error: line 48"), exit(127));
	t = ft_split(env[i] + 5, ':');
	if (!t)
		(perror("execve Error: line 51"), exit(1));
	i = 0;
	while (t[i])
	{
		path = ft_strjoin3(t[i], "/", cmd);
		if (!path)
			return (ft_free(t), NULL);
		if (access(path, F_OK) != -1 || access(path, X_OK) != -1)
			return (path);
		free(path);
		i++;
	}
	return (ft_free(t), NULL);
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*t;

	int (s), (i), (j), (k);
	if (!s1 || !s2 || !s3)
		return (NULL);
	s = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	t = malloc(s + 1);
	if (!t)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		t[i++] = s2[j++];
	k = 0;
	while (s3[k] != '\0')
		t[i++] = s3[k++];
	t[i] = '\0';
	return (t);
}

int	ft_check(char *t)
{
	while (*t)
	{
		if (*t == '/')
			return (1);
		t++;
	}
	return (0);
}
