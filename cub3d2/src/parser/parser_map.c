/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:09:01 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 17:12:43 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <string.h>

static void find_player_start(t_game *game)
{
    int players_found = 0;
    for (int y = 0; y < game->map.height; y++)
    {
        for (int x = 0; x < (int)strlen(game->map.grid[y]); x++)
        {
            char c = game->map.grid[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                players_found++;
                game->map.player_x = x;
                game->map.player_y = y;
                game->map.player_dir = c;
            }
            else if (c != '0' && c != '1' && c != ' ')
                error_exit(game, "Invalid character found in map.");
        }
    }
    if (players_found != 1)
        error_exit(game, "Map must contain exactly one player start position.");
}

static void flood_fill(char **map_copy, int x, int y, t_map *map)
{
    // Base cases for recursion
    if (x < 0 || x >= map->width || y < 0 || y >= map->height)
        error_exit(NULL, "Map is not closed: Path leads to edge of map.");

    if (map_copy[y][x] == ' ' || map_copy[y][x] == '\t')
        error_exit(NULL, "Map is not closed: Path is adjacent to a space.");

    if (map_copy[y][x] == '1' || map_copy[y][x] == 'F')
        return;

    map_copy[y][x] = 'F'; // Mark as Filled

    flood_fill(map_copy, x + 1, y, map);
    flood_fill(map_copy, x - 1, y, map);
    flood_fill(map_copy, x, y + 1, map);
    flood_fill(map_copy, x, y - 1, map);
}

void validate_map_is_closed(t_game *game)
{
    char **map_copy;
    game->map.width = 0;

    for (int i = 0; i < game->map.height; i++)
        if ((int)strlen(game->map.grid[i]) > game->map.width)
            game->map.width = strlen(game->map.grid[i]);

    map_copy = malloc(sizeof(char *) * (game->map.height));
    if (!map_copy) error_exit(game, "Malloc failed during map validation.");

    for (int i = 0; i < game->map.height; i++)
        map_copy[i] = strdup(game->map.grid[i]);

    flood_fill(map_copy, game->map.player_x, game->map.player_y, &game->map);
    free_string_array(map_copy);
}

void parse_map_grid(char **lines, int start_index, t_game *game)
{
    int map_height = 0;
    while (lines[start_index + map_height])
        map_height++;

    game->map.height = map_height;
    game->map.grid = malloc(sizeof(char *) * (map_height + 1));
    if (!game->map.grid)
        error_exit(game, "Malloc failed for map grid.");

    for (int i = 0; i < map_height; i++)
        game->map.grid[i] = ft_strdup(lines[start_index + i]);
    game->map.grid[map_height] = NULL;

    find_player_start(game);
    validate_map_is_closed(game);
}
