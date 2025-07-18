/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 09:59:37 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/18 10:11:17 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// checks valid map characters
int	is_valid_map_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'W' || c == 'E'
		|| c == '2' || c == '4' || c == '8' || c == 'B' || c == 'P' || c == 'D'
		|| c == ' ' || c == '\n' || c == '\t' || c == '\r' || c == '\f');
}

/* checker for the valid line */
int	valid_element_line(char *line)
{
	if (line[0] == 'F' || line[0] == 'C' || line[0] == 'D' || line[0] == 'O'
		|| line[0] == 'B' || line[0] == 'P')
		return (1);
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	if (line[0] == 'E' && line[1] == 'A')
		return (1);
	if (line[0] == 'S' && line[1] == 'O')
		return (1);
	if (line[0] == 'W' && line[1] == 'E')
		return (1);
	printf("Invalid line in file. Line is '%s'.\n", line);
	return (0);
}

/* Trims the element lines of whitespaces */
char	*remove_whitespaces(char *str, int i, int j)
{
	char	*new_str;
	int		new_len;

	new_len = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\f')
			new_len++;
		i++;
	}
	new_str = (char *)ft_calloc(new_len + 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\f')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	return (new_str);
}
