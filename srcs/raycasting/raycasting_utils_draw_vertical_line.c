/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_draw_vertical_line.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 18:26:47 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	calculate_wall_column_height(t_ray *ray, int h)
{
	if (ray->ray_perpendicular_distance_to_wall != 0)
		return ((int)(h / ray->ray_perpendicular_distance_to_wall));
	return (0);
}

static void	set_wall_column_display_window(t_wall_column_render_params *params,
		int h)
{
	params->screen_draw_start_y = -params->wall_column_pixel_height / 2 + h / 2;
	params->screen_draw_end_y = params->wall_column_pixel_height / 2 + h / 2;
	if (params->screen_draw_start_y < 0)
		params->screen_draw_start_y = 0;
	if (params->screen_draw_end_y >= h)
		params->screen_draw_end_y = h - 1;
}

static void	prepare_texture_vertical_display(t_wall_column_render_params *p,
		int h)
{
	double	start_offset;

	if (p->wall_column_pixel_height != 0)
		p->texture_sample_step = (double)p->texture->texture_height
			/ p->wall_column_pixel_height;
	else
		p->texture_sample_step = 0;
	start_offset = (p->screen_draw_start_y - h / 2 + p->wall_column_pixel_height
			/ 2);
	p->texture_vertical_position = start_offset * p->texture_sample_step;
}

void	draw_wall_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	t_wall_column_render_params	params;
	t_texture_data				info;
	int							tex_x;

	get_texture_data(game, get_wall_face(game, ray), &info);
	params.texture = &info;
	params.wall_column_pixel_height = calculate_wall_column_height(ray, h);
	set_wall_column_display_window(&params, h);
	tex_x = get_texture_column_for_display(game, ray,
			params.texture->texture_width);
	prepare_texture_vertical_display(&params, h);
	render_wall_pixel_column(game, x, tex_x, params);
}
