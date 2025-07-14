#include "../inc/cub3d.h"

int	mouse_move(int x, int y, t_game *game)
{
	int	move;

	move = x - game->mouse_x;
	if (move > 0 && abs(move) > 10)
		turn_view(game, RIGHT);
	else if (move < 0 && abs(move) > 10)
		turn_view(game, LEFT);
	game->mouse_x = x;
	game->mouse_y = y;
	return (0);
}
