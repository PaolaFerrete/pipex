/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:23:11 by paola             #+#    #+#             */
/*   Updated: 2024/06/03 14:51:17 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>


int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		msg_error(0);
	else if (!argv[2][0] || !argv[3][0])
		msg_error(0);
	else if (argc == 5)
		pipex(argv, envp);
	else
		msg_error(0);
	return (0);
}
