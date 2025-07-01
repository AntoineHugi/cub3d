#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../src/libft/libft.h"

typedef struct s_map {
	int		map_height;
	int		map_width;
	char	**map_array;
	int		p_posx;
	int		p_posy;
	char	p_dir;

}			t_map;

typedef struct s_game {
	char	**file_array;
	t_map	*map;
	int		file_num_lines;
	int		map_start_line;
	char	*no_texture_path;
	char	*ea_texture_path;
	char	*so_texture_path;
	char	*we_texture_path;
	char	*c_texture_path;
	char	*f_texture_path;

}			t_game;

/* Parsing functions */
int		file_validation(t_game *game, char *file_path);
int		parsing_file(t_game *game);
int		parsing_element(t_game *game);
int		parsing_map(t_game *game);
int		valid_elements(t_game *game);
int		valid_colors(t_game *game);

/* errors and freeing functions */
void	free_game(t_game *game);
void	parsing_error(t_game *game, char *err_msg);

/* utils */
void	skip_whitespaces(char **line);

#endif