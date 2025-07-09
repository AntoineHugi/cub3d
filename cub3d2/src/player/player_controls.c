/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:16:24 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 09:58:10 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void move_player(t_game *g, double move_speed)
{
    double new_x = g->player.pos_x + g->player.dir_x * move_speed;
    double new_y = g->player.pos_y + g->player.dir_y * move_speed;
    // Collision detection
    if (g->map.grid[(int)new_y][(int)g->player.pos_x] != '1')
        g->player.pos_y = new_y;
    if (g->map.grid[(int)g->player.pos_y][(int)new_x] != '1')
        g->player.pos_x = new_x;
}

static void strafe_player(t_game *g, double move_speed)
{
    double new_x = g->player.pos_x + g->player.plane_x * move_speed;
    double new_y = g->player.pos_y + g->player.plane_y * move_speed;
    // Collision detection
    if (g->map.grid[(int)new_y][(int)g->player.pos_x] != '1')
        g->player.pos_y = new_y;
    if (g->map.grid[(int)g->player.pos_y][(int)new_x] != '1')
        g->player.pos_x = new_x;
}

static void rotate_player(t_player *p, double rot_speed)
{
    double old_dir_x = p->dir_x;
    p->dir_x = p->dir_x * cos(rot_speed) - p->dir_y * sin(rot_speed);
    p->dir_y = old_dir_x * sin(rot_speed) + p->dir_y * cos(rot_speed);
    double old_plane_x = p->plane_x;
    p->plane_x = p->plane_x * cos(rot_speed) - p->plane_y * sin(rot_speed);
    p->plane_y = old_plane_x * sin(rot_speed) + p->plane_y * cos(rot_speed);
}

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == K_ESC)
        exit_game(game);
    if (keycode == K_W)
        move_player(game, MOVE_SPEED);
    if (keycode == K_S)
        move_player(game, -MOVE_SPEED);
    if (keycode == K_A)
        strafe_player(game, -MOVE_SPEED);
    if (keycode == K_D)
        strafe_player(game, MOVE_SPEED);
    if (keycode == K_LEFT)
        rotate_player(&game->player, -ROT_SPEED);
    if (keycode == K_RIGHT)
        rotate_player(&game->player, ROT_SPEED);
    return (0);
}
