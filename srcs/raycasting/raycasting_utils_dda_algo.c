/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_dda_algo.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 14:30:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 14:46:26 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_wall(t_game *game, t_ray *ray)
{
	char	tile;

	if (ray->in_map_grid_cell_x < 0
		|| ray->in_map_grid_cell_x >= game->data->map_width
		|| ray->in_map_grid_cell_y < 0
		|| ray->in_map_grid_cell_y >= game->data->map_height)
		return (1);
	tile = game->data->map[ray->in_map_grid_cell_y][ray->in_map_grid_cell_x];
	return (tile == '1');
}

static void	step_ray(t_ray *ray)
{
	double	dist_x;
	double	dist_y;

	dist_x = ray->ray_dda_distance_to_next_grid_cell_x;
	dist_y = ray->ray_dda_distance_to_next_grid_cell_y;
	if (dist_x < dist_y)
	{
		ray->ray_dda_distance_to_next_grid_cell_x
			+= ray->ray_dda_distance_between_grid_lines_x;
		ray->in_map_grid_cell_x += ray->ray_dda_grid_increment_direction_x;
		ray->ray_wall_collision_is_vertical = 0;
	}
	else
	{
		ray->ray_dda_distance_to_next_grid_cell_y
			+= ray->ray_dda_distance_between_grid_lines_y;
		ray->in_map_grid_cell_y += ray->ray_dda_grid_increment_direction_y;
		ray->ray_wall_collision_is_vertical = 1;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->ray_wall_collision_found == 0)
	{
		step_ray(ray);
		if (is_wall(game, ray))
			ray->ray_wall_collision_found = 1;
	}
}
