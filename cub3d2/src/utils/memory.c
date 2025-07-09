/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokwuful <<bokwuful@student.42berlin.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 09:19:37 by bokwuful          #+#    #+#             */
/*   Updated: 2025/07/06 10:04:29 by bokwuful         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <string.h>

void free_string_array(char **arr)
{
    if (!arr) return;
    for (int i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);
}

char *ft_strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *new_str = malloc(len);
    if (!new_str) return NULL;
    memcpy(new_str, s, len);
    return new_str;
}

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i]) i++;
    return i;
}
