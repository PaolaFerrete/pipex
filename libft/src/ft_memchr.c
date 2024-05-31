/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:00:37 by pferrete          #+#    #+#             */
/*   Updated: 2023/12/20 14:36:48 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
/*searches an array for the first occurrence of a character */

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	unsigned char	c;
	unsigned char	*p;
	size_t			i;

	c = ch;
	i = 0;
	p = (unsigned char *)ptr;
	while (i < count)
	{
		if (p[i] == c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
