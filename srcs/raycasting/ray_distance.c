/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:10:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 13:13:02 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	double	offset;

	offset = (1 - ray->ray_dda_grid_increment_direction_x) / 2;
	if (ray->ray_wall_collision_is_vertical == 0)
	{
		ray->ray_perpendicular_distance_to_wall = (ray->in_map_grid_cell_x
				- game->player_pos_x + offset) / ray->ray_dir_vector_x;
	}
	else
	{
		offset = (1 - ray->ray_dda_grid_increment_direction_y) / 2;
		ray->ray_perpendicular_distance_to_wall = (ray->in_map_grid_cell_y
				- game->player_pos_y + offset) / ray->ray_dir_vector_y;
	}
}
