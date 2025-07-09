#include "../inc/cub3d.h"
/*
void	render_ray(t_game *game, t_map *map)
{
	
}*/

/* first checks the position of the player and set the ray starting position */
/* then iterates through each ray and calculates the specific ray info */
/* Finally, renders that ray on the screen */
void	render_map(t_game *game)
{
	int	i;

	game->rc.ray_pos_x = game->map->p_posx;
	game->rc.ray_pos_y = game->map->p_posy;
	i = 0;
	while (i < WIN_WIDTH)
	{
		calculate_raycasting(&game->rc, game->map, i);
		//render_ray(game, game->map);
		i++;
	}
}
