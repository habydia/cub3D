/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_draw_vertical_line.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 16:36:37 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	calculate_texture_y_coordinate(int tex_y, int tex_height)
{
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= tex_height)
		tex_y = tex_height - 1;
	return (tex_y);
}

static unsigned int	get_texture_pixel_color(t_texture_data *texture, int tex_x,
		int tex_y)
{
	if (texture->texture_pixel_buffer && tex_x >= 0
		&& tex_x < texture->texture_width && tex_y >= 0
		&& tex_y < texture->texture_height)
		return (*(unsigned int *)(texture->texture_pixel_buffer + (tex_y
					* texture->texture_bytes_per_scanline) + (tex_x * 4)));
	return (0xFFFFFF);
}

static int	calculate_wall_column_height(t_game *game, t_ray *ray, int h)
{
	if (ray->ray_perpendicular_distance_to_wall != 0)
		return ((int)(h / ray->ray_perpendicular_distance_to_wall));
	return (0);
}

static void	calculate_screen_draw_bounds(t_wall_column_render_params *params,
		int h)
{
	params->screen_draw_start_y = -params->wall_column_pixel_height / 2 + h / 2;
	params->screen_draw_end_y = params->wall_column_pixel_height / 2 + h / 2;
	if (params->screen_draw_start_y < 0)
		params->screen_draw_start_y = 0;
	if (params->screen_draw_end_y >= h)
		params->screen_draw_end_y = h - 1;
}

static void	calculate_texture_sampling_params(t_wall_column_render_params *params,
		int h)
{
	if (params->wall_column_pixel_height != 0)
		params->texture_sample_step = (double)params->texture->texture_height
			/ params->wall_column_pixel_height;
	else
		params->texture_sample_step = 0;
	params->texture_vertical_position = (params->screen_draw_start_y - h / 2
			+ params->wall_column_pixel_height / 2)
		* params->texture_sample_step;
}

void	render_wall_pixel_column(t_game *game, int x, int tex_x,
		t_wall_column_render_params params)
{
	int	y;
	int	tex_y;

	y = params.screen_draw_start_y;
	while (y <= params.screen_draw_end_y)
	{
		tex_y = calculate_texture_y_coordinate((int)params.texture_vertical_position,
				params.texture->texture_height);
		put_pixel(game, x, y, get_texture_pixel_color(params.texture, tex_x,
				tex_y));
		params.texture_vertical_position += params.texture_sample_step;
		y++;
	}
}

void	draw_wall_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	t_wall_column_render_params	params;
	t_texture_data				info;
	int							tex_x;

	get_texture_data(game, get_wall_face(game, ray), &info);
	params.texture = &info;
	params.wall_column_pixel_height = calculate_wall_column_height(game, ray,
			h);
	calculate_screen_draw_bounds(&params, h);
	tex_x = get_texture_column_for_display(game, ray,
			params.texture->texture_width);
	calculate_texture_sampling_params(&params, h);
	render_wall_pixel_column(game, x, tex_x, params);
}
