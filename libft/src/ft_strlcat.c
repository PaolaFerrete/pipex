/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 14:54:49 by paola             #+#    #+#             */
/*   Updated: 2023/12/20 14:38:58 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_length;
	size_t	src_length;

	src_length = ft_strlen(src);
	dest_length = ft_strlen(dst);
	j = dest_length;
	i = 0;
	if (size <= dest_length)
		return (size + src_length);
	if (dest_length < size - 1 && size > 0)
		while (src[i] && dest_length + i < size - 1)
			dst[j++] = src[i++];
	dst[j] = 0;
	if (dest_length >= size)
		dest_length = size;
	return (dest_length + src_length);
}
