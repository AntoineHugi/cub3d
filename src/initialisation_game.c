#include "../inc/cub3d.h"

static t_texture	new_texture(void *mlx, char *path, t_game *game)
{
	t_texture	texture;

	texture.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &texture.width, &texture.height);
	if (texture.xpm_ptr == NULL)
		initialisation_error(game, "Could not create wall texture.");
	printf("width = %i. heigth = %i\n", texture.width, texture.height);
	return (texture);
}

static void	initialise_textures(t_game *game)
{
	game->no_wall = new_texture(game->mlx, game->no_texture_path, game);
	game->ea_wall = new_texture(game->mlx, game->ea_texture_path, game);
	game->so_wall = new_texture(game->mlx, game->so_texture_path, game);
	game->we_wall = new_texture(game->mlx, game->we_texture_path, game);
	//game->floor = new_sprite(game->mlx, game->f_texture_path, game);
	//game->ceiling = new_sprite(game->mlx, game->no_texture_path, game);
}

void	initialise_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		initialisation_error(game, "MLX initialisation failed.");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "./cub3D");
	if (game->win == NULL)
		initialisation_error(game, "Window initialisation failed.");
	initialise_textures(game);
}