// #include <fcntl.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/wait.h>
// #include <unistd.h>
// # include "42_Libft/libft.h"

// #define MAX_ARGS 100

// typedef struct s_pipeline
// {
// 	int	num_cmds;
// 	int	*fds;
// 	int	**pipes;
// 	int	i;
// }		t_pipeline;

// int	count_commands(int argc)
// {
// 	int	result;

// 	result = argc - 3; // Subtract program name, file1, and file2
// 	return (result);
// }

// void	ft_free(char **t)
// {
// 	int	i;

// 	i = 0;
// 	while (t[i])
// 	{
// 		free(t[i]);
// 		i++;
// 	}
// 	free(t);
// 	t = NULL;
// }

// void	ft_exit(char *t)
// {
// 	perror(t);
// 	exit(1);
// }

// void	leaks(void)
// {
// 	char	command[50];

// 	sprintf(command, "leaks %d", getpid());
// 	system(command);
// }

// char	**ft_fix_path2(char **env)
// {
// 	int	i;

// 	i = 0;
// 	while (env[i] && ft_strnstr(env[i], "PATH=", ft_strlen(env[i])) == NULL)
// 		i++;
// 	if (!env[i])
// 		return (NULL);
// 	return (ft_split(env[i] + 5, ':'));
// }

// char	*ft_fix_path(char *cmd, char **env)
// {
// 	int		i;
// 	char	**t;
// 	char	*tmp;
// 	char	*path;

// 	t = ft_fix_path2(env);
// 	if (!t)
// 		return (NULL);
// 	i = 0;
// 	while (t[i])
// 	{
// 		tmp = ft_strjoin(t[i], "/");
// 		if (!tmp)
// 			return (ft_free(t), NULL);
// 		path = ft_strjoin(tmp, cmd);
// 		if (!path)
// 			return (ft_free(t), free(tmp), NULL);
// 		if (access(path, F_OK) == 0 && access(path, X_OK) == 0)
// 			return (ft_free(t), free(tmp), path);
// 		free(tmp);
// 		free(path);
// 		i++;
// 	}
// 	return (ft_free(t), NULL);
// }



// int	**create_pipes(int num_pipes)
// {
// 	int	**pipes;
// 	int	i;

// 	pipes = malloc(num_pipes * sizeof(int *));
// 	i = 0;
// 	while (pipes && i < num_pipes)
// 	{
// 		pipes[i] = malloc(2 * sizeof(int));
// 		if (!pipes[i] || pipe(pipes[i]) == -1)
// 		{
// 			while (i-- > 0)
// 			{
// 				free(pipes[i]);
// 			}
// 			free(pipes);
// 			perror("pipe");
// 			return (NULL);
// 		}
// 		i++;
// 	}
// 	return (pipes);
// }

// void	setup_io(int i, int num_cmds, int **pipes, int *fds)
// {
// 	if (i == 0 && fds[0] != -1)
// 		dup2(fds[0], STDIN_FILENO);
// 	if (i > 0)
// 		dup2(pipes[i - 1][0], STDIN_FILENO);
// 	if (i == num_cmds - 1 && fds[1] != -1)
// 		dup2(fds[1], STDOUT_FILENO);
// 	if (i < num_cmds - 1)
// 		dup2(pipes[i][1], STDOUT_FILENO);
// }

// void	close_pipes(int **pipes, int num_pipes, int *fds)
// {
// 	int	i;

// 	i = 0;
// 	while (i < num_pipes)
// 	{
// 		close(pipes[i][0]);
// 		close(pipes[i][1]);
// 		i++;
// 	}
// 	if (fds[0] != -1)
// 		close(fds[0]);
// 	if (fds[1] != -1)
// 		close(fds[1]);
// }

// void	execute_child(char *cmd, t_pipeline *data, char **env)
// {
// 	char	**args;

// 	args = ft_split(cmd,' ');
// 	close_pipes(data->pipes, data->num_cmds - 1, data->fds);
// 	free(data->fds);
// 	execve(ft_fix_path(args[0],env),args, env);
// 	perror("execve");
// 	exit(1);
// }

// int	spawn_child(t_pipeline *data, char **argv, char **env)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		setup_io(data->i, data->num_cmds, data->pipes, data->fds);
// 		execute_child(argv[data->i + 2], data, env);
// 	}
// 	close_pipes(data->pipes, data->num_cmds - 1, data->fds);
// 	free(data->fds);
// 	return (pid);
// }

