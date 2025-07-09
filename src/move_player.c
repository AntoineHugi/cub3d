#include "../inc/cub3d.h"

/* checks if move is possible, then moves */
static void	move_forward(t_map *map)
{
	char	**array;

	array = map->map_array;
	if (array[(int)(map->p_posy + map->p_dir_x * map->move_speed)] \
		[(int)map->p_posx] != '1')
		map->p_posy += map->p_dir_x * map->move_speed;
	if (array[(int)map->p_posy] \
		[(int)(map->p_posx + map->p_dir_y * map->move_speed)] != '1')
		map->p_posx += map->p_dir_y * map->move_speed;
}

/* checks if move is possible, then moves */
static void	move_backward(t_map *map)
{
	char	**array;

	array = map->map_array;
	if (array[(int)(map->p_posy - map->p_dir_x * map->move_speed)] \
		[(int)map->p_posx] != '1')
		map->p_posy -= map->p_dir_x * map->move_speed;
	if (array[(int)map->p_posy] \
		[(int)(map->p_posx - map->p_dir_y * map->move_speed)] != '1')
		map->p_posx -= map->p_dir_y * map->move_speed;
}

/* checks if move is possible, then moves sideways */
static void	move_left(t_map *map)
{
	char	**array;

	array = map->map_array;
	if (array[(int)(map->p_posy - (map->p_dir_y * map->move_speed))] \
		[(int)map->p_posx] != '1')
		map->p_posy -= map->p_dir_y * map->move_speed;
	if (array[(int)map->p_posy] \
		[(int)(map->p_posx + (map->p_dir_x * map->move_speed))] != '1')
		map->p_posx += map->p_dir_x * map->move_speed;
}

/* checks if move is possible, then moves sideways */
static void	move_right(t_map *map)
{
	char	**array;

	array = map->map_array;
	if (array[(int)(map->p_posy + (map->p_dir_y * map->move_speed))] \
		[(int)map->p_posx] != '1')
		map->p_posy += map->p_dir_y * map->move_speed;
	if (array[(int)map->p_posy] \
		[(int)(map->p_posx - (map->p_dir_x * map->move_speed))] != '1')
		map->p_posx -= map->p_dir_x * map->move_speed;
}

/* checks which direction to move */
void	check_move(t_game *game, int direction)
{
	update_player_dir(game->map);
	if (direction == FORWARD)
		move_forward(game->map);
	if (direction == BACKWARD)
		move_backward(game->map);
	if (direction == LEFT)
		move_left(game->map);
	if (direction == RIGHT)
		move_right(game->map);
}
