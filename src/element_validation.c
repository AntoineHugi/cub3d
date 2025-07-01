#include "../inc/cub3d.h"

/* checks that the texture files can be opened (commented out since we don't have textures left)*/
/*static int	valid_textures(t_game *game)
{
	if (open(game->NO_texture_path, O_RDONLY) == -1)
		return (0);
	if (open(game->EA_texture_path, O_RDONLY) == -1)
		return (0);
	if (open(game->SO_texture_path, O_RDONLY) == -1)
		return (0);
	if (open(game->WE_texture_path, O_RDONLY) == -1)
		return (0);
	return (1);
}*/

/* checks all elements are valid */
int	valid_elements(t_game *game)
{
/*	if (!valid_textures(game))
	{
		printf("invalid textures\n");
		return (0);
	}*/
	if (!valid_colors(game))
		return (0);
	return (1);
}
