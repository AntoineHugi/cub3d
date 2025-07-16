/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:22:38 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 11:22:40 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* adds padding around the player to avoid slipping into walls */
void	make_move(t_map *map, double new_x, double new_y)
{
	double	padding;
	char	**array;

	padding = 0.2;
	array = map->map_array;
	if (array[(int)(map->p_posy)][(int)(new_x + padding)] != '1'
		&& array[(int)(map->p_posy)][(int)(new_x - padding)] != '1')
		map->p_posx = new_x;
	if (array[(int)(new_y + padding)][(int)(map->p_posx)] != '1'
		&& array[(int)(new_y - padding)][(int)(map->p_posx)] != '1')
		map->p_posy = new_y;
}

/* checks which direction to move */
/* and sets the new potential position accordingly */
void	check_move(t_game *game, t_map *map, int direction)
{
	double	new_x;
	double	new_y;

	if (direction == FORWARD)
	{
		new_x = map->p_posx + game->rc.p_dir_x * map->move_speed;
		new_y = map->p_posy + game->rc.p_dir_y * map->move_speed;
	}
	if (direction == BACKWARD)
	{
		new_x = map->p_posx - game->rc.p_dir_x * map->move_speed;
		new_y = map->p_posy - game->rc.p_dir_y * map->move_speed;
	}
	if (direction == LEFT)
	{
		new_x = map->p_posx - game->rc.plane_x * map->move_speed;
		new_y = map->p_posy - game->rc.plane_y * map->move_speed;
	}
	if (direction == RIGHT)
	{
		new_x = map->p_posx + game->rc.plane_x * map->move_speed;
		new_y = map->p_posy + game->rc.plane_y * map->move_speed;
	}
	make_move(map, new_x, new_y);
}
