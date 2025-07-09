/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:13:29 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 09:57:27 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void draw_floor_ceiling(t_game *game)
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            if (y < SCREEN_HEIGHT / 2)
                game->frame.data[y * SCREEN_WIDTH + x] = game->config.ceiling_color;
            else
                game->frame.data[y * SCREEN_WIDTH + x] = game->config.floor_color;
        }
    }
}

static void draw_wall_slice(t_game *g, t_ray *ray, int x)
{
    int line_h = (int)(SCREEN_HEIGHT / ray->perp_wall_dist);
    int draw_start = -line_h / 2 + SCREEN_HEIGHT / 2;
    if (draw_start < 0) draw_start = 0;
    int draw_end = line_h / 2 + SCREEN_HEIGHT / 2;
    if (draw_end >= SCREEN_HEIGHT) draw_end = SCREEN_HEIGHT - 1;

    int tex_num = 0; // Determine texture based on side and ray direction
    if (ray->side == 0 && ray->dir_x > 0) tex_num = 3; // East
    else if (ray->side == 0) tex_num = 2; // West
    else if (ray->side == 1 && ray->dir_y > 0) tex_num = 1; // South
    else tex_num = 0; // North

    double wall_x; // Where exactly the wall was hit
    if (ray->side == 0) wall_x = g->player.pos_y + ray->perp_wall_dist * ray->dir_y;
    else wall_x = g->player.pos_x + ray->perp_wall_dist * ray->dir_x;
    wall_x -= floor(wall_x);

    int tex_x = (int)(wall_x * (double)TEXTURE_WIDTH);
    if ((ray->side == 0 && ray->dir_x < 0) || (ray->side == 1 && ray->dir_y > 0))
        tex_x = TEXTURE_WIDTH - tex_x - 1;

    double step = 1.0 * TEXTURE_HEIGHT / line_h;
    double tex_pos = (draw_start - SCREEN_HEIGHT / 2 + line_h / 2) * step;

    for (int y = draw_start; y <= draw_end; y++)
    {
        int tex_y = (int)tex_pos & (TEXTURE_HEIGHT - 1);
        tex_pos += step;
        int color = g->textures[tex_num].data[TEXTURE_HEIGHT * tex_y + tex_x];
        g->frame.data[y * SCREEN_WIDTH + x] = color;
    }
}

int render_next_frame(t_game *game)
{
    draw_floor_ceiling(game);
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        t_ray ray;
        ray.camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
        ray.dir_x = game->player.dir_x + game->player.plane_x * ray.camera_x;
        ray.dir_y = game->player.dir_y + game->player.plane_y * ray.camera_x;

        perform_raycasting(game, &ray);
        draw_wall_slice(game, &ray, x);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->frame.ptr, 0, 0);
    return (0);
}
