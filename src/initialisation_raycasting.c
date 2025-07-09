#include "../inc/cub3d.h"

/* Checks what direction the player is facing, */
/* and sets the direction and plane (edges of the vision). */
/* CPV = Camera Plane Vector */
void	get_direction_and_plane(t_raycasting *ray, t_map *map, double cpv)
{
	ray->p_dir_x = 0;
	ray->p_dir_y = 0;
	ray->plane_x = 0;
	ray->plane_y = 0;
	if (map->map_array[map->p_posy][map->p_posx] == 'N')
	{
		ray->p_dir_y = -1;
		ray->plane_x = cpv;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'S')
	{
		ray->p_dir_y = 1;
		ray->plane_x = -cpv;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'E')
	{
		ray->p_dir_x = 1;
		ray->plane_y = cpv;
	}
	if (map->map_array[map->p_posy][map->p_posx] == 'W')
	{
		ray->p_dir_x = -1;
		ray->plane_y = -cpv;
	}
}

/* on every change of view direction, */
/* calculate the necessary variables to do the ray casting. */
/* This only happens at the start of the game, */
/* or whenever the player changes direction */
void	init_raycasting(t_raycasting *ray, t_map *map)
{
	double	fov;
	double	cpv;

	fov = 60 * (3.141592 / 180);
	cpv = tan(fov / 2);
	get_direction_and_plane(ray, map, cpv);
}
