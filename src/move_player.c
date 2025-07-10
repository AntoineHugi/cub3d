#include "../inc/cub3d.h"

/* checks if move is possible, then moves */
static void	move_forward(t_game *game, t_map *map)
{
	char	**array;
	double	new_x;
	double	new_y;

	array = map->map_array;
	new_x = map->p_posx + game->rc.p_dir_x * map->move_speed;
	new_y = map->p_posy + game->rc.p_dir_y * map->move_speed;
	if (array[(int)new_y][(int)map->p_posx] != '1')
		map->p_posy = new_y;
	if (array[(int)map->p_posy][(int)new_x] != '1')
		map->p_posx = new_x;
}

/* checks if move is possible, then moves */
static void	move_backward(t_game *game, t_map *map)
{
	char	**array;
	double	new_x;
	double	new_y;

	array = map->map_array;
	new_x = map->p_posx - game->rc.p_dir_x * map->move_speed;
	new_y = map->p_posy - game->rc.p_dir_y * map->move_speed;
	if (array[(int)new_y][(int)map->p_posx] != '1')
		map->p_posy = new_y;
	if (array[(int)map->p_posy][(int)new_x] != '1')
		map->p_posx = new_x;
}

/* checks if move is possible, then moves sideways */
static void	move_left(t_game *game, t_map *map)
{
	char	**array;
	double	new_x;
	double	new_y;

	array = map->map_array;
	new_x = map->p_posx - game->rc.plane_x * map->move_speed;
	new_y = map->p_posy - game->rc.plane_y * map->move_speed;
	if (array[(int)map->p_posy][(int)new_x] != '1')
		map->p_posx = new_x;
	if (array[(int)new_y][(int)map->p_posx] != '1')
		map->p_posy = new_y;
}

/* checks if move is possible, then moves sideways */
static void	move_right(t_game *game, t_map *map)
{
	char	**array;
	double	new_x;
	double	new_y;

	array = map->map_array;
	new_x = map->p_posx + game->rc.plane_x * map->move_speed;
	new_y = map->p_posy + game->rc.plane_y * map->move_speed;
	if (array[(int)map->p_posy][(int)new_x] != '1')
		map->p_posx = new_x;
	if (array[(int)new_y][(int)map->p_posx] != '1')
		map->p_posy = new_y;
}

/* checks which direction to move */
void	check_move(t_game *game, int direction)
{
	if (direction == FORWARD)
		move_forward(game, game->map);
	if (direction == BACKWARD)
		move_backward(game, game->map);
	if (direction == LEFT)
		move_left(game, game->map);
	if (direction == RIGHT)
		move_right(game, game->map);
}
