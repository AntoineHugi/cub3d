/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:24:51 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/18 08:49:49 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	*safe_malloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		printf(stderr, "Error\nMemory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

int	validation_error(t_game *game, const char *error_msg)
{
	if (error_msg)
		printf("Error: %s\n", error_msg);
	if (!game)
		return (0);
	free_game(game, NULL);
	exit(1);
	return (0);
}

int	initialisation_error(t_game *game, char *error_msg)
{
	printf("%s\n", error_msg);
	if (!game)
		return (0);
	free_game(game, NULL);
	exit(1);
	return (0);
}
