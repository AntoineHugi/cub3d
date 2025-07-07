#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define UP	1
# define DOWN	2
# define RIGHT	3
# define LEFT	4
# define WIN_HEIGHT	1024
# define WIN_WIDTH	1024

typedef struct s_texture {
	void	*xpm_ptr;
	int		width;
	int		height;
}				t_texture;

typedef struct s_map {
	int		map_height;
	int		map_width;
	char	**map_array;
	char	**map_validation;
	int		p_posx;
	int		p_posy;
}			t_map;

typedef struct s_game {
	char		**file_array;
	t_map		*map;
	int			file_num_lines;
	int			map_start_line;
	char		*no_texture_path;
	char		*ea_texture_path;
	char		*so_texture_path;
	char		*we_texture_path;
	char		*c_texture_path;
	char		*f_texture_path;
	t_texture	no_wall;
	t_texture	ea_wall;
	t_texture	so_wall;
	t_texture	we_wall;
	t_texture	floor;
	t_texture	ceiling;
	void		*mlx;
	void		*win;

}			t_game;

/* Parsing functions */
int		parsing_file(t_game *game, char *file_path);
int		valid_file(t_game *game);
int		parsing_element(t_game *game);
int		valid_elements(t_game *game);
int		valid_colors(t_game *game);
int		valid_map(t_game *game);
t_map	*create_map(t_game *game);

/* initialisation */
void	initialise_game(t_game *game);

/* rendering */
void	render_map(t_game *game);

/* key hooks */
int	key_hook(int keycode, t_game *game);
int	exit_app(t_game *game);

/* movement */
void	check_move(t_game *game, int direction);
void	turn_view(t_game *game, int direction);

/* errors and freeing functions */
void	free_game(t_game *game);
void	free_map(t_map *map);
void	validation_error(t_game *game);
void	initialisation_error(t_game *game, char *error_msg);

/* utils */
char	*remove_whitespaces(char *str, int i, int j);

#endif