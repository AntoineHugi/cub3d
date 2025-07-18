/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:23:48 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 11:23:50 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* checks that the texture files can be opened */
static int	valid_textures(t_game *game)
{
	if (open(game->no_texture_path, O_RDONLY) == -1)
	{
		printf("Can't find or open NO texture.\n");
		return (0);
	}
	if (open(game->ea_texture_path, O_RDONLY) == -1)
	{
		printf("Can't find or open EA texture.\n");
		return (0);
	}
	if (open(game->so_texture_path, O_RDONLY) == -1)
	{
		printf("Can't find or open SO texture.\n");
		return (0);
	}
	if (open(game->we_texture_path, O_RDONLY) == -1)
	{
		printf("Can't find or open WE texture.\n");
		return (0);
	}
	return (1);
}

/* checks that no elements are missing */
int	all_elements(t_game *game)
{
	if (game->no_texture_path == NULL)
		return (0);
	if (game->ea_texture_path == NULL)
		return (0);
	if (game->so_texture_path == NULL)
		return (0);
	if (game->we_texture_path == NULL)
		return (0);
	if (game->c_color_code == NULL)
		return (0);
	if (game->f_color_code == NULL)
		return (0);
	return (1);
}

/* checks all elements are valid */
int	valid_elements(t_game *game)
{
	if (!parsing_element(game))
		return (0);
	if (!all_elements(game))
	{
		printf("Some element types are missing or placed after the map.\n");
		return (0);
	}
	if (!valid_textures(game))
		return (0);
	if (!valid_colors(game))
		return (0);
	return (1);
}
