#include "../inc/cub3d.h"

/* checks if move is possible, then moves (keeping the same view direction) */
static void	move_forward(t_map *map)
{
	char	view;
	char	**array;

	array = map->map_array;
	view = array[map->p_posy][map->p_posx];
	if (array[map->p_posy + map->p_dir_y][map->p_posx + map->p_dir_x] != '1')
	{
		array[map->p_posy + map->p_dir_y][map->p_posx + map->p_dir_x] = view;
		array[map->p_posy][map->p_posx] = '0';
		map->p_posx = map->p_posx + map->p_dir_x;
		map->p_posy = map->p_posy + map->p_dir_y;
	}
}

/* checks if move is possible, then moves (keeping the same view direction) */
static void	move_backward(t_map *map)
{
	char	view;
	char	**array;

	array = map->map_array;
	view = array[map->p_posy][map->p_posx];
	if (array[map->p_posy - map->p_dir_y][map->p_posx - map->p_dir_x] != '1')
	{
		array[map->p_posy - map->p_dir_y][map->p_posx - map->p_dir_x] = view;
		array[map->p_posy][map->p_posx] = '0';
		map->p_posx = map->p_posx - map->p_dir_x;
		map->p_posy = map->p_posy - map->p_dir_y;
	}
}

/* checks if move is possible, then moves (keeping the same view direction) */
static void	move_left(t_map *map)
{
	char	view;
	char	**array;

	array = map->map_array;
	view = array[map->p_posy][map->p_posx];
	if (array[map->p_posy + map->p_dir_x][map->p_posx + map->p_dir_y] != '1')
	{
		array[map->p_posy + map->p_dir_x][map->p_posx + map->p_dir_y] = view;
		array[map->p_posy][map->p_posx] = '0';
		map->p_posx = map->p_posx + map->p_dir_y;
		map->p_posy = map->p_posy + map->p_dir_x;
	}
}

/* checks if move is possible, then moves (keeping the same view direction) */
static void	move_right(t_map *map)
{
	char	view;
	char	**array;

	array = map->map_array;
	view = array[map->p_posy][map->p_posx];
	if (array[map->p_posy - map->p_dir_x][map->p_posx - map->p_dir_y] != '1')
	{
		array[map->p_posy - map->p_dir_x][map->p_posx - map->p_dir_y] = view;
		array[map->p_posy][map->p_posx] = '0';
		map->p_posx = map->p_posx - map->p_dir_y;
		map->p_posy = map->p_posy - map->p_dir_x;
	}
}
/* checks which direction to move */
void	check_move(t_game *game, int direction)
{
	printf("player view direction: %c\n", game->map->map_array[game->map->p_posy][game->map->p_posx]);
	printf("player position before: x=%i:y=%i\n", game->map->p_posx, game->map->p_posy);
	update_player_dir(game->map);
	if (direction == FORWARD)
		move_forward(game->map);
	if (direction == BACKWARD)
		move_backward(game->map);
	if (direction == LEFT)
		move_left(game->map);
	if (direction == RIGHT)
		move_right(game->map);
	printf("player position after: x=%i:y=%i\n\n", game->map->p_posx, game->map->p_posy);
}