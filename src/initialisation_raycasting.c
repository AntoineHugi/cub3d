#include "../inc/cub3d.h"

/* Checks what direction the player is facing, and sets the direction and plane (edges of the vision). CPV = Camera Plane Vector */
void	get_direction_and_plane(t_game *game, t_map *map)
{
	game->rc.p_dir_x = 0;
	game->rc.p_dir_y = 0;
	game->rc.plane_x = 0;
	game->rc.plane_y = 0;
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
	{
		game->rc.p_dir_y = -1;
		game->rc.plane_x = CPV;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'S')
	{
		game->rc.p_dir_y = 1;
		game->rc.plane_x = -CPV;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'E')
	{
		game->rc.p_dir_x = 1;
		game->rc.plane_y = CPV;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'W')
	{
		game->rc.p_dir_x = -1;
		game->rc.plane_y = -CPV;
	}
}


/* on every change of view direction, calculate the necessary variables to do the ray casting. This only happens at the start of the game, or whenever the player changes direction */
void	init_raycasting(t_game *game, t_map *map)
{
	game->rc.ray_pos_x = map->p_posx;
	game->rc.ray_pos_y = map->p_posy;
	get_direction_and_plane(game, map);
}
