#include "../inc/cub3d.h"
/*
void	render_ray(t_game *game, t_map *map)
{
	
}*/

/* first initialises the raycasting info that will stay constant for each ray, then iterates through each ray and calculates the ray info specific to that ray. Finally, renders that ray on the screen */
void	render_map(t_game *game)
{
	int	i;

	game->rc.ray_pos_x = game->map->p_posx;
	game->rc.ray_pos_y = game->map->p_posy;
	i = 0;
	while (i < WIN_WIDTH)
	{
		calculate_raycasting(game, game->map, i);
		//render_ray(game, game->map);
		i++;
	}
}
