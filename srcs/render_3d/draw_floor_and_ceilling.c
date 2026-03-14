/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceilling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:30:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 01:47:11 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	put_pixel(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (!game || !game->pixel_buffer)
	{
		printf("Error: pixel_buffer not initialized!\n");
		return ;
	}
	if (x < 0 || x >= 800 || y < 0 || y >= 600)
		return ;
	dst = game->pixel_buffer + (y * game->bytes_per_scanline + x
			* (game->bits_for_one_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(game->data->ceiling_color[0],
			game->data->ceiling_color[1], game->data->ceiling_color[2]);
	floor_color = rgb_to_int(game->data->floor_color[0],
			game->data->floor_color[1], game->data->floor_color[2]);
	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			if (y < 300)
				put_pixel(game, x, y, ceiling_color);
			else
				put_pixel(game, x, y, floor_color);
			x++;
		}
		y++;
	}
}
