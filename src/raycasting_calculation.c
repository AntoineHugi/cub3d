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
		ray->side_dist_x = (map->p_posx - ray->ray_pos_x) \
			* ray->delta_dist_x;
	else
		ray->side_dist_x = (ray->ray_pos_x + 1 - map->p_posx) \
			* ray->delta_dist_x;
	if (ray->ray_dir_y < 0)
		ray->side_dist_y = (map->p_posy - ray->ray_pos_y) \
			* ray->delta_dist_y;
	else
		ray->side_dist_y = (ray->ray_pos_y + 1 - map->p_posy) \
			* ray->delta_dist_y;
}

/* logs the distance of the wall compared to the player */
void	get_wall_distance(t_raycasting *ray, t_map *map)
{
	if (ray->side_hit == 0)
		ray->wall_dist = (ray->ray_pos_x - map->p_posx \
			+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->wall_dist = (ray->ray_pos_y - map->p_posy \
			+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

/* iterates step by step until we hit a wall, */
/* and checks if this wall was hit on the x axis or the y axis */
void	cast_ray(t_raycasting *ray, t_map *map)
{
	while (!ray->hit_wall)
	{
		if (ray->side_dist_x < ray->side_dist_y) 
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->ray_pos_x += ray->step_x;
			ray->side_hit = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->ray_pos_y += ray->step_y;
			ray->side_hit = 1;
		}
		if (ray->ray_pos_x < 0 || ray->ray_pos_x >= map->map_width
			|| ray->ray_pos_y < 0 || ray->ray_pos_y >= map->map_height)
			break ;
		if (map->map_array[ray->ray_pos_y][ray->ray_pos_x] == '1') 
			ray->hit_wall = 1;
	}
}

/* Calculates for each ray the direction of the ray, */
/* the distance it travels per grid and then */
/* casts the ray and logs the distance it travelled */
void	calculate_raycasting(t_raycasting *ray, t_map *map, int i)
{
	ray->hit_wall = 0;
	ray->screen_pos = 2 * i / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = ray->p_dir_x + ray->plane_x * ray->screen_pos;
	ray->ray_dir_y = ray->p_dir_y + ray->plane_y * ray->screen_pos;
	get_distance_and_step(ray, map);
	cast_ray(ray, map);
	get_wall_distance(ray, map);
}
