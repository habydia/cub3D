/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_and_ceilling.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:30:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
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

	if (!game || !game->img_data)
	{
		fprintf(stderr, "Erreur : img_data non initialisé !\n");
		return ;
	}
	if (x < 0 || x >= 800 || y < 0 || y >= 600)
		return ;
	dst = game->img_data + (y * game->line_len + x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_and_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	ceiling_color;
	int	floor_color;

	ceiling_color = rgb_to_int(game->data->colors.ceiling_color[0],
			game->data->colors.ceiling_color[1], game->data->colors.ceiling_color[2]);
	floor_color = rgb_to_int(game->data->colors.floor_color[0],
			game->data->colors.floor_color[1], game->data->colors.floor_color[2]);
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
