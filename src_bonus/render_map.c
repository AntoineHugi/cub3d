/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:32:26 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 13:32:27 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y < WIN_HEIGHT / 2)
				game->frame.data[y * WIN_WIDTH + x] = game->c_color_int;
			else
				game->frame.data[y * WIN_WIDTH + x] = game->f_color_int;
			x++;
		}
		y++;
	}
}

static void	determine_texture(t_wall *wall, t_raycasting *ray, t_game *game)
{
	wall->tex = &(game->no_wall);
	if (ray->side_hit == 0 && ray->ray_dir_x > 0)
		wall->tex = &(game->ea_wall);
	else if (ray->side_hit == 0 && ray->ray_dir_x < 0)
		wall->tex = &(game->we_wall);
	else if (ray->side_hit == 1 && ray->ray_dir_y > 0)
		wall->tex = &(game->so_wall);
	else if (ray->side_hit == 1 && ray->ray_dir_y < 0)
		wall->tex = &(game->no_wall);
	if (ray->wall_hit == 2)
		wall->tex = &(game->door_closed);
}

static void	init_wall_struct(t_wall *wall, t_raycasting *ray, t_game *game)
{
	wall->line_h = (int)(WIN_HEIGHT / ray->wall_dist);
	wall->start = -(wall->line_h) / 2 + WIN_HEIGHT / 2;
	if (wall->start < 0)
		wall->start = 0;
	wall->end = wall->line_h / 2 + WIN_HEIGHT / 2;
	if (wall->end >= WIN_HEIGHT)
		wall->end = WIN_HEIGHT - 1;
	determine_texture(wall, ray, game);
	if (ray->side_hit == 0)
		wall->wall_x = game->map->p_posy + ray->wall_dist * ray->ray_dir_y;
	else
		wall->wall_x = game->map->p_posx + ray->wall_dist * ray->ray_dir_x;
	wall->wall_x -= floor(wall->wall_x);
	wall->tex_x = (int)(wall->wall_x * (double)wall->tex->width);
	if ((ray->side_hit == 0 && ray->ray_dir_x < 0)
		|| (ray->side_hit == 1 && ray->ray_dir_y > 0))
		wall->tex_x = wall->tex->width - wall->tex_x - 1;
}

static void	render_ray(t_game *game, t_raycasting *ray, int x)
{
	t_wall	wall;
	int		y;

	init_wall_struct(&wall, ray, game);
	wall.step = 1.0 * wall.tex->height / wall.line_h;
	wall.tex_pos = (wall.start - WIN_HEIGHT / 2 + wall.line_h / 2) * wall.step;
	y = wall.start;
	while (y < wall.end)
	{
		wall.tex_y = (int)wall.tex_pos % wall.tex->height;
		if (wall.tex_y < 0)
			wall.tex_y = 0;
		else if (wall.tex_y >= wall.tex->height)
			wall.tex_y = wall.tex->height - 1;
		wall.tex_pos += wall.step;
		if (wall.tex_x < 0)
			wall.tex_x = 0;
		else if (wall.tex_x >= wall.tex->width)
			wall.tex_x = wall.tex->width - 1;
		wall.color = wall.tex->data[wall.tex->height * wall.tex_y + wall.tex_x];
		game->frame.data[y * WIN_WIDTH + x] = wall.color;
		y++;
	}
}

/* then iterates through each ray and calculates the specific ray info */
/* Finally, renders that ray on the screen */
int	render_map(t_game *game)
{
	int	i;

	i = 0;
	draw_floor_ceiling(game);
	while (i < WIN_WIDTH)
	{
		calculate_raycasting(&game->rc, game->map, i);
		if (game->rc.wall_dist <= 0 || isnan(game->rc.wall_dist))
			printf("distance is 0 or negative\n");
		else
			render_ray(game, &game->rc, i);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->frame.ptr, 0, 0);
	return (0);
}
