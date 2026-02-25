/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:39:39 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 18:16:17 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x, int w)
{
	ray->ray_camera_pos_x = 2 * x / (double)w - 1;
	ray->ray_dir_vector_x = game->player_vector_direction_x + game->camera_plane_x * ray->ray_camera_pos_x;
	ray->ray_dir_vector_y = game->player_vector_direction_y + game->camera_plane_y * ray->ray_camera_pos_x;
	ray->in_map_grid_cell_x = (int)game->player_pos_x;
	ray->in_map_grid_cell_y = (int)game->player_pos_y;
	ray->ray_dda_distance_between_grid_lines_x = fabs(1 / ray->ray_dir_vector_x);
	ray->ray_dda_distance_between_grid_lines_y = fabs(1 / ray->ray_dir_vector_y);
	ray->ray_wall_collision_found = 0;
}

void	calculate_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_vector_x < 0)
	{
		ray->ray_dda_grid_increment_direction_x = -1;
		ray->ray_dda_distance_to_next_grid_cell_x = (game->player_pos_x - ray->in_map_grid_cell_x) * ray->ray_dda_distance_between_grid_lines_x;
	}
	else
	{
		ray->ray_dda_grid_increment_direction_x = 1;
		ray->ray_dda_distance_to_next_grid_cell_x = (ray->in_map_grid_cell_x + 1.0 - game->player_pos_x)
			* ray->ray_dda_distance_between_grid_lines_x;
	}
	if (ray->ray_dir_vector_y < 0)
	{
		ray->ray_dda_grid_increment_direction_y = -1;
		ray->ray_dda_distance_to_next_grid_cell_y = (game->player_pos_y - ray->in_map_grid_cell_y) * ray->ray_dda_distance_between_grid_lines_y;
	}
	else
	{
		ray->ray_dda_grid_increment_direction_y = 1;
		ray->ray_dda_distance_to_next_grid_cell_y = (ray->in_map_grid_cell_y + 1.0 - game->player_pos_y)
			* ray->ray_dda_distance_between_grid_lines_y;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->ray_wall_collision_found == 0)
	{
		if (ray->ray_dda_distance_to_next_grid_cell_x < ray->ray_dda_distance_to_next_grid_cell_y)
		{
			ray->ray_dda_distance_to_next_grid_cell_x += ray->ray_dda_distance_between_grid_lines_x;
			ray->in_map_grid_cell_x += ray->ray_dda_grid_increment_direction_x;
			ray->ray_wall_collision_is_vertical = 0;
		}
		else
		{
			ray->ray_dda_distance_to_next_grid_cell_y += ray->ray_dda_distance_between_grid_lines_y;
			ray->in_map_grid_cell_y += ray->ray_dda_grid_increment_direction_y;
			ray->ray_wall_collision_is_vertical = 1;
		}
		if (game->data->map[ray->in_map_grid_cell_y][ray->in_map_grid_cell_x] == '1')
			ray->ray_wall_collision_found = 1;
	}
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->ray_wall_collision_is_vertical == 0)
		ray->ray_perpendicular_distance_to_wall = (ray->in_map_grid_cell_x - game->player_pos_x + (1 - ray->ray_dda_grid_increment_direction_x)
				/ 2) / ray->ray_dir_vector_x;
	else
		ray->ray_perpendicular_distance_to_wall = (ray->in_map_grid_cell_y - game->player_pos_y + (1 - ray->ray_dda_grid_increment_direction_y)
				/ 2) / ray->ray_dir_vector_y;
}
