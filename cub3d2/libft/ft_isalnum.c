/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:19:34 by bokwuful          #+#    #+#             */
/*   Updated: 2022/12/14 12:53:35 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c) || ft_isdigit(c)));
}
/*
int main(void)
{
	int s1 = 'A';
	int s2 = '1';
	printf("isalnum : %d, %d\n", isalnum(s1), isalnum(s2));
	printf("ft_isalnum : %d, %d\n", ft_isalnum(s1), ft_isalnum(s2));
	return (0);
}
*/
