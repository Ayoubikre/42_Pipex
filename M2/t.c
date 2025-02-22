# include "../42_Libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
//---------
# include <errno.h>
# include <stdio.h>
# include <string.h>
#include "t.h"



int main()
{
	int i;
	char *t="hello world this is awk ' print combined '";
	char **tmp1=ft_split(t, ' ');
	char **tmp2=ft_split2(t, ' ');

		printf("\n------------------\n");

	i=0;
	while(tmp1[i])
	{
		printf("-->  %d: %s   <--\n",i+1, tmp1[i]);
		i++;
	}
			printf("\n------------------\n");

	i=0;
	while(tmp2[i])
	{
		printf("-->  %d: %s   <--\n",i+1, tmp2[i]);
		i++;
	}
			printf("\n------------------\n");

	return 0;

}




// typedef struct s_list2
// {
// 	int	i;
// 	int c;
// 	int	fd1;
// 	int	fd2;
// 	int	**pi;
// }		t_list2;

// void	ft_execve(char *t, char **env)
// {
// 	char	*pathname;
// 	char	**cmd;

// 	cmd = ft_split(t, ' ');
// 	if (!cmd)
// 		ft_exit("execve Error: line 23");
// 	pathname = ft_path(cmd[0], env);
// 	if (pathname)
// 		ft_exit("execve Error: line 25");
// 	execve(pathname, cmd, env);
//      ft_exit("execve Error: line 27");
// }

// char	*ft_path(char *cmd, char **env)
// {
// 	int		i;
// 	char	*path;
// 	char	**t;

//     i = 0;
// 	while (env[i] || ft_strnstr(env[i], "PATH=", ft_strlen("PATH=")) == NULL)
// 		i++;
// 	if (!env[i])
// 		ft_exit("execve Error: line 40");
// 	t = ft_split(env[i] + 5, ':');
//     if (!t)
//         ft_exit("execve Error: line 43");
// 	i = 0;
// 	while (t[i])
// 	{
// 		path = ft_strjoin3(t[i], "/", cmd);
// 		if (access(path, F_OK) != -1 || access(path, X_OK) != -1)
// 		    return (path);
// 		free(path);
// 		i++;
// 	}
// 	return (NULL);
// }

// char	*ft_strjoin3(char *s1, char *s2, char *s3)
// {
// 	char	*t;

// 	int (s), (i), (j), (k);
// 	if (!s1 || !s2 || !s3)
// 		return (NULL);
// 	s = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
// 	t = malloc(s + 1);
// 	if (!t)
// 		return (NULL);
// 	i = 0;
// 	while (s1[i] != '\0')
// 	{
// 		t[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2[j] != '\0')
// 		t[i++] = s2[j++];
// 	k = 0;
// 	while (s3[k] != '\0')
// 		t[i++] = s3[k++];
// 	t[i] = '\0';
// 	return (t);
// }


// void	ft_process(int c, char **ar, char **env, t_list2 *data)
// {
// 	pid_t	pid;
// 	int		i;

// 	while (data->i < c - 3)
// 	{
// 		i = data->i;
// 		pid = fork();
// 		if (pid < 0)
// 			ft_exit("process Error: line 25");
// 		if (pid == 0)
// 		{
// 			ft_dup(c, data);
// 			ft_close(c, data);
// 			ft_execve(ar[i + 2], env);
// 		}
// 		if (i > 0)
// 			close(data->pi[i - 1][0]); // read
// 		if (i < c - 3 - 1)
// 			close(data->pi[i][1]); // write
// 		data->i += 1;
// 	}
// 	close(data->fd1);
// 	close(data->fd2);
// }

// void	ft_dup(int c, t_list2 *data)
// {
// 	int	i;

// 	i = data->i;
// 	if (data->i == 0)
// 		dup2(data->fd1, STDIN_FILENO);
// 	else
// 		dup2(data->pi[i - 1][0], STDIN_FILENO);
	
// 	if (data->i == c - 3 - 1)
// 		dup2(data->fd2, STDOUT_FILENO);
// 	else
// 		dup2(data->pi[i][1], STDOUT_FILENO);
// }

// void	ft_close(int c, t_list2 *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < c - 3 - 1)
// 	{
// 		close(data->pi[i][0]);
// 		close(data->pi[i][1]);
// 		i++;
// 	}
// 	close(data->fd1);
// 	close(data->fd2);
// }


// void	ft_initialize(int c, char **ar, t_list2 *data)
// {
// 	data->i = 0;
// 	data->c = c - 3;
// 	data->fd1 = ft_open(ar[1], 1);
// 	data->fd2 = ft_open(ar[c - 1], 2);
// 	data->pi = ft_pipe(c); // we didnt close fds
// }

// int	ft_open(char *t, int f)
// {
// 	int	fd;

// 	if (f == 1)
// 	{
// 		if (access(t, F_OK) == -1 || access(t, R_OK) == -1)
// 			ft_exit("initialze Error: line 31");
// 		fd = open(t, O_RDONLY);
// 		if (fd == -1)
// 			ft_exit("initialze Error: line 34");
// 	}
// 	else
// 	{
// 		fd = open(t, O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		if (fd == -1)
// 			ft_exit("initialze Error: line 40");
// 	}
// 	return (fd);
// }

// int	**ft_pipe(int c)
// {
// 	int (s), (**pi), i = 0;
// 	s = c - 3 - 1;
// 	pi = malloc(sizeof(int *) * s);
// 	if (!pi)
// 		ft_exit("initialze Error: line 51");
// 	while (i < s)
// 	{
// 		pi[i] = malloc(sizeof(int) * 2);
// 		if (!pi[i])
// 		{
// 			while (i-- >= 0)
// 				free(pi[i]);
// 			free(pi);
// 			ft_exit("initialze Error: line 60");
// 		}
// 		if (pipe(pi[i]) == -1)
// 		{
// 			while (i-- >= 0)
// 				free(pi[i]);
// 			free(pi);
// 			ft_exit("initialze Error: line 67");
// 		}
// 		i++;
// 	}
// 	return (pi);
// }

// int	main(int c, char **ar, char **env)
// {
// 	int		i;
// 	t_list2	data;

// 	i = 0;
// 	if (c != 5 || !env || !*env)
// 		ft_exit("error: line 19");
// 	ft_initialize(c, ar, &data);
// 	ft_process(c, ar, env, &data);
// 	while (i < c - 3)
// 	{
// 		wait(NULL);
// 		i++;
// 	}
// 	return (0);
// }

// void	ft_exit(char *t)
// {
// 	perror(t);
// 	exit(EXIT_FAILURE);
// }

// void	leaks(void)
// {
// 	char	command[50];

// 	sprintf(command, "leaks %d", getpid());
// 	system(command);
// }
