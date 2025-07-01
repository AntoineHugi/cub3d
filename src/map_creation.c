#include "../inc/cub3d.h"

char	**create_map_array(t_game *game, t_map *map)
{
	
}

int	get_map_heigth(t_game *game, int i)
{
	int	j;
	int	height;

	height = i;
	while (game->file_array[i])
	{
		j = 0;
		while (game->file_array[i][j] == ' ' || game->file_array[i][j] == '\t' 
			|| game->file_array[i][j] == '\r' || game->file_array[i][j] == '\f')
			j++;
		if (game->file_array[i][j] != '1')
			break ;
		i++;
	}
	return (i - height);
}

int	get_map_width(t_game *game)
{
	int	i;
	int	max_width;

	i = game->map_start_line;
	max_width = 0;
	while (game->file_array[i] && ft_isdigit(game->file_array[i][0]))
	{
		if (ft_strlen(game->file_array[i]) > max_width)
			max_width = ft_strlen(game->file_array[i]);
		i++;
	}
	return (max_width);
}

/* Not used yet */
t_map	*create_map(t_game *game)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(map));
	map->map_width = get_map_width(game);
	map->map_height = get_map_heigth(game, game->map_start_line);
	map->p_posx == -1;
	map->p_posy == -1;
	map->p_posx == '\0';
	map->map_array = create_map_array(game, map);
}
