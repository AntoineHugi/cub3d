/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:01:00 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/18 10:36:02 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	update_sprite_animation(t_sprite *sprite)
{
	sprite->anim_timer++;
	if (sprite->anim_timer > ANIMATION_SPEED)
	{
		sprite->frame = (sprite->frame + 1) % 2;
		sprite->anim_timer = 0;
	}
}

void	transform_sprite(t_game *game, t_sprite_vars *s, t_sprite *sprite)
{
	s->sprite_x = sprite->x - game->map->p_posx;
	s->sprite_y = sprite->y - game->map->p_posy;
	s->inv_det = 1.0 / (game->rc.plane_x * game->rc.p_dir_y - game->rc.p_dir_x
			* game->rc.plane_y);
	s->transform_x = s->inv_det * (game->rc.p_dir_y * s->sprite_x
			- game->rc.p_dir_x * s->sprite_y);
	s->transform_y = s->inv_det * (-game->rc.plane_y * s->sprite_x
			+ game->rc.plane_x * s->sprite_y);
	s->sprite_screen_x = (int)((WIN_WIDTH / 2) * (1 + s->transform_x
				/ s->transform_y));
}
