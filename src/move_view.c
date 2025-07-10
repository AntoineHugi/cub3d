#include "../inc/cub3d.h"

/* checks which direction to rotate*/
/* and recalculates the plane and direction for the raycasting */
void	turn_view(t_game *game, int direction)
{
	double	fov;
	double	cpv;

	fov = 60 * (3.141592 / 180);
	cpv = tan(fov / 2);
	if (direction == LEFT)
		game->map->p_angle += game->map->rotation_speed;
	if (direction == RIGHT)
		game->map->p_angle -= game->map->rotation_speed;
	if (game->map->p_angle < 0)
		game->map->p_angle += 2 * PI;
	if (game->map->p_angle >= 2 * PI)
		game->map->p_angle -= 2 * PI;
	game->rc.p_dir_x = cos(game->map->p_angle);
	game->rc.p_dir_y = -sin(game->map->p_angle);
	game->rc.plane_x = -cpv * game->rc.p_dir_y;
	game->rc.plane_y = cpv * game->rc.p_dir_x;
}
