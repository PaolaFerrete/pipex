/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:07:10 by paola             #+#    #+#             */
/*   Updated: 2024/05/31 15:11:24 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	msg_error(int err)
{
	printf("MSG_ERROR\n");
	if (err == 0)
	{
		write(1, "error arguments:\n", 16);
		write(2, "./pipex <file1> <cmd1> <cmd2> <file2>\n", 38);
	}
	else if (err == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}


void	free_matrix(char **argv)
{
	int	i;

	printf("FREE_MATRIX\n");
	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		printf("free: %s\n", argv[i]);
		free(argv[i++]);
	}
	free(argv);
}
