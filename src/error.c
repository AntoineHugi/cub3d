#include "../inc/cub3d.h"

void	validation_error(t_game *game)
{
	free_game(game);
	exit (1);
}