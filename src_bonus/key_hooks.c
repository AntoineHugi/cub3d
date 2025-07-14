#include "../inc/cub3d.h"

int	operate_door(t_game *game, t_map *map)
{
	char	**array;
	double	new_x;
	double	new_y;

	array = map->map_array;
	new_x = map->p_posx + game->rc.p_dir_x * (map->move_speed + 0.8);
	new_y = map->p_posy + game->rc.p_dir_y * (map->move_speed + 0.8);
	if (array[(int)(new_y)][(int)new_x] == 'D')
		array[(int)(new_y)][(int)new_x] = 'O';
	else if (array[(int)(new_y)][(int)new_x] == 'O')
	{
		if (array[(int)map->p_posy][(int)map->p_posx] != 'O')
			array[(int)(new_y)][(int)new_x] = 'D';
	}
	return (0);
}

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
		check_move(game, game->map, FORWARD);
	else if (keycode == KEY_S)
		check_move(game, game->map, BACKWARD);
	else if (keycode == KEY_A)
		check_move(game, game->map, LEFT);
	else if (keycode == KEY_D)
		check_move(game, game->map, RIGHT);
	else if (keycode == KEY_LEFT)
		turn_view(game, LEFT);
	else if (keycode == KEY_RIGHT)
		turn_view(game, RIGHT);
	else if (keycode == KEY_E)
		operate_door(game, game->map);
	else if (keycode == KEY_ESC)
		exit_app(game);
	else
		return (0);
	return (0);
}
