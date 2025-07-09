/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:11:26 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 14:26:22 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	load_texture(t_game *game, int index, char *path)
{
	void *ptr;

	ptr = NULL;
	game->textures[index].ptr = mlx_xpm_file_to_image(game->mlx, path,
			(int []){TEXTURE_WIDTH}, (int []){TEXTURE_HEIGHT});
	if (!game->textures[index].ptr)
		error_exit(game, "Failed to load texture.");
	else
		ptr = game->textures[index].ptr;
	game->textures[index].data = (int *)mlx_get_data_addr(ptr,
			&game->textures[index].bpp, &game->textures[index].size_l,
			&game->textures[index].endian);
}

void	init_engine(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, "Failed to initialize MiniLibX.");
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
		error_exit(game, "Failed to create window.");
	game->frame.ptr = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->frame.data = (int *)mlx_get_data_addr(game->frame.ptr,
			&game->frame.bpp, &game->frame.size_l, &game->frame.endian);
	load_texture(game, 0, game->config.no_path);
	load_texture(game, 1, game->config.so_path);
	load_texture(game, 2, game->config.we_path);
	load_texture(game, 3, game->config.ea_path);
}
