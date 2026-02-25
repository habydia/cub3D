/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_correct_fisheye.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:00:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 18:28:49 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <math.h>

double	correct_fisheye_distance(t_game *game, t_ray *ray)
{
	double	perp_distance;
	double	angle_diff;
	double	cos_correction;

	perp_distance = ray->ray_perpendicular_distance_to_wall;
	angle_diff = atan2(ray->ray_dir_vector_y, ray->ray_dir_vector_x)
		- atan2(game->player.direction_y, game->player.direction_x);
	cos_correction = cos(angle_diff);
	if (cos_correction < 0.01)
		cos_correction = 0.01;
	return (perp_distance / cos_correction);
}
