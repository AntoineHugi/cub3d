#include "../inc/cub3d.h"

/* generates an array from the content of the cub file for parsing */
char	**file_array_creation(char *file_path)
{
	char	*file_raw;
	char	*file_line;
	char	**file_array;
	int		fd;

	file_raw = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open map file\n");
		return (NULL);
	}
	file_line = get_next_line(fd);
	while (file_line)
	{
		file_raw = ft_gnl_strjoin(file_raw, file_line);
		free(file_line);
		file_line = get_next_line(fd);
	}
	close(fd);
	if (!file_raw)
		printf("File is empty\n");
	file_array = ft_split(file_raw, '\n');
	free(file_raw);
	return (file_array);
}

int	file_validation(t_game *game, char *file_path)
{
	game->file_array = file_array_creation(file_path);
	if (!game->file_array)
		return (0);
	if (parsing_file(game))
	{
		return (1);
	}
	return (1);
}