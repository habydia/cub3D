/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:48:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 15:49:16 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_game *game) // ADDED BY LEO
{
	int x;
	int y;
	int position_x;
	int position_y;
	int map_scale_for_pixel;
	int color;

	map_scale_for_pixel = 10; // taille d’une case en pixels
	y = 0;

	while (y < game->data->map_height)
	{
		x = 0;
		while (x < game->data->map_width)
		{
			// Choix de la couleur
			if (game->data->map[y][x] == '1')
				color = 0xFFFFFF; // mur blanc
			else
				color = 0x000000; // vide noir

			// Dessiner la case a la position (x, y) avec scale
			position_y = 0;
			while (position_y < map_scale_for_pixel)
			{
				position_x = 0;
				while (position_x < map_scale_for_pixel)
				{
					put_pixel(game, x * map_scale_for_pixel + position_x, y * map_scale_for_pixel + position_y,
						color);
					position_x++;
				}
				position_y++;
			}
			x++;
		}
		y++;
	}

	// Dessiner le joueur (rouge)
	int player_px = (int)(game->player_x * map_scale_for_pixel);
	int player_py = (int)(game->player_y * map_scale_for_pixel);

	int i = -2;
	while (i <= 2)
	{
		int j = -2;
		while (j <= 2)
		{
			put_pixel(game, player_px + i, player_py + j, 0xFF0000);
			j++;
		}
		i++;
	}
}
