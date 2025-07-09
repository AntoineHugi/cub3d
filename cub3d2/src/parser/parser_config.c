/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_config.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:06:44 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 14:12:04 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Modified to return -1 on error and NOT exit.
static int	parse_color(const char *str)
{
	char	**rgb;
	int		color;

	int r, g, b;
	rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_string_array(rgb);
		return (-1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_string_array(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		return (-1);
	}
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	parse_config_line(char *line, t_game *game)
{
	char	**tokens;
	char	*error_msg;
	int		color;

	error_msg = NULL;
	tokens = ft_split(line, ' ');
	if (!tokens || !tokens[0] || !tokens[1])
		error_msg = "Invalid configuration line format.";
	else if (strcmp(tokens[0], "NO") == 0 && !game->config.is_set[0]++)
		game->config.no_path = ft_strdup(tokens[1]);
	else if (strcmp(tokens[0], "SO") == 0 && !game->config.is_set[1]++)
		game->config.so_path = ft_strdup(tokens[1]);
	else if (strcmp(tokens[0], "WE") == 0 && !game->config.is_set[2]++)
		game->config.we_path = ft_strdup(tokens[1]);
	else if (strcmp(tokens[0], "EA") == 0 && !game->config.is_set[3]++)
		game->config.ea_path = ft_strdup(tokens[1]);
	else if (strcmp(tokens[0], "F") == 0 && !game->config.is_set[4]++)
	{
		color = parse_color(tokens[1]);
		if (color == -1)
			error_msg = "Invalid floor color.";
		else
			game->config.floor_color = color;
	}
	else if (strcmp(tokens[0], "C") == 0 && !game->config.is_set[5]++)
	{
		color = parse_color(tokens[1]);
		if (color == -1)
			error_msg = "Invalid ceiling color.";
		else
			game->config.ceiling_color = color;
	}
	else if (tokens[2])
		error_msg = "Extra information on configuration line.";
	else
		error_msg = "Invalid or duplicate identifier.";
	free_string_array(tokens);
	if (error_msg)
		error_exit(game, error_msg);
}
