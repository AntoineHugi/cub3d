#include "../inc/cub3d.h"

void	free_textures(t_game *game)
{
	free(game->no_texture_path);
	free(game->ea_texture_path);
	free(game->so_texture_path);
	free(game->we_texture_path);
	free(game->c_texture_path);
	free(game->f_texture_path);
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}

/* Frees the game struct */
void	free_game(t_game *game)
{
	free_array(game->file_array);
	//free_array(game->map_array);
	free_textures(game);
}