/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:02:43 by paola             #+#    #+#             */
/*   Updated: 2024/06/16 15:54:33 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*my_getenv(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free(sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	free_matrix(allpath);
	return (cmd);
}

int	check_command(char *argv)
{
	char	**get_command;
	int		i;

	get_command = ft_split(argv, ' ');
	i = ft_strcmp(get_command[0], "sleep");
	free_matrix(get_command);
	if (i == 0)
		return (0);
	else
		return (1);
}

int	open_file(char *file, int in_or_out)
{
	int	arch;

	if (in_or_out == 0)
	{
		arch = open(file, O_RDONLY, 0777);
		if (arch == -1)
			msg_error(-1);
	}
	else if (in_or_out == 1)
	{
		arch = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (arch == -1)
			msg_error(-1);
	}
	return (arch);
}
