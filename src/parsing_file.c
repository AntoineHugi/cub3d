#include "../inc/cub3d.h"

int	get_num_lines(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_array[i])
		i++;
	return (i);
}

/* checks that no elements are missing */
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

/* initialises values for some of the struct */
void	init_game_struct(t_game *game)
{
	int		i;

	i = 0;
	while (game->file_array[i] && !ft_isdigit(game->file_array[i][0]))
		i++;
	game->file_num_lines = get_num_lines(game);
	game->map_start_line = i;
	game->NO_texture_path = NULL;
	game->EA_texture_path = NULL;
	game->SO_texture_path = NULL;
	game->WE_texture_path = NULL;
	game->C_texture_path = NULL;
	game->F_texture_path = NULL;
	game->map.p_posx = 0;
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
