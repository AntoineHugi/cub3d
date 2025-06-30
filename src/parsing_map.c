#include "../inc/cub3d.h"

int	invalid_player_num(t_game *game, int i)
{
	int	j;
	
	while (game->file_array[i])
	{
		j = 0;
		while (game->file_array[i][j])
		{
			if (game->file_array[i][j] == 'N' 
				|| game->file_array[i][j] == 'E' 
				|| game->file_array[i][j] == 'S' 
				|| game->file_array[i][j] == 'W')
			{
				if (game->p_posx)
					return (1);
				else
				{
					game->p_posx = j;
					game->p_posy = i - game->map_start_line;
					game->p_dir = game->file_array[i][j];
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_map_element(char **array, int i)
{
	int	j;

	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] != ' ' && array[i][j] != '1' 
				&& array[i][j] != '0' && array[i][j] != 'N' 
				&& array[i][j] != 'E' && array[i][j] != 'S' 
				&& array[i][j] != 'W')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parsing_map(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	game->p_posx = 0;
	while (game->file_array[i] && !ft_isdigit(game->file_array[i][0]))
		i++;
	game->map_start_line = i;
	if (invalid_map_element(game->file_array, i))
	{
		printf("invalid map element\n");
		return (0);
	}
	if (invalid_player_num(game, i))
	{
		printf("invalid player num\n");
		return (0);
	}
	return (1);
}