#include "../inc/cub3d.h"

/* generates an array from the content of the cub file */
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
		free(file_raw);
		return (NULL);
	}
	while (1)
	{
		file_line = get_next_line(fd);
		if (!file_line)
			break;
		file_raw = ft_gnl_strjoin(file_raw, file_line);
		free(file_line);
	}
	close(fd);
	file_array = ft_split(file_raw, '\n');
	free(file_raw);
	return (file_array);
}
