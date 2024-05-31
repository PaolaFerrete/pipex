/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:21:46 by pferrete          #+#    #+#             */
/*   Updated: 2024/01/27 14:24:30 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*split a string */

#include "../include/libft.h"

static int	ft_count_split(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_array(char **ssplit, char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		k;
	size_t	s_len;

	i = 0;
	k = 0;
	s_len = ft_strlen(s);
	while (s[i])
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j >= s_len)
			ssplit[k++] = "\0";
		else
			ssplit[k++] = ft_substr(s, j, i - j);
	}
	return (ssplit);
}

char	**ft_split(char const *s, char c)
{
	char	**ssplit;
	int		nwords;

	if (!s)
		return (NULL);
	nwords = ft_count_split(s, c);
	ssplit = malloc((nwords + 1) * sizeof(char *));
	if (ssplit == NULL)
		return (NULL);
	ssplit = ft_array(ssplit, s, c);
	ssplit[nwords] = NULL;
	return (ssplit);
}
