/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:31:43 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 13:31:45 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* checks for correct file extension */
int	correct_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (filename[len - 1] != 'b')
		return (0);
	if (filename[len - 2] != 'u')
		return (0);
	if (filename[len - 3] != 'c')
		return (0);
	if (filename[len - 4] != '.')
		return (0);
	return (1);
}

/* checks for correct number of arguments and input */
int	input_validation(int argc, char **argv)
{
	if (argc != 2)
		printf("Usage: ./cub3D <path/to/map.cub>\n");
	if (argc == 2)
	{
		if (!correct_extension(argv[1]))
			printf("Not a .cub file\n");
		else
			return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!input_validation(argc, argv))
		return (EXIT_FAILURE);
	if (!parsing_file(&game, argv[1]))
	{
		free_game(&game, "Failed to parse map file");
		return (EXIT_FAILURE);
	}
	if (!initialise_game(&game))
	{
		free_game(&game, "Failed to initialize game.\n");
		return (EXIT_FAILURE);
	}
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, exit_app, &game);
	mlx_hook(game.win, 6, 1L << 6, mouse_move, &game);
	mlx_loop_hook(game.mlx, render_map, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
