/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:23:31 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 23:01:54 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	n;
	size_t	i;

	n = dstsize - 1;
	i = 0;
	if (dstsize > 0)
	{
		while (n-- && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
/*
int main(void)
{
	char str1[24] = "Come ";
	char str2[24] = "Come ";
	//const char str3[] = "pomp";
	printf("strlcpy : %lu\n", strlcpy(str1, "tomper", 21));
	printf("\nft_strlcpy : %lu\n", ft_strlcpy(str2, "tomper", 21));
	printf("str1 : %s\n", str1);
	printf("str2 : %s\n", str2);
	return (0);
}
*/