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