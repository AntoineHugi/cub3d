#include "../inc/cub3d.h"

/* calculates the delta distance a ray travels to move by one grid line */
/* (either on the x-axis or the y-axis), */
/* and calculates the step for each iteration */
/* (the direction the ray is moving on the x/y axis) */
void	get_distance_and_step(t_raycasting *ray, t_map *map)
{
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	if (ray->ray_dir_x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir_y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
	if (ray->ray_dir_x < 0)
		ray->side_dist_x = (map->p_posx - ray->map_x) * ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->map_x + 1 - map->p_posx) * ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (map->p_posy - ray->map_y) * ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->map_y + 1 - map->p_posy) * ray->delta_dist_y;
}

/* logs the distance of the wall compared to the player */
void	get_wall_distance(t_raycasting *ray, t_map *map)
{
	if (ray->side_hit == 0)
		ray->wall_dist = (ray->map_x - map->p_posx + (1 - ray->step_x) / 2)
			/ ray->ray_dir_x;
	else if (ray->side_hit == 1)
		ray->wall_dist = (ray->map_y - map->p_posy + (1 - ray->step_y) / 2)
			/ ray->ray_dir_y;
	if (ray->wall_dist <= 0)
		printf("wall dist is 0 or negative: %f\n", ray->wall_dist);
}

/* iterates step by step until we hit a wall, */
/* and checks if this wall was hit on the x axis or the y axis */
void	cast_ray(t_raycasting *ray, t_map *map)
{
	while (!ray->wall_hit)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side_hit = 1;
		}
		if (ray->map_x < 0 || ray->map_x >= map->map_width || ray->map_y < 0
			|| ray->map_y >= map->map_height)
			break ;
		if (map->map_array[ray->map_y][ray->map_x] == '1')
			ray->wall_hit = 1;
		if (map->map_array[ray->map_y][ray->map_x] == 'D')
			ray->wall_hit = 2;
	}
}

/* first checks the position of the player and set the ray starting position */
/* Calculates for each ray the direction of the ray, */
/* the distance it travels per grid and then */
/* casts the ray and logs the distance it travelled */
void	calculate_raycasting(t_raycasting *ray, t_map *map, int i)
{
	ray->ray_pos_x = map->p_posx;
	ray->ray_pos_y = map->p_posy;
	ray->map_x = (int)map->p_posx;
	ray->map_y = (int)map->p_posy;
	ray->wall_hit = 0;
	ray->side_hit = -1;
	ray->wall_dist = -1;
	ray->screen_pos = 2.0 * i / (double)WIN_WIDTH - 1.0;
	ray->ray_dir_x = ray->p_dir_x + ray->plane_x * ray->screen_pos;
	ray->ray_dir_y = ray->p_dir_y + ray->plane_y * ray->screen_pos;
	get_distance_and_step(ray, map);
	cast_ray(ray, map);
	get_wall_distance(ray, map);
}
