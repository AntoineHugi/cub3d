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
	int		p_dir;

}			t_map;

typedef struct s_game {
	char	**file_array;
	t_map	map;
	int		file_num_lines;
	int		map_start_line;
	char	*NO_texture_path;
	char	*EA_texture_path;
	char	*SO_texture_path;
	char	*WE_texture_path;
	char	*C_texture_path;
	char	*F_texture_path;

}			t_game;

/* Cub3D Parsing functions */
int	file_validation(t_game *game, char *file_path);
int	parsing_file(t_game *game);
int	parsing_element(t_game *game);
int	parsing_map(t_game *game);
int	valid_elements(t_game *game);
int	valid_colors(t_game *game);

/* Cub3D errors and freeing functions */
void	free_game(t_game *game);
void	parsing_error(t_game *game, char *err_msg);

/* get_next_line and utils */
char	*get_next_line(int fd);
char	*ft_strchr_mod(char *s);
char	*ft_gnl_strjoin(char *s1, char *s2);
void	ft_gnl_memcpy(char *dst, char *src, size_t n);
void	*ft_gnl_calloc(size_t nmemb, size_t size);


/* libft functions */
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);

#endif