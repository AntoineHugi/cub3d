/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:21:20 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 10:36:45 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FORWARD 1
# define BACKWARD 2
# define RIGHT 3
# define LEFT 4

# define WIN_HEIGHT 800
# define WIN_WIDTH 1024
# define PI 3.14159265358979323846

// *** BONUS: Minimap Macros *** //
# define MINIMAP_SCALE 10
# define MINIMAP_BORDER 10
# define PLAYER_SIZE 4
# define WALL_COLOR 0x222222
# define FLOOR_COLOR 0x888888
# define PLAYER_COLOR 0xFF0000

// *** BONUS: Sprite Macros *** //
# define MAX_SPRITE_FRAMES 10
# define ANIMATION_SPEED 10
# define TRANSPARENT_COLOR 0x000000

// *** OS-specific includes and definitions *** //
# ifdef __APPLE__
#  include "../minilibx_macos/mlx.h"
#  define KEY_W 13
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_D 2
#  define KEY_E 14
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define KEY_ESC 53
# else
#  include "../minilibx-linux/mlx.h"
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_E 101
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define KEY_ESC 65307
# endif

// *** Struct definitions *** //
typedef struct s_img
{
	void			*ptr;
	int				*data;
	int				bpp;
	int				size_l;
	int				endian;
	int				height;
	int				width;
}					t_img;

typedef struct s_map
{
	int				map_height;
	int				map_width;
	char			**map_array;
	char			**map_validation;
	char			p_view;
	double			p_posx;
	double			p_posy;
	double			p_angle;
	double			move_speed;
	double			rotation_speed;
}					t_map;

typedef struct s_raycasting
{
	double			p_dir_x;
	double			p_dir_y;
	double			plane_x;
	double			plane_y;
	int				map_x;
	int				map_y;
	double			ray_pos_x;
	double			ray_pos_y;
	int				wall_hit;
	int				side_hit;
	double			screen_pos;
	double			ray_dir_x;
	double			ray_dir_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	double			wall_dist;
	double *z_buffer
}					t_raycasting;

typedef struct s_wall
{
	int				line_h;
	int				start;
	int				end;
	int				tex_num;
	double			wall_x;
	t_img			*tex;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				color;
}					t_wall;

typedef struct s_sprite
{
	double			x;
	double			y;
	double			dist;
	int				frame;
	int				anim_timer;
	t_img			*tex[2];
}					t_sprite;

typedef struct s_sprite_vars
{
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				d;
	int				color;
	t_img			*texture;
}					t_sprite_vars;

typedef struct s_game
{
	char			**f_array;
	t_map			*map;
	int				f_lines;
	int				map_start_line;
	char			*no_texture_path;
	char			*ea_texture_path;
	char			*so_texture_path;
	char			*we_texture_path;
	char			*d_texture_path;
	char			*o_texture_path;
	char			*s_texture_paths[MAX_SPRITE_FRAMES];
	char			*c_color_code;
	char			*f_color_code;
	int				c_color_int;
	int				f_color_int;
	t_img			no_wall;
	t_img			ea_wall;
	t_img			so_wall;
	t_img			we_wall;
	t_img			sprite_tex[MAX_SPRITE_FRAMES];
	t_img			door_closed;
	t_img			door_open;
	void			*mlx;
	void			*win;
	t_raycasting	rc;
	t_img			frame;
	int				is_exiting;
	int				mouse_x;
	int				mouse_y;
	t_sprite		*sprites;
	int				sprite_count;
}					t_game;

// *** Function Prototypes *** //
/* Parsing functions */
int					parsing_file(t_game *game, char *file_path);
int					valid_file(t_game *game);
int					parsing_element(t_game *game);
int					valid_elements(t_game *game);
int					valid_colors(t_game *game);
int					valid_map(t_game *game);
t_map				*create_map(t_game *game);

/* initialisation */
int					initialise_game(t_game *game);
void				init_raycasting(t_raycasting *ray, t_map *map);

/* rendering */
int					render_map(t_game *game);
void				calculate_raycasting(t_raycasting *ray, t_map *map, int i);

/* hooks & movement */
int					key_hook(int keycode, t_game *game);
int					exit_app(t_game *game);
void				check_move(t_game *game, t_map *map, int direction);
void				turn_view(t_game *game, int direction);
int					mouse_move(int x, int y, t_game *game);

/* errors and freeing functions */
void				free_game(t_game *game, const char *error_msg);
void				free_map(t_map *map);
void				free_array(char **array);
int					validation_error(t_game *game, const char *error_msg);
int					initialisation_error(t_game *game, char *error_msg);

/* utils */
int					is_valid_map_char(char c);
char				*remove_whitespaces(char *str, int i, int j);

/*** BONUS */
// Minimap functions
void				render_minimap(t_game *game);

// Sprite functions
void				init_sprites(t_game *game);
void				render_sprites(t_game *game);
void				sort_sprites(t_game *game);
void				update_sprite_animation(t_sprite *sprite);
void				draw_sprite_stripe(t_game *g, t_sprite_vars *s,
						t_sprite *spr, int stripe);
void				transform_sprite(t_game *game, t_sprite_vars *s,
						t_sprite *sprite);
void				set_sprite_properties(t_game *game, int i, int x, int y);

#endif
