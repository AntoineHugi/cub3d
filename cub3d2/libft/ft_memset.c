/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:22:04 by bokwuful          #+#    #+#             */
/*   Updated: 2024/12/01 00:11:57 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_memset fills the first len bytes of the memory area
	pointed	to by b with the byte c. Both b and c are interpreted as 
	unsigned char.

	RETURN VALUE :
	A pointer to memory area s.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;

	if (n <= 0)
		return (b);
	ptr = (unsigned char *)b;
	while (n--)
		*ptr++ = (unsigned char)c;
	return (b);
}
/*
int main(void)
{
	const char *str = "Hello World!";
	printf("memset :%s\n", memset(str, 'k', 5));
	printf("ft_memset :%s\n", ft_memset(str, 'k', 5));
	return (0);
}
*/