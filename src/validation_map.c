#include "../inc/cub3d.h"

int	map_not_last(t_game *game)
{
	if (game->map_start_line + game->map->map_height < game->file_num_lines)
	{
		printf("Map is not at the end of the file.\n");
		return (1);
	}
	return (0);
}

int	invalid_player_num(t_map *map, int i, int j)
{
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (map->map_array[i][j] == 'N' || map->map_array[i][j] == 'E'
				|| map->map_array[i][j] == 'S' || map->map_array[i][j] == 'W')
			{
				if (map->p_posx != -1)
				{
					printf("Too many players.\n");
					return (1);
				}
				else
				{
					map->p_posx = j;
					map->p_posy = i;
					map->p_dir = map->map_array[i][j];
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_map_element(char **array, int map_start)
{
	int	i;
	int	j;

	i = map_start;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != ' ' && array[i][j] != '1'
				&& array[i][j] != '0' && array[i][j] != 'N'
				&& array[i][j] != 'E' && array[i][j] != 'S'
				&& array[i][j] != 'W')
				{
					printf("Invalid element on the map.\n");
					return (1);
				}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_not_closed(t_map *map, int x, int y)
{
	int enclosed;

	//printf("x = %i, y = %i\n", x, y);
	//printf("map height = %i, map width = %i\n", map->map_height, map->map_width);

	//printf("map at xy = %i\n", map->map_validation[y][x]);
	enclosed = 0;
	if (x < 0 || y < 0 || x >= map->map_width || y >= map->map_height)
		return 1;
	if (map->map_validation[y][x] == ' ' || map->map_validation[y][x] == '\0')
		return 1;
	if (map->map_validation[y][x] == '1')
		return 0;
	map->map_validation[y][x] = '1';
	enclosed += map_not_closed(map, x + 1, y);
	enclosed += map_not_closed(map, x - 1, y);
	enclosed += map_not_closed(map, x, y + 1);
	enclosed += map_not_closed(map, x, y - 1);
	return enclosed;
}

int	valid_map(t_game *game)
{
	if (invalid_map_element(game->file_array, game->map_start_line))
		return (0);
	game->map = create_map(game);
	if (!game->map)
		return (0);
	if (map_not_last(game))
		return (0);
	if (invalid_player_num(game->map, 0, 0))
		return (0);
	if (game->map->p_posx == -1)
	{
		printf("No players.\n");
		return (0);
	}
	if (map_not_closed(game->map, game->map->p_posx, game->map->p_posy))
	{
		printf("Map is not closed.\n");
		return (0);
	}
	return (1);
}
