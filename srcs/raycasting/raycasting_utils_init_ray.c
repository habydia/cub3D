/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_init_ray.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:39:39 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 15:53:02 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x, int w)
{
	ray->ray_camera_pos_x = 2 * x / (double)w - 1;
	ray->ray_dir_vector_x = game->player_vector_direction_x
		+ game->camera_plane_x * ray->ray_camera_pos_x;
	ray->ray_dir_vector_y = game->player_vector_direction_y
		+ game->camera_plane_y * ray->ray_camera_pos_x;
	ray->in_map_grid_cell_x = (int)game->player_pos_x;
	ray->in_map_grid_cell_y = (int)game->player_pos_y;
	ray->ray_dda_distance_between_grid_lines_x = fabs(1
			/ ray->ray_dir_vector_x);
	ray->ray_dda_distance_between_grid_lines_y = fabs(1
			/ ray->ray_dir_vector_y);
	ray->ray_wall_collision_found = 0;
}
