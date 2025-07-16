/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_raycasting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugi <ahugi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:31:31 by ahugi             #+#    #+#             */
/*   Updated: 2025/07/16 13:31:32 by ahugi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/* Checks what direction the player is facing, */
/* and sets the direction and plane (edges of the vision). */
/* CPV = Camera Plane Vector */
void	get_direction_and_plane(t_raycasting *ray, t_map *map, double cpv)
{
	ray->plane_x = 0;
	ray->plane_y = 0;
	if (map->p_view == 'N')
	{
		ray->plane_x = cpv;
		map->p_angle = PI / 2;
	}
	if (map->p_view == 'S')
	{
		ray->plane_x = -cpv;
		map->p_angle = 3 * PI / 2;
	}
	if (map->p_view == 'E')
	{
		ray->plane_y = cpv;
		map->p_angle = 0;
	}
	if (map->p_view == 'W')
	{
		ray->plane_y = -cpv;
		map->p_angle = PI;
	}
	ray->p_dir_x = cos(map->p_angle);
	ray->p_dir_y = -sin(map->p_angle);
}

/* on every change of view direction, */
/* calculate the necessary variables to do the ray casting. */
/* This only happens at the start of the game, */
void	init_raycasting(t_raycasting *ray, t_map *map)
{
	double	fov;
	double	cpv;

	fov = 60 * (3.141592 / 180);
	cpv = tan(fov / 2);
	get_direction_and_plane(ray, map, cpv);
}
