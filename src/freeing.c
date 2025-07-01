#include "../inc/cub3d.h"

void	free_textures(t_game *game)
{
	free(game->NO_texture_path);
	free(game->EA_texture_path);
	free(game->SO_texture_path);
	free(game->WE_texture_path);
	free(game->C_texture_path);
	free(game->F_texture_path);
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

void	free_game(t_game *game)
{
	free_array(game->file_array);
	//free_array(game->map_array);
	free_textures(game);
}