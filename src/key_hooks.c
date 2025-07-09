#include "../inc/cub3d.h"

/* quits the game with ESC or the X button */
int	exit_app(t_game *game)
{
	free_game(game);
	exit(1);
}

/* reads key press and goes into relevant function */
int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119)
		check_move(game, FORWARD);
	else if (keycode == 115)
		check_move(game, BACKWARD);
	else if (keycode == 97)
		check_move(game, LEFT);
	else if (keycode == 100)
		check_move(game, RIGHT);
	else if (keycode == 65361)
		turn_view(game, LEFT);
	else if (keycode == 65363)
		turn_view(game, RIGHT);
	else if (keycode == 65307)
		exit_app(game);
	else
		return (0);
	//render_map(game);
	return (0);
}
