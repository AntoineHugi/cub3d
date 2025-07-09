/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:22:26 by bokwuful          #+#    #+#             */
/*   Updated: 2024/12/01 00:15:09 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_bzero erases data in the n bytes of memory starting
	at location s by writing '\0's.

	RETURN VALUE :
	None.
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

/*
int main(void)
{
	int s1[8];
	int s2[2];
	printf("bzero\n");
	for(int i = 0; i < 8; i++)
		printf("%d, ", s1[i]);
	printf("\nft_bzero\n");
	for(int i = 0; i < 2; i++)
		printf("%d, ", s2[i]);
	return (0);
}
*/
