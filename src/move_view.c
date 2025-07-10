#include "../inc/cub3d.h"

/* checks which direction to rotate*/
/* and recalculates the plane and direction for the raycasting */
void	turn_view(t_game *game, int direction)
{
	if (direction == LEFT)
		game->map->p_angle -= game->map->rotation_speed;
	if (direction == RIGHT)
		game->map->p_angle += game->map->rotation_speed;
	game->map->p_dir_x = cos(game->map->p_angle);
	game->map->p_dir_y = -sin(game->map->p_angle);
	init_raycasting(&game->rc, game->map);
}
