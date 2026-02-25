/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 16:18:17 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_minimap_color(char tile)
{
	if (tile == '1')
		return (0xFFFFFF);
	return (0x000000);
}

void	draw_minimap_case(t_game *game, t_pixel_square d)
{
	int	position_x;
	int	position_y;

	position_y = 0;
	while (position_y < d.square_size)
	{
		position_x = 0;
		while (position_x < d.square_size)
		{
			put_pixel(game, d.screen_start_x * d.square_size + position_x,
				d.screen_start_y * d.square_size + position_y, d.color);
			position_x++;
		}
		position_y++;
	}
}

void	draw_minimap_line(t_game *game, int y, int square_size)
{
	int				x;
	t_pixel_square	d;

	x = 0;
	while (x < game->data->map_width)
	{
		d.screen_start_x = x;
		d.screen_start_y = y;
		d.square_size = square_size;
		d.color = get_minimap_color(game->data->map[y][x]);
		draw_minimap_case(game, d);
		x++;
	}
}

void	draw_player_red_minimap(t_game *game, int map_scale_for_pixel)
{
	int	player_px;
	int	player_py;
	int	i;
	int	j;

	player_px = (int)(game->player_pos_x * map_scale_for_pixel);
	player_py = (int)(game->player_pos_y * map_scale_for_pixel);
	i = -2;
	while (i <= 2)
	{
		j = -2;
		while (j <= 2)
		{
			put_pixel(game, player_px + i, player_py + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	y;
	int	square_size;

	square_size = 10;
	y = 0;
	while (y < game->data->map_height)
	{
		draw_minimap_line(game, y, square_size);
		y++;
	}
	draw_player_red_minimap(game, square_size);
}
