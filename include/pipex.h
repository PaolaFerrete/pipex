/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:31:43 by paola             #+#    #+#             */
/*   Updated: 2024/06/16 11:18:56 by paola            ###   ########.fr       */
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
# include <errno.h>
# include "../libft/include/libft.h"

void	msg_error(int err);
void	free_matrix(char **argv);
void	pipex(char **argv, char **envp);
void	child_process(char **argv, char **envp, int *fd);
void	parent_process(char **argv, char **envp, int *fd);
void	ft_execute(char *argv, char **envp);
char	*get_path(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
int		open_file(char *file, int in_or_out);
int		check_command(char *argv);

#endif
