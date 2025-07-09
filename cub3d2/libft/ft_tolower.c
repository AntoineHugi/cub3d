/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:24:51 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/15 11:29:47 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
int	main(void)
{
	int s1;
	int s2;
	int s3;

	s1 = '2';
	s2 = 'b';
	s3 = 'N';
	printf ("tolower : %c, %c\n, %c\n", tolower(s1), tolower(s2), tolower(s3));
	printf ("ft_tolower : %c, %c\n, %c\n",
		ft_tolower(s1), ft_tolower(s2), ft_tolower(s3));
	return (0);
}
*/