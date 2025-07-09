/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <bokwuful@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:27:45 by bokwuful          #+#    #+#             */
/*   Updated: 2024/12/01 00:12:38 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION :
	The function ft_atoi converts a string into an int.

	RETURN VALUE :
	The converted int.
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	if (!str)
		return (0);
	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (str[i] == 43)
	{
		sign = 1;
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		result = (result * 10) + (str[i++] - 48);
	return (result * sign);
}

/*
int main(void)
{
	const char *str = "    -0234560av";
	printf("atoi :%d\n", atoi(str));
	printf("ft_atoi :%d\n", ft_atoi(str));
	return (0);
}
*/
