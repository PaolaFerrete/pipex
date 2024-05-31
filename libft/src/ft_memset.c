/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:23:36 by pferrete          #+#    #+#             */
/*   Updated: 2023/12/20 14:37:08 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*Copies the values into each of the first count characters of the pointer*/
/*param: *str pointer, int value, size_t num */
/*return copie of the pointer*/

void	*ft_memset(void *str, int value, size_t num)
{
	unsigned char	*p;

	p = str;
	while (num-- > 0)
	{
		p[num] = (unsigned char) value;
	}
	return (str);
}
