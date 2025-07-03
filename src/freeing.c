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
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_map(t_map *map)
{
	if (!map)
		return;
	free_array(map->map_array);
	free_array(map->map_validation);
	free(map);
}

/* Frees the game struct */
void	free_game(t_game *game)
{
	free_array(game->file_array);
	free_map(game->map);
	free_textures(game);
}