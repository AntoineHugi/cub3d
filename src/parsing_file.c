#include "../inc/cub3d.h"

int	get_num_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_array[i])
		i++;
	return (i);
}

int	all_elements(t_game *game)
{
	if (game->NO_texture_path == NULL)
		return (0);
	if (game->EA_texture_path == NULL)
		return (0);
	if (game->SO_texture_path == NULL)
		return (0);
	if (game->WE_texture_path == NULL)
		return (0);
	if (game->C_texture_path == NULL)
		return (0);
	if (game->F_texture_path == NULL)
		return (0);
	return (1);
}

int	parsing_file(t_game *game)
{
	game->file_num_lines = get_num_lines(game);
	if (!parsing_element(game))
	{
		printf("parsing element didn't work\n");
		return (0);
	}
	if (!all_elements(game))
	{
		printf("parsing all element didn't work\n");
		return (0);
	}
	if (!parsing_map(game))
	{
		printf("parsing map didn't work\n");	
		return (0);
	}
	return (1);
}
