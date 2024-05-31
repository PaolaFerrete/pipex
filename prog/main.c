/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:23:11 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 15:10:55 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"


int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (argc == 5)
	{
		printf("ac: %d\n", argc);
		if (pipe(fd) == -1)
			msg_error(-1);
		printf("descriptor fd0: %d\n", fd[0]);
		printf("descriptor fd1: %d\n", fd[1]);
		pid = fork();
		printf("pid: %d\n", pid);
		if (pid == -1)
			msg_error(-1);
		if (pid == 0)
			child_process(argv, envp, fd);
		waitpid(pid, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		msg_error(0);
	}
	return (0);
}
