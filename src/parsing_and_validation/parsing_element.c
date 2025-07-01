#include "../inc/cub3d.h"

void	skip_whitespaces(char **line)
{
		while (**line == ' ' || **line == '\t' || **line == '\n')
			(*line)++;
		return ;
}

void	get_floor_ceiling_info(t_game *game, char **line, char c)
{
	if (line[0][1] == ' ')
	{
			*line = (*line) + 1;
			skip_whitespaces(line);
	}
	if (c == 'C' && game->C_texture_path == NULL)
		game->C_texture_path = ft_strdup(*line);
	if (c == 'F' && game->F_texture_path == NULL)
		game->F_texture_path = ft_strdup(*line);
}

void	get_wall_info(t_game *game, char **line, char c)
{
	if (line[0][2] == ' ')
	{
			*line = (*line) + 2;
			skip_whitespaces(line);
	}
	if (c == 'N' && game->NO_texture_path == NULL)
		game->NO_texture_path = ft_strdup(*line);
	if (c == 'E' && game->EA_texture_path == NULL)
		game->EA_texture_path = ft_strdup(*line);
	if (c == 'S' && game->SO_texture_path == NULL)
		game->SO_texture_path = ft_strdup(*line);
	if (c == 'W' && game->WE_texture_path == NULL)
		game->WE_texture_path = ft_strdup(*line);
}

int	valid_element_line(char *line)
{
	if (ft_strlen(line) > 3)
	{
		if (line[2] == ' ')
		{
			if (line[0] == 'N' && line[1] == 'O')
				return (1);
			if (line[0] == 'E' && line[1] == 'A')
				return (1);
			if (line[0] == 'S' && line[1] == 'O')
				return (1);
			if (line[0] == 'W' && line[1] == 'E')
				return (1);
		}
		else if (line[1] == ' ')
		{
			if (line[0] == 'F')
				return (1);
			if (line[0] == 'C')
				return (1);
		}
	}
	return (0);
}

int	parsing_element(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (game->file_array[i])
	{
		if (game->file_array[i][0] && !(ft_isdigit(game->file_array[i][0])))
		{
			line = game->file_array[i];
			if (valid_element_line(line))
			{
				get_wall_info(game, &line, *line);
				get_floor_ceiling_info(game, &line, *line);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}
