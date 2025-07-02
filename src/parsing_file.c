#include "../inc/cub3d.h"

int	get_map_start_line(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->file_array[i])
	{
		j = 0;
		while (game->file_array[i][j] == ' ' || game->file_array[i][j] == '\t' 
			|| game->file_array[i][j] == '\r' || game->file_array[i][j] == '\f')
			j++;
		if (game->file_array[i][j] == '1' || game->file_array[i][j] == '0')
			break ;
		i++;
	}
	return (i);
}

/* initialises values for some of the struct */
void	init_game_struct(t_game *game)
{
	int	i;

	i = 0;
	while (game->file_array[i])
		i++;
	game->file_num_lines = i;
	game->map_start_line = get_map_start_line(game);
	game->map = NULL;
	game->no_texture_path = NULL;
	game->ea_texture_path = NULL;
	game->so_texture_path = NULL;
	game->we_texture_path = NULL;
	game->c_texture_path = NULL;
	game->f_texture_path = NULL;
}

/* concatenate all the lines in the file */
char	*reading_file(int fd)
{
	char	*file_raw;
	char	*file_line;

	file_raw = NULL;
	file_line = get_next_line(fd);
	while (file_line)
	{
		file_raw = ft_gnl_strjoin(file_raw, file_line);
		free(file_line);
		file_line = get_next_line(fd);
	}
	if (!file_raw)
		printf("File is empty.\n");
	//keep_empty_lines(file_raw);
	close(fd);
	return (file_raw);
}

/* generates an array from the content of the cub file for parsing */
char	**file_array_creation(char *file_path)
{
	char	*file_raw;
	char	**file_array;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open map file.\n");
		return (NULL);
	}
	file_raw = reading_file(fd);
	if (!file_raw)
		return (NULL);
	file_array = ft_split(file_raw, '\n');
	free(file_raw);
	return (file_array);
}

/* parsing the file to check the two parts: elements and map */
int	parsing_file(t_game *game, char *file_path)
{
	game->file_array = file_array_creation(file_path);
	if (!game->file_array)
		return (0);
	init_game_struct(game);
	if (!valid_file(game))
		validation_error(game);
	return (1);
}
