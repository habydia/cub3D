/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:00:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 01:08:17 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	get_wall_face(t_game *game, t_ray *ray);
void	get_texture_data(t_game *game, char face, t_texture_info *info);
int		compute_texture_x(t_game *game, t_ray *ray, int tex_w);

void	render_pixel_column(t_game *game, int x, int tex_x,
		t_draw_params params)
{
	int	y;
	int	tex_y;
	int	color;

	y = params.draw_start;
	while (y <= params.draw_end)
	{
		tex_y = (int)params.tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= params.tex_height)
			tex_y = params.tex_height - 1;
		if (params.tex_data && tex_x >= 0 && tex_x < params.tex_w && tex_y >= 0
			&& tex_y < params.tex_height)
			color = *(unsigned int *)(params.tex_data + (tex_y
						* params.line_len) + (tex_x * 4));
		else
			color = 0xFFFFFF;
		params.tex_pos += params.step;
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	t_draw_params	params;
	t_texture_info	info;
	int				tex_x;

	get_texture_data(game, get_wall_face(game, ray), &info);
	params.tex_data = info.data;
	params.tex_w = info.width;
	params.tex_height = info.height;
	params.line_len = info.line_len;
	params.line_height = (int)(h / ray->perp_wall_dist);
	params.draw_start = -params.line_height / 2 + h / 2;
	params.draw_end = params.line_height / 2 + h / 2;
	if (params.draw_start < 0)
		params.draw_start = 0;
	if (params.draw_end >= h)
		params.draw_end = h - 1;
	tex_x = compute_texture_x(game, ray, params.tex_w);
	params.step = (double)params.tex_height / params.line_height;
	params.tex_pos = (params.draw_start - h / 2 + params.line_height / 2)
		* params.step;
	render_pixel_column(game, x, tex_x, params);
}
