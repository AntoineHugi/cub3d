#include "../inc/cub3d.h"

/* quits the game with ESC or the X button */
int	exit_app(t_game *game)
{
	game->is_exiting = 1;
	free_game(game, NULL);
	exit(0);
	return (0);
}

/* reads key press and goes into relevant function */
/* rerenders after each key press */
int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		check_move(game, FORWARD);
	else if (keycode == KEY_S)
		check_move(game, BACKWARD);
	else if (keycode == KEY_A)
		check_move(game, LEFT);
	else if (keycode == KEY_D)
		check_move(game, RIGHT);
	else if (keycode == KEY_LEFT)
		turn_view(game, LEFT);
	else if (keycode == KEY_RIGHT)
		turn_view(game, RIGHT);
	else if (keycode == KEY_ESC)
		exit_app(game);
	else
		return (0);
	render_map(game);
	return (0);
}
