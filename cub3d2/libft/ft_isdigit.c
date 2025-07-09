/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:14:03 by bokwuful          #+#    #+#             */
/*   Updated: 2022/11/28 12:14:13 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
int main(void)
{
	int s1 = 'A';
	int s2 = '2';
	printf("isdigit : %d, %d\n", isdigit(s1), isdigit(s2));
	printf("ft_isdigit : %d, %d\n", ft_isdigit(s1), ft_isdigit(s2));
	return (0);
}
*/
