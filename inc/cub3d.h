#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define FORWARD	1
# define BACKWARD	2
# define RIGHT	3
# define LEFT	4
# define WIN_HEIGHT	512
# define WIN_WIDTH	512

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
	char	p_view;
	double	p_posx;
	double	p_posy;
	int		p_dir_x;
	int		p_dir_y;
	double	move_speed;
	double	rotation_speed;
}			t_map;

typedef struct s_raycasting {
	int		p_dir_x;
	int		p_dir_y;
	double	plane_x;
	double	plane_y;
	int		ray_pos_x;
	int		ray_pos_y;
	int		wall_hit;
	int		side_hit;
	double	screen_pos;
	double	ray_dir_x;
	double	ray_dir_y;
	double	delta_dist_x;
	double	delta_dist_y; 
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y;
	double	wall_dist;
}			t_raycasting;

typedef struct s_game {
	char			**f_array;
	t_map			*map;
	int				f_lines;
	int				map_start_line;
	char			*no_texture_path;
	char			*ea_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*c_color_code;
	char			*f_color_code;
	t_texture		no_wall;
	t_texture		ea_wall;
	t_texture		so_wall;
	t_texture		we_wall;
	void			*mlx;
	void			*win;
	t_raycasting	rc;
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
void	init_raycasting(t_raycasting *ray, t_map *map);

/* rendering */
void	render_map(t_game *game);
void	calculate_raycasting(t_raycasting *ray, t_map *map, int i);

/* key hooks */
int		key_hook(int keycode, t_game *game);
int		exit_app(t_game *game);

/* movement */
void	check_move(t_game *game, int direction);
void	turn_view(t_game *game, int direction);
void	update_player_dir(t_map *map);

/* errors and freeing functions */
void	free_game(t_game *game);
void	free_map(t_map *map);
void	validation_error(t_game *game);
void	initialisation_error(t_game *game, char *error_msg);

/* utils */
char	*remove_whitespaces(char *str, int i, int j);

#endif