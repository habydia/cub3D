/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:15:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 18:42:19 by lebroue          ###   ########.fr       */
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
			return ('W');
		return ('E');
	}
	else
	{
		if (ray->map_y == 0)
			return ('N');
		if (ray->map_y == game->data->map_height - 1)
			return ('S');
		if (ray->ray_dir_y > 0)
			return ('N');
		return ('S');
	}
}

static void	get_texture_data(t_game *game, char face, char **data, int *w,
		int *h, int *line_len)
{
	if (face == 'N')
	{
		*data = game->textures.north_data;
		*w = game->textures.north_width;
		*h = game->textures.north_height;
		*line_len = game->textures.north_line_len;
	}
	else if (face == 'S')
	{
		*data = game->textures.south_data;
		*w = game->textures.south_width;
		*h = game->textures.south_height;
		*line_len = game->textures.south_line_len;
	}
	else if (face == 'E')
	{
		*data = game->textures.east_data;
		*w = game->textures.east_width;
		*h = game->textures.east_height;
		*line_len = game->textures.east_line_len;
	}
	else
	{
		*data = game->textures.west_data;
		*w = game->textures.west_width;
		*h = game->textures.west_height;
		*line_len = game->textures.west_line_len;
	}
}

static int	compute_texture_x(t_game *game, t_ray *ray, int tex_w)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->player_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player_x + ray->perp_wall_dist * ray->ray_dir_x;
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

static void	render_pixel_column(t_game *game, int x, int tex_x,
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
		params.tex_pos += params.step;
		if (params.tex_data && tex_x >= 0 && tex_x < params.tex_w && tex_y >= 0
			&& tex_y < params.tex_height)
			color = *(unsigned int *)(params.tex_data + (tex_y
						* params.line_len) + (tex_x * 4));
		else
			color = 0xFFFFFF;
		put_pixel(game, x, y, color);
		y++;
	}
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	t_draw_params params;
	char face;
	int tex_x;

	face = get_wall_face(game, ray);
	get_texture_data(game, face, &params.tex_data, &params.tex_w,
		&params.tex_height, &params.line_len);
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