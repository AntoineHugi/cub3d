#include "../inc/cub3d.h"

void	free_texture_img(t_game *game)
{
	if (game->no_wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->no_wall.xpm_ptr);
	if (game->ea_wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->ea_wall.xpm_ptr);
	if (game->so_wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->so_wall.xpm_ptr);
	if (game->we_wall.xpm_ptr)
		mlx_destroy_image(game->mlx, game->we_wall.xpm_ptr);
}

void	free_texture_path(t_game *game)
{
	free(game->no_texture_path);
	free(game->ea_texture_path);
	free(game->so_texture_path);
	free(game->we_texture_path);
	free(game->c_color_code);
	free(game->f_color_code);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
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
		return ;
	free_array(map->map_array);
	free_array(map->map_validation);
	free(map);
}

/* Frees the game struct */
void	free_game(t_game *game)
{
	free_array(game->f_array);
	free_map(game->map);
	free_texture_path(game);
	free_texture_img(game);
	if (game->mlx)
	{
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
