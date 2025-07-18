/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:23:41 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 10:12:08 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* checks that the value is within the rgb range */
static int	valid_rgb_value(char *value)
{
	int		value_int;

	if (!value[0])
		return (0);
	value_int = ft_atoi(value);
	if (value_int > 255 || value_int < 0)
		return (0);
	return (1);
}

/* checks that the value is within the rgb range */
static int	valid_rgb_code(char *input)
{
	char	value[4];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (input[i])
	{
		ft_bzero(value, 4);
		while (input[i] && ft_isdigit(input[i]))
		{
			value[j] = input[i];
			i++;
			j++;
		}
		if (j == 0)
			return (0);
		j = 0;
		if (!valid_rgb_value(value))
			return (0);
		if (input[i])
			i++;
	}
	return (1);
}

/* checks that RGB format is correct (3 ints of 3 digits max between commas) */
static int	valid_rgb_format(char *input)
{
	int	i;
	int	elem_counter;
	int	code_counter;

	i = 0;
	elem_counter = 1;
	code_counter = 0;
	while (input[i] && input[i] != '\n')
	{
		if (ft_isdigit(input[i]) && code_counter < 3)
			code_counter++;
		else if (ft_isdigit(input[i]) && code_counter > 3)
			return (0);
		else if (input[i] == ',' && i != 0 && elem_counter < 3 && input[i + 1])
		{
			code_counter = 0;
			elem_counter++;
		}
		else
			return (0);
		i++;
	}
	if (elem_counter != 3)
		return (0);
	return (1);
}

/* checks the floor and ceiling elements */
int	valid_colors(t_game *game)
{
	if (!valid_rgb_format(game->f_color_code))
	{
		printf("Error\nInvalid floor format.\n");
		return (0);
	}
	if (!valid_rgb_format(game->c_color_code))
	{
		printf("Error\nInvalid ceiling format.\n");
		return (0);
	}
	if (!valid_rgb_code(game->f_color_code))
	{
		printf("Error\nInvalid floor code.\n");
		return (0);
	}
	if (!valid_rgb_code(game->c_color_code))
	{
		printf("Error\nInvalid ceiling code.\n");
		return (0);
	}
	return (1);
}
