/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:02:33 by pferrete          #+#    #+#             */
/*   Updated: 2023/12/20 14:25:06 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*erase the data int the n bytes of the memory*/
/* param: *str pointer, size_t n */

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*p;

	p = str;
	while (n-- > 0)
	{
		p[n] = '\0';
	}
}
