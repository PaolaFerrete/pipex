/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:59 by paola             #+#    #+#             */
/*   Updated: 2024/06/05 10:49:34 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../libft/include/libft.h"


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
	char	**s_cmd;

	i = -1;
	allpath = ft_split(my_getenv("PATH", env), ':');
	s_cmd = ft_split(cmd, ' ');
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		printf("%s\n", exec);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			free_matrix(s_cmd);
			return (exec);
		}
		free(exec);
	}
	free_matrix(allpath);
	free_matrix(s_cmd);
	return (cmd);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
	{
		ret = open(file, O_RDONLY, 0777);
		if (ret == -1)
			msg_error(-1);
	}
	else if (in_or_out == 1)
	{
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (ret == -1)
			msg_error(-1);
	}
	return (ret);
}



