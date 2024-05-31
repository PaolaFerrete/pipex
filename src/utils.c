/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:59 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 18:31:00 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/include/libft.h"


char	*completed_path(char *paths, char *cmd)
{
	char	*part_path;
	char	*path;

	printf("COMPLETED_PATH\n");
	if (paths == NULL || cmd == NULL)
		return (0);
	part_path = ft_strjoin(paths, "/");
	printf("join /: %s\n", part_path);
	path = ft_strjoin(part_path, cmd);
	printf("Return path: %s\n", path);
	return (path);
}

char	*find_paths(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	write(1, "FIND_PATHS\n", 11);
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
		path = completed_path(paths[i], cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_matrix(paths);
	return (0);
}



