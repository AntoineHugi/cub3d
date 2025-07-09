#include "../inc/cub3d.h"

void	validation_error(t_game *game)
{
	free_game(game);
	exit (1);
}

void	initialisation_error(t_game *game, char *error_msg)
{
	printf("%s\n", error_msg);
	free_game(game);
	exit (1);
}
