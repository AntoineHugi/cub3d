#include "../inc/cub3d.h"

/* updates the direction used in moving */
void	update_player_dir(t_map *map)
{
	if (map->p_view == 'N')
	{
		map->p_dir_x = 0;
		map->p_dir_y = -1;
	}
	else if (map->p_view == 'S')
	{
		map->p_dir_x = 0;
		map->p_dir_y = 1;
	}
	else if (map->p_view == 'E')
	{
		map->p_dir_x = 1;
		map->p_dir_y = 0;
	}
	else if (map->p_view == 'W')
	{
		map->p_dir_x = -1;
		map->p_dir_y = 0;
	}
}

/* checks current view, then rotates */
static void	look_right(t_map *map)
{
	if (map->p_view == 'N')
		map->p_view = 'E';
	else if (map->p_view == 'S')
		map->p_view = 'W';
	else if (map->p_view == 'E')
		map->p_view = 'S';
	else if (map->p_view == 'W')
		map->p_view = 'N';
}

/* checks current view, then rotates */
static void	look_left(t_map *map)
{
	if (map->p_view == 'N')
		map->p_view = 'W';
	else if (map->p_view == 'S')
		map->p_view = 'E';
	else if (map->p_view == 'E')
		map->p_view = 'N';
	else if (map->p_view == 'W')
		map->p_view = 'S';
}

/* checks which direction to rotate*/
/* and recalculates the plane and direction for the raycasting */
void	turn_view(t_game *game, int direction)
{
	if (direction == LEFT)
		look_left(game->map);
	if (direction == RIGHT)
		look_right(game->map);
	update_player_dir(game->map);
	init_raycasting(&game->rc, game->map);
}
