/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 11:02:13 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_wall_face(t_game *game, t_ray *ray);
void	get_texture_data(t_game *game, char face, t_texture_data *info);
int		compute_texture_x(t_game *game, t_ray *ray, int tex_w);

void	render_pixel_column(t_game *game, int x, int tex_x,
		t_wall_column_render_params params)
{
	int	y;
	int	tex_y;
	int	color;

	y = params.screen_draw_start_y;
	while (y <= params.screen_draw_end_y)
	{
		tex_y = (int)params.texture_vertical_position;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= params.texture->texture_height)
			tex_y = params.texture->texture_height - 1;
		if (params.texture->texture_pixel_buffer && tex_x >= 0
			&& tex_x < params.texture->texture_width && tex_y >= 0
			&& tex_y < params.texture->texture_height)
			color = *(unsigned int *)(params.texture->texture_pixel_buffer
					+ (tex_y * params.texture->texture_bytes_per_scanline)
					+ (tex_x * 4));
		else
			color = 0xFFFFFF;
		params.texture_vertical_position += params.texture_sample_step;
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	t_wall_column_render_params	params;
	t_texture_data				info;
	int							tex_x;

	get_texture_data(game, get_wall_face(game, ray), &info);
	params.texture = &info;
	params.wall_column_pixel_height = (int)(h
			/ ray->ray_perpendicular_distance_to_wall);
	params.screen_draw_start_y = -params.wall_column_pixel_height / 2 + h / 2;
	params.screen_draw_end_y = params.wall_column_pixel_height / 2 + h / 2;
	if (params.screen_draw_start_y < 0)
		params.screen_draw_start_y = 0;
	if (params.screen_draw_end_y >= h)
		params.screen_draw_end_y = h - 1;
	tex_x = compute_texture_x(game, ray, params.texture->texture_width);
	params.texture_sample_step = (double)params.texture->texture_height
		/ params.wall_column_pixel_height;
	params.texture_vertical_position = (params.screen_draw_start_y - h / 2
			+ params.wall_column_pixel_height / 2) * params.texture_sample_step;
	render_pixel_column(game, x, tex_x, params);
}
