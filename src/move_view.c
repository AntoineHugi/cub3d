#include "../inc/cub3d.h"

/* updates the direction used in moving */
void	update_player_dir(t_map *map)
{
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
	{
		map->p_dir_x = 0;
		map->p_dir_y = -1;
	}
	else if (map->map_array[map->p_posy][map->p_posx] == 'S')
	{
		map->p_dir_x = 0;
		map->p_dir_y = 1;
	}
	else if (map->map_array[map->p_posy][map->p_posx] == 'E')
	{
		map->p_dir_x = 1;
		map->p_dir_y = 0;
	}
	else if (map->map_array[map->p_posy][map->p_posx] == 'W')
	{
		map->p_dir_x = -1;
		map->p_dir_y = 0;
	}
}

/* checks current view, then rotates */
static void	look_right(t_map *map)
{
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
		map->map_array[map->p_posy][map->p_posx] = 'E';
	else if (map->map_array[map->p_posy][map->p_posx] == 'S')
		map->map_array[map->p_posy][map->p_posx] = 'W';
	else if (map->map_array[map->p_posy][map->p_posx] == 'E')
		map->map_array[map->p_posy][map->p_posx] = 'S';
	else if (map->map_array[map->p_posy][map->p_posx] == 'W')
		map->map_array[map->p_posy][map->p_posx] = 'N';
}

/* checks current view, then rotates */
static void	look_left(t_map *map)
{
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
		map->map_array[map->p_posy][map->p_posx] = 'W';
	else if (map->map_array[map->p_posy][map->p_posx] == 'S')
		map->map_array[map->p_posy][map->p_posx] = 'E';
	else if (map->map_array[map->p_posy][map->p_posx] == 'E')
		map->map_array[map->p_posy][map->p_posx] = 'N';
	else if (map->map_array[map->p_posy][map->p_posx] == 'W')
		map->map_array[map->p_posy][map->p_posx] = 'S';
}

/* checks which direction to rotate*/
/* and recalculates the plane and direction for the raycasting */
void	turn_view(t_game *game, int direction)
{
	//printf("player view direction before: %c\n", game->map->map_array[game->map->p_posy][game->map->p_posx]);
	if (direction == LEFT)
		look_left(game->map);
	if (direction == RIGHT)
		look_right(game->map);
	//printf("player position: x=%i:y=%i\n", game->map->p_posx, game->map->p_posy);
	update_player_dir(game->map);
	init_raycasting(&game->rc, game->map);
	//printf("player view direction after: %c\n\n", game->map->map_array[game->map->p_posy][game->map->p_posx]);
}
