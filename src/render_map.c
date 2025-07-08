#include "../inc/cub3d.h"

/* iterates step by step until we hit a wall, and checks if this wall was hit on the x axis or the y axis */
void	cast_ray(t_game *game, t_map *map)
{
	int	hit;
	int	side;

	hit = 0;
	if (game->rc.ray_dir_x < 0)
		game->rc.side_dist_x = (game->map->p_posx - game->rc.ray_pos_x) * game->rc.delta_dist_x;
	else
		game->rc.side_dist_x = (game->rc.ray_pos_x + 1.0 - game->map->p_posx) * game->rc.delta_dist_x;
	if (game->rc.ray_dir_y < 0)
		game->rc.side_dist_y = (game->map->p_posy - game->rc.ray_pos_y) * game->rc.delta_dist_y;
	else
		game->rc.side_dist_y = (game->rc.ray_pos_y + 1.0 - game->map->p_posy) * game->rc.delta_dist_y;
	while (!hit)
	{
		if (game->rc.side_dist_x < game->rc.side_dist_y) 
		{
			game->rc.side_dist_x += game->rc.delta_dist_x;
			game->rc.ray_pos_x += game->rc.step_x;
			side = 0;
        }
		else
		{
			game->rc.side_dist_y += game->rc.delta_dist_y;
			game->rc.ray_pos_y += game->rc.step_y;
			side = 1;
		}
		if (map->map_array[game->rc.ray_pos_y][game->rc.ray_pos_x] == '1') 
			hit = 1;
    }
	if (side == 0)
		game->rc.wall_dist = (game->rc.ray_pos_x - map->p_posx + (1 - game->rc.step_x) / 2) / game->rc.ray_dir_x;
	else
        game->rc.wall_dist = (game->rc.ray_pos_y - map->p_posy + (1 - game->rc.step_y) / 2) / game->rc.ray_dir_y;
}

/* on every interation, calculate the necessary variables to do the ray casting, based on direction */
/* might need to move this elsewhere and break it down more */
void	define_raycasting(t_game *game, t_map *map, int i)
{
	game->rc.p_dir[0] = 0;
	game->rc.p_dir[1] = 0;
	game->rc.ray_pos_x = (int)game->map->p_posx;
	game->rc.ray_pos_y = (int)game->map->p_posy;
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
		game->rc.p_dir[1] = -1;
	if (map->map_array[map->p_posy][map->p_posx] == 'S')
		game->rc.p_dir[1] = 1;
	if (map->map_array[map->p_posy][map->p_posx] == 'E')
		game->rc.p_dir[0] = 1;
	if (map->map_array[map->p_posy][map->p_posx] == 'W')
		game->rc.p_dir[0] = -1;
	game->rc.screen_pos = 2 * i / (double)WIN_WIDTH - 1;
	game->rc.ray_dir_x = game->rc.p_dir[0] + CPL * game->rc.screen_pos;
	game->rc.ray_dir_y = game->rc.p_dir[1] + CPL * game->rc.screen_pos;
	if (game->rc.ray_dir_x < 0)
		game->rc.step_x = -1;
	else
		game->rc.step_x = 1;
	if (game->rc.ray_dir_y < 0)
		game->rc.step_y = -1;
	else
		game->rc.step_y = 1;
	game->rc.delta_dist_x = fabs(1 / game->rc.ray_dir_x);
    game->rc.delta_dist_y = fabs(1 / game->rc.ray_dir_y);
}

/* iterates through each pixel in width and casts a ray for each */
/* currently doesn't quite work it seems, getting a 0.0 distance in some cases */
void	render_map(t_game *game)
{
	int	i;
	printf("\n");
	i = 0;
	while (i < WIN_WIDTH)
	{
		define_raycasting(game, game->map, i);	
		cast_ray(game, game->map);
		if (i == WIN_WIDTH/2)
			printf("d #%i=%.2f| ", i, game->rc.wall_dist);
		i++;
	}
	
	printf("player facing %c, direction on x is %i, direction on y is %i\n", game->map->map_array[game->map->p_posy][game->map->p_posx], game->rc.p_dir[0], game->rc.p_dir[1]);

}
