/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:00:00 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/18 10:35:33 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	put_pixel_to_frame(t_game *game, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
	{
		if (color != TRANSPARENT_COLOR)
			game->frame.data[y * (game->frame.size_l / 4) + x] = color;
	}
}

static void	draw_sprite_stripe(t_game *g, t_sprite_vars *s, t_sprite *spr,
		int stripe)
{
	int	y;
	int	d;
	int	color;

	s->tex_x = (int)(256 * (stripe - (-s->sprite_width / 2
					+ s->sprite_screen_x)) * spr->tex[spr->frame]->width
			/ s->sprite_width) / 256;
	if (s->transform_y > 0 && stripe > 0 && stripe < WIN_WIDTH
		&& s->transform_y < g->rc.z_buffer[stripe])
	{
		y = s->draw_start_y;
		while (y < s->draw_end_y)
		{
			d = y * 256 - WIN_HEIGHT * 128 + s->sprite_height * 128;
			s->tex_y = ((d * spr->tex[spr->frame]->height) / s->sprite_height)
				/ 256;
			color = spr->tex[spr->frame]->data[s->tex_y
				* spr->tex[spr->frame]->width + s->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				g->frame.data[y * WIN_WIDTH + stripe] = color;
			y++;
		}
	}
}

static void	calculate_sprite_dimensions(t_sprite_vars *s)
{
	s->sprite_height = abs((int)(WIN_HEIGHT / s->transform_y));
	s->draw_start_y = -s->sprite_height / 2 + WIN_HEIGHT / 2;
	if (s->draw_start_y < 0)
		s->draw_start_y = 0;
	s->draw_end_y = s->sprite_height / 2 + WIN_HEIGHT / 2;
	if (s->draw_end_y >= WIN_HEIGHT)
		s->draw_end_y = WIN_HEIGHT - 1;
	s->sprite_width = abs((int)(WIN_HEIGHT / s->transform_y));
	s->draw_start_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_start_x < 0)
		s->draw_start_x = 0;
	s->draw_end_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->draw_end_x >= WIN_WIDTH)
		s->draw_end_x = WIN_WIDTH - 1;
}

void	render_sprites(t_game *game)
{
	int				i;
	int				stripe;
	t_sprite_vars	s;

	if (game->sprite_count == 0)
		return ;
	sort_sprites(game);
	i = 0;
	while (i < game->sprite_count)
	{
		update_sprite_animation(&game->sprites[i]);
		transform_sprite(game, &s, &game->sprites[i]);
		calculate_sprite_dimensions(&s);
		stripe = s.draw_start_x;
		while (stripe < s.draw_end_x)
		{
			draw_sprite_stripe(game, &s, &game->sprites[i], stripe);
			stripe++;
		}
		i++;
	}
}
