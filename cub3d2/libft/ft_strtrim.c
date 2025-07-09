/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro13 <macbookpro13@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:49:40 by macbookpro13      #+#    #+#             */
/*   Updated: 2022/12/15 11:15:09 by macbookpro13     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (start < end)
		trimmed[i++] = s1[start++];
	trimmed[i] = 0;
	return (trimmed);
}
/*
int	main(void)
{
	char const	*str1 = " ,.  Software Engineer,, _... -";
	char const	*str2 = " -.. ,.  Software... Engineer... _";
	char		*str3;
	char		*str4;

	str3 = ft_strtrim(str1, ",-_ .");
	str4 = ft_strtrim(str2, ", .-");
	printf ("str3 :%s\n", str3);
	printf ("str4 :%s\n", str4);
	return (0);
}
*/