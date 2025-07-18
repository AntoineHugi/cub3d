/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:32:12 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 09:58:04 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

/* saves the element information in the game struct */
// saves the element information in the game struct
static int	process_main_textures(t_game *game, char *line)
{
	if (line[0] == 'N' && game->no_texture_path == NULL)
		game->no_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'E' && game->ea_texture_path == NULL)
		game->ea_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'S' && game->so_texture_path == NULL)
		game->so_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'W' && game->we_texture_path == NULL)
		game->we_texture_path = ft_strdup(line + 2);
	else
		return (0);
	return (1);
}

static int	process_bonus_textures(t_game *game, char *line)
{
	if (line[0] == 'D' && game->d_texture_path == NULL)
		game->d_texture_path = ft_strdup(line + 1);
	else if (line[0] == 'O' && game->o_texture_path == NULL)
		game->o_texture_path = ft_strdup(line + 1);
	else if (line[0] == 'B' && game->s_texture_paths[0] == NULL)
		game->s_texture_paths[0] = ft_strdup(line + 1);
	else if (line[0] == 'P' && game->s_texture_paths[1] == NULL)
		game->s_texture_paths[1] = ft_strdup(line + 1);
	else
		return (0);
	return (1);
}

int	get_element_info(t_game *game, char *line)
{
	if (process_main_textures(game, line))
		return (1);
	if (process_bonus_textures(game, line))
		return (1);
	if (line[0] == 'C' && game->c_color_code == NULL)
		game->c_color_code = ft_strdup(line + 1);
	else if (line[0] == 'F' && game->f_color_code == NULL)
		game->f_color_code = ft_strdup(line + 1);
	else
	{
		printf("Duplicate element.\n");
		free(line);
		return (0);
	}
	return (1);
}

static int	process_element_line(t_game *game, char *line)
{
	if (line[0] == '#')
	{
		free(line);
		return (1);
	}
	if (valid_element_line(line))
	{
		if (!get_element_info(game, line))
			return (0);
	}
	else
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

// checking that the file contains valid element line
int	parsing_element(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (game->f_array[i] && i < game->map_start_line)
	{
		line = remove_whitespaces(game->f_array[i++], 0, 0);
		if (line[0] && !(ft_isdigit(line[0])) && line[0] != '\n')
		{
			if (!process_element_line(game, line))
				return (0);
		}
		else
			free(line);
	}
	return (1);
}
