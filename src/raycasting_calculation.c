#include "../inc/cub3d.h"

/* calculates the delta distance a ray travels to move by one grid line (either on the x-axis or the y-axis), and calculates the step for each iteration (the direction the ray is moving on the x/y axis) */
void	get_distance_and_step(t_game *game, t_map *map)
{
	game->rc.delta_dist_x = fabs(1 / game->rc.ray_dir_x);
	game->rc.delta_dist_y = fabs(1 / game->rc.ray_dir_y);
	if (game->rc.ray_dir_x < 0)
		game->rc.step_x = -1;
	else
		game->rc.step_x = 1;
	if (game->rc.ray_dir_y < 0)
		game->rc.step_y = -1;
	else
		game->rc.step_y = 1;
	if (game->rc.ray_dir_x < 0)
		game->rc.side_dist_x = (map->p_posx - game->rc.ray_pos_x) \
			* game->rc.delta_dist_x;
	else
		game->rc.side_dist_x = (game->rc.ray_pos_x + 1.0 - map->p_posx) \
			* game->rc.delta_dist_x;
	if (game->rc.ray_dir_y < 0)
		game->rc.side_dist_y = (map->p_posy - game->rc.ray_pos_y) \
			* game->rc.delta_dist_y;
	else
		game->rc.side_dist_y = (game->rc.ray_pos_y + 1.0 - map->p_posy) \
			* game->rc.delta_dist_y;
}

/* logs the distance of the wall compared to the player */
void	get_wall_distance(t_game *game, t_map *map)
{
	if (game->rc.side_hit == 0)
		game->rc.wall_dist = (game->rc.ray_pos_x - map->p_posx \
			+ (1 - game->rc.step_x) / 2) / game->rc.ray_dir_x;
	else
		game->rc.wall_dist = (game->rc.ray_pos_y - map->p_posy \
			+ (1 - game->rc.step_y) / 2) / game->rc.ray_dir_y;
}

/* iterates step by step until we hit a wall, and checks if this wall was hit on the x axis or the y axis */
void	cast_ray(t_game *game, t_map *map)
{
	while (!game->rc.hit_wall)
	{
		if (game->rc.side_dist_x < game->rc.side_dist_y) 
		{
			game->rc.side_dist_x += game->rc.delta_dist_x;
			game->rc.ray_pos_x += game->rc.step_x;
			game->rc.side_hit = 0;
		}
		else
		{
			game->rc.side_dist_y += game->rc.delta_dist_y;
			game->rc.ray_pos_y += game->rc.step_y;
			game->rc.side_hit = 1;
		}
		if (game->rc.ray_pos_x < 0 || game->rc.ray_pos_x >= map->map_width
			|| game->rc.ray_pos_y < 0 || game->rc.ray_pos_y >= map->map_height)
			break ;
		if (map->map_array[game->rc.ray_pos_y][game->rc.ray_pos_x] == '1') 
			game->rc.hit_wall = 1;
	}
}

/* Calculates for each ray the direction of the ray, the distance it travels per grid and then casts the ray and logs the distance it travelled */
void	calculate_raycasting(t_game *game, t_map *map, int i)
{
	game->rc.hit_wall = 0;
	game->rc.screen_pos = 2 * i / (double)WIN_WIDTH - 1;
	game->rc.ray_dir_x = game->rc.p_dir_x + game->rc.plane_x * game->rc.screen_pos;
	game->rc.ray_dir_y = game->rc.p_dir_y + game->rc.plane_y * game->rc.screen_pos;
	get_distance_and_step(game, map);
	cast_ray(game, map);
	get_wall_distance(game, map);
}
