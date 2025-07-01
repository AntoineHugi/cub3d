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
	if (argc == 1)
		printf("Please provide a .cub map to start playing.\n");
	if (argc > 2)
		printf("Please provide only one .cub map to start playing.\n");
	if (argc == 2)
	{
		if (!correct_extension(argv[1]))
			printf("Please provide a valid file in '.cub' format.\n");
		else
			return (1);
	}
	return (0);
}

int main (int argc, char **argv)
{
	t_game	game;
	
	if (input_validation(argc, argv))
	{
		if (file_validation(&game, argv[1]))
		{
			printf("it worked!\n");
			free_game(&game);
		}
	}
	return (0);
}
