/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:25:15 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 22:34:45 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}
/*
int main(void)
{
	const char *str1 = "Help2bv";
	int c = '2';
	printf("strchr :%s\n", strchr(str1, c));
	printf("ft_strchr :%s\n", ft_strchr(str1, c));
	return (0);
}
*/