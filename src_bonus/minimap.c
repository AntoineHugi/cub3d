/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:17:15 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/17 12:20:50 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Puts a single pixel of a given color into the image data buffer.
// This is a utility function to draw a pixel at coordinates (x, y) on the
// specified image. It checks for boundary conditions to prevent segfaults.
static void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		img->data[y * (img->size_l / 4) + x] = color;
}

// Draws a square tile on the minimap.
// This function draws a square of size MINIMAP_SCALE * MINIMAP_SCALE at a
// specified screen position with a given color.
static void	draw_minimap_tile(t_game *game, int map_x, int map_y, int color)
{
	int	pixel_x;
	int	pixel_y;
	int	i;
	int	j;

	pixel_x = map_x * MINIMAP_SCALE + MINIMAP_BORDER;
	pixel_y = map_y * MINIMAP_SCALE + MINIMAP_BORDER;
	i = 0;
	while (i < MINIMAP_SCALE)
	{
		j = 0;
		while (j < MINIMAP_SCALE)
		{
			put_pixel_to_img(&game->frame, pixel_x + j, pixel_y + i, color);
			j++;
		}
		i++;
	}
}

// Draws the player's position on the minimap. The player is
// represented by a small square centered on their exact coordinates.
static void	draw_player_on_minimap(t_game *game)
{
	int	player_screen_x;
	int	player_screen_y;
	int	i;
	int	j;

	player_screen_x = (int)(game->map->p_posx * MINIMAP_SCALE) + MINIMAP_BORDER;
	player_screen_y = (int)(game->map->p_posy * MINIMAP_SCALE) + MINIMAP_BORDER;
	i = -PLAYER_SIZE / 2;
	while (i <= PLAYER_SIZE / 2)
	{
		j = -PLAYER_SIZE / 2;
		while (j <= PLAYER_SIZE / 2)
		{
			put_pixel_to_img(&game->frame, player_screen_x + j, player_screen_y
				+ i, PLAYER_COLOR);
			j++;
		}
		i++;
	}
}

// Renders the entire minimap, including walls, floor, and the player.
// This function iterates through the game map and draws each tile on the
// screen-space minimap based on its type (wall, floor, etc.). It then
// calls a function to draw the player on top.
void	render_minimap(t_game *game)
{
	int		x;
	int		y;
	char	tile;

	y = 0;
	while (y < game->map->map_height)
	{
		x = 0;
		while (x < game->map->map_width)
		{
			tile = game->map->map_array[y][x];
			if (tile == '1')
				draw_minimap_tile(game, x, y, WALL_COLOR);
			else if (ft_strchr("0NSEWD", tile))
				draw_minimap_tile(game, x, y, FLOOR_COLOR);
			x++;
		}
		y++;
	}
	draw_player_on_minimap(game);
}
