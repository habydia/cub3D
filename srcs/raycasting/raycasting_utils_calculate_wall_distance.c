/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_calculate_wall_distance.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:10:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 18:40:20 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

static double	calculate_ray_length_horizontal(t_game *game, t_ray *ray,
		double offset)
{
	if (ray->ray_dir_vector_x != 0)
		return ((ray->in_map_grid_cell_x - game->player_pos_x + offset)
			/ ray->ray_dir_vector_x);
	return (50.0);
}

static double	calculate_ray_length_vertical(t_game *game, t_ray *ray,
		double offset)
{
	if (ray->ray_dir_vector_y != 0)
		return ((ray->in_map_grid_cell_y - game->player_pos_y + offset)
			/ ray->ray_dir_vector_y);
	return (50.0);
}

static double	apply_perp_corr(t_game *game, t_ray *ray, double ray_length)
{
	double	ray_magnitude;
	double	dot_product;

	ray_magnitude = sqrt(ray->ray_dir_vector_x * ray->ray_dir_vector_x
			+ ray->ray_dir_vector_y * ray->ray_dir_vector_y);
	if (ray_magnitude <= 0)
		return (ray_length);
	dot_product = (game->player_vector_direction_x * ray->ray_dir_vector_x
			+ game->player_vector_direction_y * ray->ray_dir_vector_y)
		/ ray_magnitude;
	return (ray_length * dot_product);
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	double	offset;
	double	ray_length;

	if (ray->ray_wall_collision_is_vertical == 0)
		offset = (1 - ray->ray_dda_grid_increment_direction_x) / 2;
	else
		offset = (1 - ray->ray_dda_grid_increment_direction_y) / 2;
	if (ray->ray_wall_collision_is_vertical == 0)
		ray_length = calculate_ray_length_horizontal(game, ray, offset);
	else
		ray_length = calculate_ray_length_vertical(game, ray, offset);
	ray->ray_perpendicular_distance_to_wall = apply_perp_corr(game, ray,
			ray_length);
}
