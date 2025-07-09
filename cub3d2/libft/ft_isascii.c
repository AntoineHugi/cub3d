/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:04 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 12:54:27 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}

/*
int main(void)
{
	int s1 = 'A';
	int s2 = '2';
	printf("isascii : %d, %d\n", isascii(s1), isascii(s2));
	printf("ft_isascii : %d, %d\n", ft_isascii(s1), ft_isascii(s2));
	return (0);
}
*/
