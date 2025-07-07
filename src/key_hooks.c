#include "../inc/cub3d.h"

int	exit_app(t_game *game)
{
	free_game(game);
	exit(1);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119)
		check_move(game, UP);
	if (keycode == 115)
		check_move(game, DOWN);
	if (keycode == 97)
		check_move(game, LEFT);
	if (keycode == 100)
		check_move(game, RIGHT);
	if (keycode == 65361)
		turn_view(game, LEFT);
	if (keycode == 65363)
		turn_view(game, RIGHT);
	if (keycode == 65307)
		exit_app(game);
	//render_map(game);
	return (0);
}