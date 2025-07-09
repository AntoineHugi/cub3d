/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:40 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 12:56:13 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return ((31 < c && c < 127));
}
/*
int main(void)
{
	int s1 = 'A';
	int s2 = '2';
	printf("isprint : %d, %d\n", isalpha(s1), isalpha(s2));
	printf("ft_isprint : %d, %d\n", ft_isalpha(s1), ft_isalpha(s2));
	return (0);
}
*/
