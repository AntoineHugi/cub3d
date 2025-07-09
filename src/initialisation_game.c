#include "../inc/cub3d.h"

/* creates an individual texture into an image, this is malloc'd */
static t_texture	new_texture(void *mlx, char *path, t_game *game)
{
	t_texture	t;

	t.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &t.width, &t.height);
	if (t.xpm_ptr == NULL)
		initialisation_error(game, "Could not create wall texture.");
	return (t);
}

/* creates the textures for each wall */
static void	initialise_textures(t_game *game)
{
	game->no_wall = new_texture(game->mlx, game->no_texture_path, game);
	game->ea_wall = new_texture(game->mlx, game->ea_texture_path, game);
	game->so_wall = new_texture(game->mlx, game->so_texture_path, game);
	game->we_wall = new_texture(game->mlx, game->we_texture_path, game);
}

/* creates the mlx and window pointers*/
/* and intialises the textures for the walls into images used in rendering. */
/* Also initialises the ray casting info from the direction the player faces */
void	initialise_game(t_game *game)
{
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		initialisation_error(game, "MLX initialisation failed.");
	game->win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "./cub3D");
	if (game->win == NULL)
		initialisation_error(game, "Window initialisation failed.");
	initialise_textures(game);
	init_raycasting(&game->rc, game->map);
}
