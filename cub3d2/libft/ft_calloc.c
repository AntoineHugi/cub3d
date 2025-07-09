/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:28:27 by bokwuful          #+#    #+#             */
/*   Updated: 2024/12/01 00:15:46 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_calloc allocates memory for an array of count elements
	of size bytes each and sets the memory to zero.

	RETURN VALUE :
	The pointer to the allocated memory. NULL if the memory allocation fails.
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int main(void)
{
	char *str1 = (char *)calloc(10, sizeof(char));
	char *str2 = (char *)ft_calloc(10, sizeof(char));
	printf("calloc :");
	for (int i = 0; i < 10; i++)
		printf("%d", str1[i]);
	printf("\nft_calloc :");
	for (int i = 0; i < 10; i++)
		printf("%d", str2[i]);
	free(str1);
	free(str2);
	return (0);
}
*/