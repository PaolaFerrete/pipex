/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:02:56 by paola             #+#    #+#             */
/*   Updated: 2024/06/16 11:54:42 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	ft_execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = get_path(*cmd, envp);
	if (!path)
	{
		free_matrix(cmd);
		msg_error(-1);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_matrix(cmd);
		exit(127);
	}
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open_file(argv[4], 1);
	if (fileout == -1)
		msg_error(-1);
	dup2(fileout, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fileout);
	ft_execute(argv[3], envp);
}

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open_file(argv[1], 0);
	if (filein == -1)
		msg_error(-1);
	dup2(filein, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	close(filein);
	ft_execute(argv[2], envp);
}

int	check_command(char *argv)
{
	char	**get_command;
	int		i;

	get_command = ft_split(argv, ' ');
	i = ft_strncmp(get_command[0], "sleep", ft_strlen("sleep"));
	free_matrix(get_command);
	if (i == 0)
		return (0);
	else
		return (1);
}

void	pipex(char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		msg_error(-1);
	pid = fork();
	if (pid == -1)
		msg_error(-1);
	if (pid == 0)
	{
		close(fd[0]);
		child_process(argv, envp, fd);
	}
	else
	{
		close(fd[1]);
		if (check_command(argv[2]) == 0)
			waitpid(0, NULL, 0);
		else
			waitpid(0, NULL, WNOHANG);
		parent_process(argv, envp, fd);
	}
}
