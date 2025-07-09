/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 16:37:08 by bokwuful          #+#    #+#             */
/*   Updated: 2025/04/15 17:23:25 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char	*ft_ltoa(long n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n = -n;
	}
	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1 + (sign == -1)));
	if (!str)
		return (NULL);
	str[len + (sign == -1)] = '\0';
	if (sign == -1)
		str[0] = '-';
	while (len--)
	{
		str[len + (sign == -1)] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
