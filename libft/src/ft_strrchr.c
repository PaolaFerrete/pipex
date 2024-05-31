/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:19:55 by pferrete          #+#    #+#             */
/*   Updated: 2023/12/20 14:39:32 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Search for the last occurrence of the character */

#include "../include/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == (char)c)
		{
			ptr = (char *)&s[len];
			return (ptr);
		}
		len--;
	}
	return (NULL);
}
