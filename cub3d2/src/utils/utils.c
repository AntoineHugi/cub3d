/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:22:44 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 09:58:49 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


// This is a simplified function to read lines.
// A more robust get_next_line (like the one from 42) is recommended.
char    **read_file_lines(int fd)
{
    char **lines = malloc(sizeof(char*) * 1024); // Assume max 1024 lines
    char buffer[10000];
    char *line;
    int bytes_read;
    int i = 0;

    bytes_read = read(fd, buffer, 9999);
    buffer[bytes_read] = '\0';

    char *current = buffer;
    while((line = strsep(&current, "\n")) != NULL)
    {
        if (*line) // Not an empty line
            lines[i++] = ft_strdup(line);
    }
    lines[i] = NULL;
    return lines;
}
