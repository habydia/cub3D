/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_calculate_step.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 15:52:45 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 16:03:21 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_step_x(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_vector_x < 0)
	{
		ray->ray_dda_grid_increment_direction_x = -1;
		ray->ray_dda_distance_to_next_grid_cell_x = (game->player_pos_x
				- ray->in_map_grid_cell_x)
			* ray->ray_dda_distance_between_grid_lines_x;
	}
	else
	{
		ray->ray_dda_grid_increment_direction_x = 1;
		ray->ray_dda_distance_to_next_grid_cell_x = (ray->in_map_grid_cell_x
				+ 1.0 - game->player_pos_x)
			* ray->ray_dda_distance_between_grid_lines_x;
	}
}

static void	calculate_step_y(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_vector_y < 0)
	{
		ray->ray_dda_grid_increment_direction_y = -1;
		ray->ray_dda_distance_to_next_grid_cell_y = (game->player_pos_y
				- ray->in_map_grid_cell_y)
			* ray->ray_dda_distance_between_grid_lines_y;
	}
	else
	{
		ray->ray_dda_grid_increment_direction_y = 1;
		ray->ray_dda_distance_to_next_grid_cell_y = (ray->in_map_grid_cell_y
				+ 1.0 - game->player_pos_y)
			* ray->ray_dda_distance_between_grid_lines_y;
	}
}

void	calculate_step(t_game *game, t_ray *ray)
{
	calculate_step_x(game, ray);
	calculate_step_y(game, ray);
}
