/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:25 by bokwuful          #+#    #+#             */
/*   Updated: 2024/10/07 12:40:41 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while ((i + j < len) && haystack[i + j] && needle[j]
			&& haystack[i + j] == needle[j])
		{
			j++;
		}
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
		j = 0;
	}
	return (NULL);
}
/*
int main(void)
{
	const char *str1 = "Help meetmeet you";
	const char *str2 = "pom";
	printf("strnstr :%s\n", strnstr(str1, str2, 15));
	printf("ft_strnstr :%s\n", ft_strnstr(str1, str2, 15));
	return (0);
}
*/
