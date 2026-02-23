/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:10:37 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 19:16:15 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	game->keys[keycode] = 1;
	printf("Keycode pressé: %d\n", keycode);
	if (keycode == 9 || keycode == 65307) // Escape
	{
		printf("Touche Échap pressée - Quitter\n");
		close_window(game);
	}
	else if (keycode == 119) // W
		printf("Touche W pressée - Avancer\n");
	else if (keycode == 97) // A
		printf("Touche A pressée - Gauche\n");
	else if (keycode == 115) // S
		printf("Touche S pressée - Reculer\n");
	else if (keycode == 100) // D
		printf("Touche D pressée - Droite\n");
	else if (keycode == 113) // Left arrow
		printf("Flèche gauche pressée - Rotation gauche\n");
	else if (keycode == 114) // Right arrow
		printf("Flèche droite pressée - Rotation droite\n");
	else if (keycode == 111) // Up arrow
		printf("Flèche haut pressée\n");
	else if (keycode == 116) // Down arrow
		printf("Flèche bas pressée\n");
	else if (keycode == 65480) // F11
		printf("Touche F11 pressée - Maximisation\n");
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
	else if (keycode == 113) // Left arrow
		printf("Flèche gauche relâchée\n");
	else if (keycode == 114) // Right arrow
		printf("Flèche droite relâchée\n");
	else if (keycode == 111) // Up arrow
		printf("Flèche haut relâchée\n");
	else if (keycode == 116) // Down arrow
		printf("Flèche bas relâchée\n");
	return (0);
}