/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:57:25 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 15:54:44 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	exit_game(t_game *game)
{
	cleanup(game);
    game->mlx = NULL;
    game->win = NULL;
    //game->img = NULL;
    exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nUsage: ./cub3D <map_file.cub>\n");
		return (1);
	}
	// Initialize the main game struct to zeros
	ft_bzero(&game, sizeof(t_game));
	parse_cub_file(argv[1], &game);
	init_player(&game);
	init_engine(&game);
	// Setup hooks for keyboard and window events
	mlx_hook(game.win, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win, 17, 0, exit_game, &game);
	mlx_loop_hook(game.mlx, render_next_frame, &game);
	mlx_loop(game.mlx);
	return (0);
}
