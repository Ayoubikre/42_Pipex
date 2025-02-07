/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakritah <aakritah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:01 by aakritah          #+#    #+#             */
/*   Updated: 2025/02/07 16:17:41 by aakritah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void	callexecve(void)
{
	char *const args[] = {"ls", NULL};
	char *const envp[] = {NULL};
	execve("/bin/ls", args, envp);
	perror("redo");
	exit(EXIT_FAILURE);
}

void	callexecve2(void)
{
	char *const args[] = {"ls", "-a", NULL};
	char *const envp[] = {NULL};
	execve("/bin/ls", args, envp);
	exit(EXIT_FAILURE);
}

int	main(void)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		// Fork failed
		fprintf(stderr, "Fork2 failed.\n");
		return (1);
	}
	else if (pid == 0)
	{
		printf("I am the child. But now a new parent. My PID is :%d --- My child's PID is%d\n", getpid(), pid);
		callexecve();
	}
	else if (pid > 1)
	{
		printf("I am the parent. My PID is :%d --- My child's PID is %d\n",getpid(), pid);
		// waitpid(pid, NULL, 0);
		callexecve2();
	}
}