/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_calculate_wall_distance.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:10:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 18:28:49 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	double	offset;
	double	ray_length;
	double	dot_product;
	double	ray_length_magnitude;

	offset = (1 - ray->ray_dda_grid_increment_direction_x) / 2;
	if (ray->ray_wall_collision_is_vertical == 0)
	{
		if (ray->ray_dir_vector_x != 0)
			ray_length = (ray->in_map_grid_cell_x - game->player_pos_x + offset)
				/ ray->ray_dir_vector_x;
		else
			ray_length = 50.0;
	}
	else
	{
		offset = (1 - ray->ray_dda_grid_increment_direction_y) / 2;
		if (ray->ray_dir_vector_y != 0)
			ray_length = (ray->in_map_grid_cell_y - game->player_pos_y + offset)
				/ ray->ray_dir_vector_y;
		else
			ray_length = 50.0;
	}
	ray_length_magnitude = sqrt(ray->ray_dir_vector_x * ray->ray_dir_vector_x
			+ ray->ray_dir_vector_y * ray->ray_dir_vector_y);
	if (ray_length_magnitude > 0)
	{
		dot_product = (game->player_vector_direction_x * ray->ray_dir_vector_x
				+ game->player_vector_direction_y * ray->ray_dir_vector_y)
			/ ray_length_magnitude;
		ray->ray_perpendicular_distance_to_wall = ray_length * dot_product;
	}
	else
		ray->ray_perpendicular_distance_to_wall = ray_length;
}
