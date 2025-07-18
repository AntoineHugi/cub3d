/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:19:22 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/18 10:09:31 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	count_sprites(t_game *game)
{
	int	y;
	int	x;

	game->sprite_count = 0;
	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			if (game->map->map_array[y][x] == '2'
				|| game->map->map_array[y][x] == '4')
				game->sprite_count++;
			x++;
		}
		y++;
	}
}

static void	set_sprite_properties(t_game *game, int i, int x, int y)
{
	game->sprites[i].x = x + 0.5;
	game->sprites[i].y = y + 0.5;
	game->sprites[i].tex[0] = &game->sprite_tex[0];
	game->sprites[i].tex[1] = &game->sprite_tex[1];
	game->sprites[i].frame = 0;
	game->sprites[i].anim_timer = 0;
}

void	init_sprites(t_game *game)
{
	int	y;
	int	x;
	int	i;

	count_sprites(game);
	game->sprites = safe_malloc(sizeof(t_sprite) * game->sprite_count);
	i = 0;
	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			if (game->map->map_array[y][x] == '2'
				|| game->map->map_array[y][x] == '4')
			{
				set_sprite_properties(game, i, x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}

static void	calculate_sprite_distances(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		game->sprites[i].dist = sqrt(pow(game->sprites[i].x - game->map->p_posx, 2)
				+ pow(game->sprites[i].y - game->map->p_posy, 2));
		i++;
	}
}

void	sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	tmp;

	calculate_sprite_distances(game);
	i = 0;
	while (i < game->sprite_count - 1)
	{
		j = i + 1;
		while (j < game->sprite_count)
		{
			if (game->sprites[i].dist < game->sprites[j].dist)
			{
				tmp = game->sprites[i];
				game->sprites[i] = game->sprites[j];
				game->sprites[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
