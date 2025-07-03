#include "../inc/cub3d.h"

/* Gets the of the map element in the file */
int	get_map_start_line(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j] == ' ' || array[i][j] == '\t' 
			|| array[i][j] == '\r' || array[i][j] == '\f')
			j++;
		if (array[i][j] == '1' || array[i][j] == '0')
			break ;
		else if (array[i][j] == 'N' || array[i][j] == 'E' || array[i][j] == 'S'
			|| array[i][j] == 'W')
		{
			if (array[i][j + 1] == '1' || array[i][j + 1] == '0')
				break ; 
		}
		i++;
	}
	return (i);
}

/* initialises values for some of the struct */
void	init_game_struct(t_game *game)
{
	game->map_start_line = get_map_start_line(game->file_array);
	game->map = NULL;
	game->no_texture_path = NULL;
	game->ea_texture_path = NULL;
	game->so_texture_path = NULL;
	game->we_texture_path = NULL;
	game->c_texture_path = NULL;
	game->f_texture_path = NULL;
}

/* generates an array from the content of the cub file for parsing */
void	file_array_creation(t_game *game, char *file_path)
{
	int		fd;
	char	*file_line;
	int		i;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open map file.\n");
		return;
	}
	game->file_array = (char**)ft_calloc((game->file_num_lines + 1), sizeof(char*));
	i = 0;
	file_line = get_next_line(fd);
	while (file_line)
	{
		game->file_array[i] = ft_strdup(file_line);
		free(file_line);
		file_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return ;
}
/* Get number of lines in files, returns an error if file can't be opened or is empty */
int	get_files_lines(char *file_path)
{
	int		fd;
	int		num_lines;
	char		*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open map file.\n");
		return (-1);
	}
	num_lines = 0;
	line = get_next_line(fd);
	if (!line)
	{
		printf("File is empty.\n");
		return (-1);
	}
	while(line)
	{
		num_lines++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return(num_lines);
}

/* parsing the file to check the two parts: elements and map */
int	parsing_file(t_game *game, char *file_path)
{
	game->file_num_lines = get_files_lines(file_path);
	if (game->file_num_lines == -1)
		return (0);
	file_array_creation(game, file_path);
	init_game_struct(game);
	if (!valid_file(game))
		validation_error(game);
	return (1);
}
