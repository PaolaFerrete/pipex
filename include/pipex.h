/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:31:43 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 18:29:35 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/include/libft.h"

void	msg_error(int err);
void	free_matrix(char **argv);
void	pipex(char **argv, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	ft_execute(char *argv, char **envp);
char	*completed_path(char *paths, char *cmd);
char	*find_paths(char *cmd, char **envp);

#endif
