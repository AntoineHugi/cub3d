#include "../inc/cub3d.h"

int	get_num_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_array[i])
		i++;
	return (i);
}

int	get_map_start_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file_array[i])
	{
		j = 0;
		while (game->file_array[i][j] == ' ' || game->file_array[i][j] == '\t' 
			|| game->file_array[i][j] == '\r' || game->file_array[i][j] == '\f')
			j++;
		if (game->file_array[i][j] == '1')
			break ;
		i++;
	}
	return (i);
}

/* checks that no elements are missing */
int	all_elements(t_game *game)
{
	if (game->no_texture_path == NULL)
		return (0);
	if (game->ea_texture_path == NULL)
		return (0);
	if (game->so_texture_path == NULL)
		return (0);
	if (game->we_texture_path == NULL)
		return (0);
	if (game->c_texture_path == NULL)
		return (0);
	if (game->f_texture_path == NULL)
		return (0);
	return (1);
}

/* initialises values for some of the struct */
void	init_game_struct(t_game *game)
{
	game->file_num_lines = get_num_lines(game);
	game->map_start_line = get_map_start_line(game);
	game->map = NULL;
	game->no_texture_path = NULL;
	game->ea_texture_path = NULL;
	game->so_texture_path = NULL;
	game->we_texture_path = NULL;
	game->c_texture_path = NULL;
	game->f_texture_path = NULL;
}

/* parsing the file to check the two parts: elements and map */
int	parsing_file(t_game *game)
{
	init_game_struct(game);
	if (!parsing_element(game))
		parsing_error(game, "Invalid element line.\n");
	if (!all_elements(game))
		parsing_error(game, "Some element types are missing\n");
	if (!valid_elements(game))
		parsing_error(game, "Element(s) are invalid\n");
	if (parsing_map(game))
	{
		return (1);
	}	
	return (1);
}
