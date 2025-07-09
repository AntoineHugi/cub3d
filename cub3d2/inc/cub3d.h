/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:56:10 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 16:02:02 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"

/*// Try different MinilibX paths based on system
# ifdef __APPLE__
#  include "../minilibx_macos/mlx.h"
# elif __linux__
#  include "../minilibx_linux/mlx.h"
# else
#  include "../mlx.h"
# endif*/

// --- MACROS ---
# define SCREEN_WIDTH 1024
# define SCREEN_HEIGHT 768
# define MOVE_SPEED 0.1
# define ROT_SPEED 0.05
# define TEXTURE_WIDTH 64
# define TEXTURE_HEIGHT 64

// --- KEYCODES (macOS) ---
# define K_ESC 53
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_LEFT 123
# define K_RIGHT 124

// --- STRUCTURES ---

// For storing texture data

typedef struct s_img {
    void    *ptr;
    int     *data;
    int     bpp;
    int     size_l;
    int     endian;
}   t_img;

typedef struct s_player {
    double  pos_x;
    double  pos_y;
    double  dir_x;
    double  dir_y;
    double  plane_x;
    double  plane_y;
}   t_player;

typedef struct s_config {
    char    *no_path;
    char    *so_path;
    char    *we_path;
    char    *ea_path;
    int     floor_color;
    int     ceiling_color;
    int     is_set[6]; // Tracker for NO,SO,WE,EA,F,C
}   t_config;

typedef struct s_map {
    char    **grid;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    char    player_dir;
}   t_map;

typedef struct s_ray {
    double  camera_x;
    double  dir_x;
    double  dir_y;
    int     map_x;
    int     map_y;
    double  side_dist_x;
    double  side_dist_y;
    double  delta_dist_x;
    double  delta_dist_y;
    double  perp_wall_dist;
    int     step_x;
    int     step_y;
    int     hit;
    int     side;
}   t_ray;


typedef struct s_game {
    void        *mlx;
    void        *win;
    t_map       map;
    t_config    config;
    t_player    player;
    t_img       frame;
    t_img       textures[4]; // 0:NO, 1:SO, 2:WE, 3:EA
}   t_game;

// --- Function Prototypes ---

// main.c
int exit_game(t_game *game);

// parser/parser.c
void parse_cub_file(const char *filename, t_game *game);
char **read_file_lines(int fd);
int		all_configs_set(t_game *game);

// parser/parser_config.c
void parse_config_line(char *line, t_game *game);

// parser/parser_map.c
void parse_map_grid(char **lines, int start_index, t_game *game);
void validate_map_is_closed(t_game *game);

// parser/parser_utils.c
int is_whitespace(char c);
char *remove_whitespace(const char *s1);
int is_map_line(const char *line);

// engine/engine_init.c
void init_engine(t_game *game);

// engine/raycaster.c
void perform_raycasting(t_game *game, t_ray *ray);

// engine/render.c
int render_next_frame(t_game *game);

// player/player_init.c
void init_player(t_game *game);

// player/player_controls.c
int handle_keypress(int keycode, t_game *game);

// utils/error.c
void error_exit(t_game *game, const char *message);
void cleanup(t_game *game);

// utils/memory.c
void free_string_array(char **arr);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
char **ft_split(char const *s, char c);

#endif
