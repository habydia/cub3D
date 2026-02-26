/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_draw_vertical_line_utils_r        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:40:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 16:50:29 by lebroue          ###   ########.fr       */
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
	unsigned int	color;
	int				offset;

	if (!texture->texture_pixel_buffer || tex_x < 0
		|| tex_x >= texture->texture_width || tex_y < 0
		|| tex_y >= texture->texture_height)
		return (0xFFFFFF);
	offset = (tex_y * texture->texture_bytes_per_scanline) + (tex_x * 4);
	color = *(unsigned int *)(texture->texture_pixel_buffer + offset);
	return (color);
}

void	render_wall_pixel_column(t_game *game, int x, int tex_x,
		t_wall_column_render_params params)
{
	int	y;
	int	tex_y;
	int	tex_pos;

	y = params.screen_draw_start_y;
	while (y <= params.screen_draw_end_y)
	{
		tex_pos = (int)params.texture_vertical_position;
		tex_y = calculate_texture_y_coordinate(tex_pos,
				params.texture->texture_height);
		put_pixel(game, x, y, get_texture_pixel_color(params.texture, tex_x,
				tex_y));
		params.texture_vertical_position += params.texture_sample_step;
		y++;
	}
}
