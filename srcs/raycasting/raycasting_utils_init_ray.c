/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_init_ray.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:39:39 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 16:32:46 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_ray_camera_position(t_ray *ray, int x, int w)
{
	ray->ray_camera_pos_x = 2 * x / (double)w - 1;
}

static void	calculate_ray_direction_vector(t_game *game, t_ray *ray)
{
	ray->ray_dir_vector_x = game->player_vector_direction_x
		+ game->camera_plane_x * ray->ray_camera_pos_x;
	ray->ray_dir_vector_y = game->player_vector_direction_y
		+ game->camera_plane_y * ray->ray_camera_pos_x;
}

static void	initialize_ray_grid_cell(t_game *game, t_ray *ray)
{
	ray->in_map_grid_cell_x = (int)game->player_pos_x;
	ray->in_map_grid_cell_y = (int)game->player_pos_y;
}

static void	calculate_dda_grid_distances(t_ray *ray)
{
	if (ray->ray_dir_vector_x != 0)
		ray->ray_dda_distance_between_grid_lines_x = fabs(1
				/ ray->ray_dir_vector_x);
	else
		ray->ray_dda_distance_between_grid_lines_x = 100.0;
	if (ray->ray_dir_vector_y != 0)
		ray->ray_dda_distance_between_grid_lines_y = fabs(1
				/ ray->ray_dir_vector_y);
	else
		ray->ray_dda_distance_between_grid_lines_y = 100.0;
}

void	init_ray(t_game *game, t_ray *ray, int x, int w)
{
	calculate_ray_camera_position(ray, x, w);
	calculate_ray_direction_vector(game, ray);
	initialize_ray_grid_cell(game, ray);
	calculate_dda_grid_distances(ray);
	ray->ray_wall_collision_found = 0;
}
