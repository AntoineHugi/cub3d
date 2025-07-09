/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:30:24 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:23 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void check_cub_extension(const char *filename, t_game *game)
{
    if (ft_strlen(filename) < 5 || ft_strcmp(filename + ft_strlen(filename) - 4, ".cub") != 0)
        error_exit(game, "Invalid file extension. Must be .cub");
}

static char **open_and_read_lines(const char *filename, t_game *game)
{
    int fd;
    char **lines;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        error_exit(game, "Cannot open map file.");
    lines = read_file_lines(fd);
    close(fd);
    if (!lines)
        error_exit(game, "Failed to read map file or file is empty.");
    return lines;
}

static void process_line(char *trimmed, int *map_started, t_game *game, char **error_msg, char **lines, int i)
{
    if (*trimmed)
    {
        if (is_map_line(trimmed))
        {
            if (!all_configs_set(game))
                *error_msg = "Map starts before all configurations are set.";
            else
            {
                *map_started = 1;
                parse_map_grid(lines, i, game);
            }
        }
        else if (*map_started)
            *error_msg = "Configuration data found after map.";
        else
            parse_config_line(trimmed, game);
    }
}

static void handle_line_processing(char **lines, int *i, int *map_started, t_game *game, char **error_msg)
{
    char *trimmed;

    trimmed = remove_whitespace(lines[*i]);
    process_line(trimmed, map_started, game, error_msg, lines, *i);
    free(trimmed);
}

static void check_map_found(int map_started, char **error_msg)
{
    if (!map_started && !(*error_msg))
        *error_msg = "Map not found in file.";
}

static void cleanup_and_exit(char **lines, t_game *game, char *error_msg)
{
    free_string_array(lines);
    if (error_msg)
        error_exit(game, error_msg);
}

void parse_cub_file(const char *filename, t_game *game)
{
    char **lines;
    char *error_msg;
    int i = 0;
    int map_started = 0;

    error_msg = NULL;
    check_cub_extension(filename, game);
    lines = open_and_read_lines(filename, game);

    while (lines[i] && !error_msg)
    {
        handle_line_processing(lines, &i, &map_started, game, &error_msg);
        if (map_started || error_msg)
            break;
        i++;
    }

    check_map_found(map_started, &error_msg);
    cleanup_and_exit(lines, game, error_msg);
}
