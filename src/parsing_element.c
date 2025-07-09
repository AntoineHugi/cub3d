#include "../inc/cub3d.h"

/* Trims the element lines of whitespaces */
char	*remove_whitespaces(char *str, int i, int j)
{
	char	*new_str;
	int		new_len;

	new_len = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\f')
			new_len++;
		i++;
	}
	new_str = (char *)ft_calloc(new_len + 1, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r' && str[i] != '\f')
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	return (new_str);
}

/* saves the element information in the game struct */
int	get_element_info(t_game *game, char *line)
{
	if (line[0] == 'N' && game->no_texture_path == NULL)
		game->no_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'E' && game->ea_texture_path == NULL)
		game->ea_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'S' && game->so_texture_path == NULL)
		game->so_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'W' && game->we_texture_path == NULL)
		game->we_texture_path = ft_strdup(line + 2);
	else if (line[0] == 'C' && game->c_texture_path == NULL)
		game->c_texture_path = ft_strdup(line + 1);
	else if (line[0] == 'F' && game->f_texture_path == NULL)
		game->f_texture_path = ft_strdup(line + 1);
	else
	{
		printf("Duplicate element.\n");
		free(line);
		return (0);
	}
	return (1);
}

/* checker for the valid line */
int	valid_element_line(char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
		return (1);
	if (line[0] == 'N' && line[1] == 'O')
		return (1);
	if (line[0] == 'E' && line[1] == 'A')
		return (1);
	if (line[0] == 'S' && line[1] == 'O')
		return (1);
	if (line[0] == 'W' && line[1] == 'E')
		return (1);
	printf("Invalid line in file. Line is %s\n", line);
	free(line);
	return (0);
}

/* checking that the file contains valid element line */
int	parsing_element(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (game->file_array[i] && i < game->map_start_line)
	{
		line = remove_whitespaces(game->file_array[i++], 0, 0);
		if (line[0] && !(ft_isdigit(line[0])) && line[0] != '\n')
		{
			if (valid_element_line(line))
			{
				if (!get_element_info(game, line))
					return (0);
			}
			else
				return (0);
		}
		free(line);
	}
	return (1);
}
