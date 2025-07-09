/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:21:46 by bokwuful          #+#    #+#             */
/*   Updated: 2022/11/28 12:21:49 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
int main(void)
{
	char *str1 = "Help meetmeet you";
	const char *str2 = "    ";
	printf("strlen :%lu, %lu\n", strlen(str1), strlen(str2));
	printf("ft_strlen : %lu, %lu\n", ft_strlen(str1), ft_strlen(str2));
	return (0);
}*/