/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:01:02 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 10:01:34 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_player(t_game *game)
{
    game->player.pos_x = game->map.player_x + 0.5;
    game->player.pos_y = game->map.player_y + 0.5;

    if (game->map.player_dir == 'N')
    {
        game->player.dir_x = 0; game->player.dir_y = -1;
        game->player.plane_x = 0.66; game->player.plane_y = 0;
    }
    else if (game->map.player_dir == 'S')
    {
        game->player.dir_x = 0; game->player.dir_y = 1;
        game->player.plane_x = -0.66; game->player.plane_y = 0;
    }
    else if (game->map.player_dir == 'W')
    {
        game->player.dir_x = -1; game->player.dir_y = 0;
        game->player.plane_x = 0; game->player.plane_y = -0.66;
    }
    else if (game->map.player_dir == 'E')
    {
        game->player.dir_x = 1; game->player.dir_y = 0;
        game->player.plane_x = 0; game->player.plane_y = 0.66;
    }
}
