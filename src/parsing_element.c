#include "../inc/cub3d.h"

void	skip_whitespaces(char **line)
{
		while (**line == ' ' || **line == '\t' || **line == '\f' 
			|| **line == '\r')
			(*line)++;
		return ;
}

/* saves the colors for the floor and ceiling in the game struct */
void	get_floor_ceiling_info(t_game *game, char **line, char c)
{
	if (line[0][1] == ' ')
	{
			*line = (*line) + 1;
			skip_whitespaces(line);
	}
	if (c == 'C' && game->c_texture_path == NULL)
		game->c_texture_path = ft_strdup(*line);
	if (c == 'F' && game->f_texture_path == NULL)
		game->f_texture_path = ft_strdup(*line);
}

/* saves the texture paths in the game struct */
void	get_wall_info(t_game *game, char **line, char c)
{
	if (line[0][2] == ' ')
	{
			*line = (*line) + 2;
			skip_whitespaces(line);
	}
	if (c == 'N' && game->no_texture_path == NULL)
		game->no_texture_path = ft_strdup(*line);
	if (c == 'E' && game->ea_texture_path == NULL)
		game->ea_texture_path = ft_strdup(*line);
	if (c == 'S' && game->so_texture_path == NULL)
		game->so_texture_path = ft_strdup(*line);
	if (c == 'W' && game->we_texture_path == NULL)
		game->we_texture_path = ft_strdup(*line);
}

/* checker for the valid line */
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

/* checking that the file contains valid element line */
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
