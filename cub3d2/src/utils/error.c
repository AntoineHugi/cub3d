/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:19:01 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 09:58:34 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void cleanup(t_game *game)
{
    if (!game) return;
    free(game->config.no_path);
    free(game->config.so_path);
    free(game->config.we_path);
    free(game->config.ea_path);
    free_string_array(game->map.grid);

    if (game->mlx)
    {
        for (int i = 0; i < 4; i++)
            if (game->textures[i].ptr)
                mlx_destroy_image(game->mlx, game->textures[i].ptr);
        if (game->frame.ptr)
            mlx_destroy_image(game->mlx, game->frame.ptr);
        if (game->win)
            mlx_destroy_window(game->mlx, game->win);
    }
}

void error_exit(t_game *game, const char *message)
{
    printf("Error\n%s\n", message);
    cleanup(game);
    exit(1);
}
