/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_element.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:32:36 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 10:20:56 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* checks that the texture files can be opened */

static int	valid_bonus_textures(t_game *game)
{
	if (open(game->s_texture_paths[0], O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open sprite texture 0.\n");
		return (0);
	}
	if (open(game->s_texture_paths[1], O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open sprite texture.\n");
		return (0);
	}
	if (open(game->d_texture_path, O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open door texture.\n");
		return (0);
	}
	return (1);
}

static int	valid_textures(t_game *game)
{
	if (open(game->no_texture_path, O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open NO texture.\n");
		return (0);
	}
	if (open(game->ea_texture_path, O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open EA texture.\n");
		return (0);
	}
	if (open(game->so_texture_path, O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open SO texture.\n");
		return (0);
	}
	if (open(game->we_texture_path, O_RDONLY) == -1)
	{
		printf("Error\nCan't find or open WE texture.\n");
		return (0);
	}
	return (valid_bonus_textures(game));
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
	if (game->s_texture_paths[0] == NULL)
		return (0);
	if (game->s_texture_paths[1] == NULL)
		return (0);
	if (game->d_texture_path == NULL)
		return (0);
	if (game->o_texture_path == NULL)
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
		printf("Error\nSome element types are missing or placed after the map.\n");
		return (0);
	}
	if (!valid_textures(game))
		return (0);
	if (!valid_colors(game))
		return (0);
	return (1);
}
