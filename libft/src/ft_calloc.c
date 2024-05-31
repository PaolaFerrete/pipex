/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:40:54 by pferrete          #+#    #+#             */
/*   Updated: 2023/12/20 14:25:10 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

/*param: nmemb numero de elementos que sera alocado; */
/* size e o tamanho de bytes de cada elemento*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ptr;
	size_t	total;
	size_t	i;

	i = 0;
	total = (nmemb * size);
	ptr = malloc(total);
	if (ptr == NULL)
	{
		return (NULL);
	}
	if (ptr != NULL)
	{
		while (i < total)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return (ptr);
}
