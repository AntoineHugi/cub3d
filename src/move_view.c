#include "../inc/cub3d.h"

static void	look_right(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (direction == 'N')
		map->map_array[map->p_posy][map->p_posx] = 'E';
	if (direction == 'E')
		map->map_array[map->p_posy][map->p_posx] = 'S';
	if (direction == 'S')
		map->map_array[map->p_posy][map->p_posx] = 'W';
	if (direction == 'W')
		map->map_array[map->p_posy][map->p_posx] = 'N';
}

static void	look_left(t_map *map)
{
	char	direction;

	direction = map->map_array[map->p_posy][map->p_posx];
	if (direction == 'N')
		map->map_array[map->p_posy][map->p_posx] = 'W';
	if (direction == 'E')
		map->map_array[map->p_posy][map->p_posx] = 'N';
	if (direction == 'S')
		map->map_array[map->p_posy][map->p_posx] = 'E';
	if (direction == 'W')
		map->map_array[map->p_posy][map->p_posx] = 'S';
}

void	turn_view(t_game *game, int direction)
{
	//printf("player direction before:%c\n", game->map->map_array[game->map->p_posy][game->map->p_posx]);
	if (direction == LEFT)
		look_left(game->map);
	if (direction == RIGHT)
		look_right(game->map);
	//printf("player direction after:%c\n\n", game->map->map_array[game->map->p_posy][game->map->p_posx]);
}