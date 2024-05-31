/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paola <paola@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:44:30 by paola             #+#    #+#             */
/*   Updated: 2023/12/20 14:36:44 by paola            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	ft_count_num(int num)
{
	int	numdig;

	numdig = 0;
	if (num == 0)
		return (1);
	else if (num < 0)
		numdig += 1;
	while (num != 0)
	{
		num /= 10;
		numdig++;
	}
	return (numdig);
}

static char	*ft_copy(char *s, long num, int size)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		s[0] = '-';
		num *= -1;
		i++;
	}
	if (num == 0)
	{
		s[i] = 48;
		i++;
	}
	while (num != 0)
	{
		s[size - 1] = num % 10 + 48;
		num = num / 10;
		size--;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		numdig;
	long	num;

	numdig = ft_count_num(n);
	num = n;
	s = malloc(sizeof(char) * (numdig + 1));
	if (!s)
		return (NULL);
	s = ft_copy(s, num, numdig);
	return (s);
}
