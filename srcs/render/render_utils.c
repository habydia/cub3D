/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 14:47:47 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/13 17:24:39 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Convertit des composantes R, G, B en un entier couleur 0xRRGGBB
int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void put_pixel(t_game *game, int x, int y, int color)
{
    char *dst;

    if (!game || !game->img_data)
    {
        fprintf(stderr, "Erreur : img_data non initialisé !\n");
        return;
    }

    if (x < 0 || x >= 800 || y < 0 || y >= 600)
        return;

    dst = game->img_data + (y * game->line_len_in_octet + x * (game->bit_per_pixel / 8));
    *(unsigned int *)dst = color;
}


void	draw_floor_and_ceiling(t_game *game) // dessine le sol et le plafond
{
	int x, y;
	int ceiling_color = rgb_to_int(game->data->ceiling_color[0],
			game->data->ceiling_color[1], game->data->ceiling_color[2]);
	int floor_color = rgb_to_int(game->data->floor_color[0],
			game->data->floor_color[1], game->data->floor_color[2]);

	y = 0;
	while (y < 600) // hauteur de la fenêtre
	{
		x = 0;
		while (x < 800) // largeur de la fenêtre
		{
			if (y < 300) // moitié haute = plafond
				put_pixel(game, x, y, ceiling_color);
			else // moitié basse = sol
				put_pixel(game, x, y, floor_color);
			x++;
		}
		y++;
	}
}
