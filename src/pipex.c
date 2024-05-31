/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 18:22:11 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 18:30:45 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	printf("EXECUTE\n");
	cmd = ft_split(argv, ' ');
	path = find_paths(cmd[0], envp);
	if (!path)
	{
		free_matrix(cmd);
		msg_error(-1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		msg_error(-1);
	}
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		msg_error(-1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	printf("CHILD_PROCESS\n");

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		msg_error(-1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[2], envp);

}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	printf("PIPEX\n");
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