// void	process_commands(t_pipeline *data, char **argv, char **env)
// {
// 	pid_t	pid;

// 	data->i = 0;
// 	while (data->i < data->num_cmds)
// 	{
// 		data->fds = malloc(2 * sizeof(int));
// 		data->fds[0] = open(argv[1], O_RDONLY);
// 		data->fds[1] = open(argv[data->num_cmds + 2],
// 				O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 		pid = spawn_child(data, argv, env);
// 		if (pid == -1)
// 		{
// 			perror("fork");
// 			free(data->fds);
// 			return ;
// 		}
// 		data->i++;
// 	}
// }

// void	cleanup(t_pipeline *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < data->num_cmds - 1)
// 	{
// 		close(data->pipes[i][0]);
// 		free(data->pipes[i]);
// 		i++;
// 	}
// 	free(data->pipes);
// }

// void	wait_children(t_pipeline *data)
// {
// 	int		count;
// 	pid_t	pid;

// 	count = 0;
// 	while (count < data->num_cmds)
// 	{
// 		pid = waitpid(-1, NULL, 0);
// 		if (pid != -1)
// 			count++;
// 	}
// }

// int	main(int argc, char **argv, char **env)
// {
// 	t_pipeline	data;

// 	if (argc != 5)
// 	{
// 		write(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 ... cmdN file2\n",
// 			45);
// 		return (1);
// 	}
// 	data.num_cmds = count_commands(argc);
// 	data.pipes = create_pipes(data.num_cmds - 1);
// 	if (!data.pipes)
// 		return (1);
// 	process_commands(&data, argv, env);
// 	cleanup(&data);
// 	wait_children(&data);
// 	return (0);
// }













void	close_pipes(int **pipes, int num_pipes, int *fds)
{
	int	i;

	i = 0;
	while (i < num_pipes)
	{
		close(pipes[i][0]);
		close(pipes[i][1]);
		i++;
	}
	if (fds[0] != -1)
		close(fds[0]);
	if (fds[1] != -1)
		close(fds[1]);
}





void	setup_io(int i, int num_cmds, int **pipes, int *fds)
{
	if (i == 0 && fds[0] != -1)
		dup2(fds[0], STDIN_FILENO);
	if (i > 0)
		dup2(pipes[i - 1][0], STDIN_FILENO);
	if (i == num_cmds - 1 && fds[1] != -1)
		dup2(fds[1], STDOUT_FILENO);
	if (i < num_cmds - 1)
		dup2(pipes[i][1], STDOUT_FILENO);
}



void	execute_child(char *cmd, t_pipeline *data, char **env)
{
	char	**args;

	args = ft_split(cmd,' ');
	close_pipes(data->pipes, data->num_cmds - 1, data->fds);
	free(data->fds);
	execve(ft_fix_path(args[0],env),args, env);
	perror("execve");
	exit(1);
}

int	spawn_child(t_pipeline *data, char **argv, char **env)
{

	return (pid);
}




void	process_commands(t_pipeline *data, char **argv, char **env)
{
	pid_t	pid;

	data->i = 0;
	while (data->i < data->num_cmds)
	{

		pid_t	pid;
		char	**args;

		pid = fork();
		if (pid <=0)
			return ;
		if (pid == 0)
		{

			setup_io(data->i, data->num_cmds, data->pipes, data->fds);
		

			args = ft_split(cmd,' ');
			close_pipes(data->pipes, data->num_cmds - 1, data->fds);
			execve(ft_fix_path(args[0],env),args, env);
			perror("execve");
			exit(1);

		}
		close_pipes(data->pipes, data->num_cmds - 1, data->fds);
		data->i++;
	}
}
void	cleanup(t_pipeline *data)
{
	int	i;

	i = 0;
	while (i < data->num_cmds - 1)
	{
		close(data->pipes[i][0]);
		free(data->pipes[i]);
		i++;
	}
	free(data->pipes);
}

void	wait_children(t_pipeline *data)
{
	int		count;
	pid_t	pid;

	count = 0;
	while (count < data->num_cmds)
	{
		pid = waitpid(-1, NULL, 0);
		if (pid != -1)
			count++;
	}
}


int	main(int argc, char **argv, char **env)
{
	


	process_commands(&data, argv, env);
	cleanup(&data);
	wait_children(&data);
	return (0);
}
