/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:24:04 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 22:58:49 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + k);
}
/*
int main(void)
{
	char str1[24] = "";
	char str2[24] = "";
	//const char str3[] = "pomp";
	printf("strlcat : %lu\n", strlcat(str1, "tomp", 21));
	printf("\nft_strlcat : %lu\n", ft_strlcat(str2, "tomp", 21));
	printf("str1 : %s\n", str1);
	printf("str2 : %s\n", str2);
	return (0);
}
*/