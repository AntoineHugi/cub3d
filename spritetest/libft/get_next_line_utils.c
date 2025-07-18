/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:16:22 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/09 15:16:23 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gnl_memcpy(char *dst, char *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return ;
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	result = (char *)ft_calloc((s1_size + s2_size + 1), sizeof(char));
	if (!result)
	{
		if (s1)
			free(s1);
		s1 = NULL;
		return (NULL);
	}
	ft_gnl_memcpy(&result[0], s1, s1_size);
	ft_gnl_memcpy(&result[s1_size], s2, s2_size);
	if (s1)
		free(s1);
	s1 = NULL;
	return (result);
}

char	*ft_strchr_mod(char *s)
{
	size_t		i;
	char		*ptr;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	ptr = (char *)ft_calloc(ft_strlen(s + i) + 1, sizeof(char));
	if (!ptr)
	{
		if (s)
			free (s);
		s = NULL;
		return (NULL);
	}
	ft_gnl_memcpy(ptr, s + i, ft_strlen(s + i));
	if (s)
		free (s);
	s = NULL;
	return (ptr);
}
