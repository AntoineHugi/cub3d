/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:24:28 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/15 11:31:46 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}
/*
int main(void)
{
	int s1;
	int s2;
	int s3;

	s1 = '2';
	s2 = 'b';
	s3 = 'N';
	printf("toupper : %c, %c\n, %c\n", toupper(s1), toupper(s2), toupper(s3));
	printf("ft_toupper : %c, %c\n, %c\n", ft_toupper(s1),
		ft_toupper(s2), ft_toupper(s3));
	return (0);
}
*/