#include "../inc/cub3d.h"

static void	move_up(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (map->map_array[map->p_posy - 1][map->p_posx] != '1')
	{
		map->map_array[map->p_posy - 1][map->p_posx] = direction;
		map->map_array[map->p_posy][map->p_posx] = '0';
		map->p_posy--;
	}
}

static void	move_down(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (map->map_array[map->p_posy + 1][map->p_posx] != '1')
	{
		map->map_array[map->p_posy + 1][map->p_posx] = direction;
		map->map_array[map->p_posy][map->p_posx] = '0';
		map->p_posy++;
	}
}

static void	move_left(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (map->map_array[map->p_posy][map->p_posx - 1] != '1')
	{
		map->map_array[map->p_posy][map->p_posx - 1] = direction;
		map->map_array[map->p_posy][map->p_posx] = '0';
		map->p_posx--;
	}
}

static void	move_right(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (map->map_array[map->p_posy][map->p_posx + 1] != '1')
	{
		map->map_array[map->p_posy][map->p_posx + 1] = direction;
		map->map_array[map->p_posy][map->p_posx] = '0';
		map->p_posx++;
	}
}

void	check_move(t_game *game, int direction)
{
	//printf("player position before: x=%i, y=%i\n", game->map->p_posx, game->map->p_posy);
	if (direction == UP)
		move_up(game->map);
	if (direction == DOWN)
		move_down(game->map);
	if (direction == LEFT)
		move_left(game->map);
	if (direction == RIGHT)
		move_right(game->map);
	//printf("player position after: x=%i, y=%i\n\n", game->map->p_posx, game->map->p_posy);
}