/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:31:49 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 08:25:18 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* Creates an array of the map for easier use than the file array */
char	**create_map_array(t_game *game, t_map *map)
{
	char	**new_map;
	int		i;
	int		j;

	i = game->map_start_line;
	j = 0;
	new_map = (char **)ft_calloc((map->map_height + 1), sizeof(char *));
	if (!new_map)
		return (NULL);
	while (game->f_array[i] && j < map->map_height)
	{
		new_map[j] = ft_strdup(game->f_array[i]);
		i++;
		j++;
	}
	return (new_map);
}

int	get_map_heigth(char **array, int i)
{
	int	j;
	int	start;

	start = i;
	while (array[i] && array[i][0] != '\n')
	{
		j = 0;
		while (array[i][j] == ' ' || array[i][j] == '\t'
			|| array[i][j] == '\r' || array[i][j] == '\f')
			j++;
		if (array[i][j] != '1' && array[i][j] != '\n' && array[i][j] != '0'
			&& array[i][j] != 'N' && array[i][j] != 'E'
			&& array[i][j] != 'S' && array[i][j] != 'W'
			&& array[i][j] != '2' && array[i][j] != '4'
			&& array[i][j] != '8')
			break ;
		i++;
	}
	return (i - start);
}

int	get_map_width(t_game *game)
{
	int	i;
	int	max_width;

	i = game->map_start_line;
	max_width = 0;
	while (game->f_array[i])
	{
		if ((int)ft_strlen(game->f_array[i]) > max_width)
			max_width = (int)ft_strlen(game->f_array[i]);
		i++;
	}
	return (max_width);
}

/* Creates the map struct */
t_map	*create_map(t_game *game)
{
	t_map	*new_map;

	new_map = (t_map *)malloc(sizeof(t_map));
	if (!new_map)
	{
		printf("Error\nCouldn't create map.\n");
		return (NULL);
	}
	new_map->map_width = get_map_width(game);
	new_map->map_height = get_map_heigth(game->f_array, game->map_start_line);
	new_map->p_posx = -1.0;
	new_map->p_posy = -1.0;
	new_map->move_speed = 0.1;
	new_map->rotation_speed = 0.05;
	new_map->map_array = create_map_array(game, new_map);
	new_map->map_validation = create_map_array(game, new_map);
	if (!(new_map->map_array) || !(new_map->map_validation))
	{
		free_map(new_map);
		printf("Error\nCouldn't create map.\n");
		return (NULL);
	}
	find_sprites_and_replace(game);
	return (new_map);
}
