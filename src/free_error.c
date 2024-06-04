/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:07:10 by paola             #+#    #+#             */
/*   Updated: 2024/06/03 16:13:19 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	msg_error(int err)
{
	if (err == 0)
	{
		ft_putstr_fd("Error: Bad arguments\n", 1);
		ft_putstr_fd("./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	}
	else if (err == -1)
	{
		perror("ERROR");
		exit(EXIT_FAILURE);
	}
}


void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}
