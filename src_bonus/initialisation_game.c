/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_game.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:31:23 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 13:31:25 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* saves the color code into an int */
static int	save_color_int(char *str)
{
	char	**rgb;
	int		color;
	int		r;
	int		g;
	int		b;

	rgb = ft_split(str, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	color = (r * 65536) + (g * 256) + b;
	free_array(rgb);
	return (color);
}

/* creates an individual texture into an image, this is malloc'd */
static t_img	new_texture(void *mlx, char *path, t_game *game)
{
	t_img	t;

	t.ptr = mlx_xpm_file_to_image(mlx, path, &t.width, &t.height);
	if (t.ptr == NULL)
		initialisation_error(game, "Could not create texture.");
	t.data = (int *)mlx_get_data_addr(t.ptr, &t.bpp, &t.size_l, &t.endian);
	if (!t.data)
		initialisation_error(game, "Could not access texture data.");
	return (t);
}

/* creates the textures for each wall */
static void	initialise_textures(t_game *game)
{
	game->no_wall = new_texture(game->mlx, game->no_texture_path, game);
	game->ea_wall = new_texture(game->mlx, game->ea_texture_path, game);
	game->so_wall = new_texture(game->mlx, game->so_texture_path, game);
	game->we_wall = new_texture(game->mlx, game->we_texture_path, game);
	game->door_closed = new_texture(game->mlx, game->d_texture_path, game);
	game->door_open = new_texture(game->mlx, game->o_texture_path, game);
	game->c_color_int = save_color_int(game->c_color_code);
	game->f_color_int = save_color_int(game->f_color_code);
}

/* creates the mlx and window pointers*/
/* and intialises the textures for the walls into images used in rendering. */
/* Also initialises the ray casting info from the direction the player faces */

int	initialise_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		initialisation_error(game, "MLX initialisation failed.");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "./cub3D");
	if (game->win == NULL)
		initialisation_error(game, "Window initialisation failed.");
	game->frame.ptr = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (game->frame.ptr == NULL)
		initialisation_error(game, "Frame image initialisation failed.");
	game->frame.data = (int *)mlx_get_data_addr(game->frame.ptr,
			&game->frame.bpp, &game->frame.size_l, &game->frame.endian);
	if (game->frame.data == NULL)
		initialisation_error(game, "Frame data initialisation failed.");
	initialise_textures(game);
	init_raycasting(&game->rc, game->map);
	game->map->map_array[(int)game->map->p_posx][(int)game->map->p_posy] = '0';
	return (1);
}
