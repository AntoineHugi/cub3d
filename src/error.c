#include "../inc/cub3d.h"

void	parsing_error(t_game *game, char *err_msg)
{
	write(1, err_msg, ft_strlen(err_msg));
	free_game(game);
	exit (1);
}