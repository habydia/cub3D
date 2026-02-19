/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:10:37 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 16:53:05 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	game->keys[keycode] = 1;
	if (keycode == 119) // W
		printf("Touche W pressée - Avancer\n");
	else if (keycode == 97) // A
		printf("Touche A pressée - Gauche\n");
	else if (keycode == 115) // S
		printf("Touche S pressée - Reculer\n");
	else if (keycode == 100) // D
		printf("Touche D pressée - Droite\n");
	else if (keycode == 65361) // Left arrow
		printf("Flèche gauche pressée - Rotation gauche\n");
	else if (keycode == 65363) // Right arrow
		printf("Flèche droite pressée - Rotation droite\n");
	else if (keycode == 65362) // Up arrow
		printf("Flèche haut pressée\n");
	else if (keycode == 65364) // Down arrow
		printf("Flèche bas pressée\n");
	else if (keycode == 65480) // F11
		printf("Touche F11 pressée - Maximisation\n");
	else
		printf("Touche pressée: %d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	game->keys[keycode] = 0;
	if (keycode == 119) // W
		printf("Touche W relâchée\n");
	else if (keycode == 97) // A
		printf("Touche A relâchée\n");
	else if (keycode == 115) // S
		printf("Touche S relâchée\n");
	else if (keycode == 100) // D
		printf("Touche D relâchée\n");
	else if (keycode == 65361) // Left arrow
		printf("Flèche gauche relâchée\n");
	else if (keycode == 65363) // Right arrow
		printf("Flèche droite relâchée\n");
	else if (keycode == 65362) // Up arrow
		printf("Flèche haut relâchée\n");
	else if (keycode == 65364) // Down arrow
		printf("Flèche bas relâchée\n");
	return (0);
}