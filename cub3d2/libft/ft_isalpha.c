/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:57:53 by bokwuful          #+#    #+#             */
/*   Updated: 2022/11/28 12:04:01 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}

/*
int main(void)
{
	int s1 = 'A';
	int s2 = '2';
	printf("isalpha : %d, %d\n", isalpha(s1), isalpha(s2));
	printf("ft_isalpha : %d, %d\n", ft_isalpha(s1), ft_isalpha(s2));
	return (0);
}
*/
