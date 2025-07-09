/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:09:51 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 16:24:16 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <string.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

char	*remove_whitespace(const char *s1)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*trimmed;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && is_whitespace(s1[start]))
		start++;
	end = strlen(s1);
	while (end > start && is_whitespace(s1[end - 1]))
		end--;
	len = end - start;
	trimmed = malloc(len + 1);
	if (!trimmed)
		return (NULL);
	memcpy(trimmed, s1 + start, len);
	trimmed[len] = '\0';
	return (trimmed);
}

int	is_map_line(const char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}


// Checks if all 6 configuration options (textures and colors) have been set.
int all_configs_set(t_game *game)
{
    int i = 0;
    while (i < 6)
    {
        if (game->config.is_set[i] == 0)
            return (0); // Return false if any config is not set
        i++;
    }
    return (1); // Return true if all configs are set
}
