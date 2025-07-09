/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:22:47 by bokwuful          #+#    #+#             */
/*   Updated: 2022/11/28 12:22:56 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst || !src)
		return (dst);
	d = dst;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}
/*
int main(void)
{
	void *s1 = "Hello5 World";
	printf("memcpy :%s\n", memcpy(s1, s1[5], 6));
	printf("ft_memcpy :%s\n", ft_memcpy(s1, s1[5], 6));
	return (0);
}
*/