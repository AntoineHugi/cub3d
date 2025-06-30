#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_game {
	char	**file_array;
	int	file_num_lines;
	int	map_start_line;
	int	p_posx;
	int	p_posy;
	int	p_dir;
	char	*NO_texture_path;
	char	*EA_texture_path;
	char	*SO_texture_path;
	char	*WE_texture_path;
	char	*C_texture_path;
	char	*F_texture_path;

}			t_game;

/* Cub3D functions */
char	**file_array_creation(char *file);
int	parsing_file(t_game *game);
int	parsing_element(t_game *game);
int	parsing_map(t_game *game);


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
int	ft_isdigit(int c);

#endif