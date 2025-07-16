/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:23:55 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 11:23:56 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* checks that the content in the file is valid */
int	valid_file(t_game *game)
{
	if (!valid_elements(game))
		return (0);
	if (!valid_map(game))
		return (0);
	return (1);
}
