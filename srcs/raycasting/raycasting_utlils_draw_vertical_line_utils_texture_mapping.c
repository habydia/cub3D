/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utlils_draw_vertical_line_utils_        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:15:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/26 16:28:04 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_wall_face(t_game *game, t_ray *ray)
{
	if (ray->ray_wall_collision_is_vertical == 0)
	{
		if (ray->in_map_grid_cell_x == 0)
			return ('W');
		if (ray->in_map_grid_cell_x == game->data->map_width - 1)
			return ('E');
		if (ray->ray_dir_vector_x > 0)
			return ('E');
		return ('W');
	}
	else
	{
		if (ray->in_map_grid_cell_y == 0)
			return ('N');
		if (ray->in_map_grid_cell_y == game->data->map_height - 1)
			return ('S');
		if (ray->ray_dir_vector_y > 0)
			return ('S');
		return ('N');
	}
}

static double	calculate_wall_hit_position(t_game *game, t_ray *ray)
{
	if (ray->ray_wall_collision_is_vertical == 0)
		return (game->player_pos_y + ray->ray_perpendicular_distance_to_wall
			* ray->ray_dir_vector_y);
	else
		return (game->player_pos_x + ray->ray_perpendicular_distance_to_wall
			* ray->ray_dir_vector_x);
}

static int	get_texture_pixel_from_wall_position(double wall_x, int tex_w)
{
	wall_x -= floor(wall_x);
	return ((int)(wall_x * tex_w));
}

static int	adjust_texture_x_for_viewing_direction(int tex_x, int tex_w,
		t_ray *ray)
{
	if (ray->ray_wall_collision_is_vertical == 0 && ray->ray_dir_vector_x < 0)
		tex_x = tex_w - tex_x - 1;
	if (ray->ray_wall_collision_is_vertical == 1 && ray->ray_dir_vector_y > 0)
		tex_x = tex_w - tex_x - 1;
	return (tex_x);
}

int	get_texture_column_for_display(t_game *game, t_ray *ray, int tex_w)
{
	int		tex_x;
	double	wall_pos;

	wall_pos = calculate_wall_hit_position(game, ray);
	tex_x = get_texture_pixel_from_wall_position(wall_pos, tex_w);
	tex_x = adjust_texture_x_for_viewing_direction(tex_x, tex_w, ray);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_w)
		tex_x = tex_w - 1;
	return (tex_x);
}
