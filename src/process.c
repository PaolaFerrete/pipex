/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:59 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 15:14:25 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/include/libft.h"

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	write(1, "FIND_PATH\n", 10);
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
		printf("join /: %s\n", part_path);
		path = ft_strjoin(part_path, cmd);
		printf("path: %s\n", path);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			printf("diretório: %s\n", path);
			return (path);
		}
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
	int		i;
	char	*path;

	printf("EXECUTE\n");
	i = -1;
	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_matrix(cmd);
		msg_error(-1);
	}
	if (execve(path, cmd, envp) == -1)
		msg_error(-1);
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
