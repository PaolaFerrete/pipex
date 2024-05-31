/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:59 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 17:26:24 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/include/libft.h"

/*
char	*find_path(char *paths, char *cmd)
{
	char	*part_path;
	char	*path;

	printf("FIND_PATH\n");
	if (paths == NULL || cmd == NULL)
		return (0);
	part_path = ft_strjoin(paths, "/");
	printf("join /: %s\n", part_path);
	path = ft_strjoin(part_path, cmd);
	return (path);
}
*/


char	*find_paths(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*part_path;
	int		i;

	write(1, "FIND_PATHS\n", 10);
	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
	{
		printf("envp[i]: %s\n", envp[i]);
		i++;
	}
	printf("envp[i]: %s\n", envp[i]);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	free_matrix(paths);
	return (0);
}

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
