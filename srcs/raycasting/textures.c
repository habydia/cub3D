/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:15:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/24 02:01:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_wall_face(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->map_x == 0)
			return ('W');
		if (ray->map_x == game->data->map_width - 1)
			return ('E');
		if (ray->ray_dir_x > 0)
			return ('E');
		return ('W');
	}
	else
	{
		if (ray->map_y == 0)
			return ('N');
		if (ray->map_y == game->data->map_height - 1)
			return ('S');
		if (ray->ray_dir_y > 0)
			return ('S');
		return ('N');
	}
}

int	compute_texture_x(t_game *game, t_ray *ray, int tex_w)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player_pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player_pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex_w);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		tex_x = tex_w - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		tex_x = tex_w - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_w)
		tex_x = tex_w - 1;
	return (tex_x);
}
