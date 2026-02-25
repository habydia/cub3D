/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:10:37 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 16:57:00 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	handle_special_key(int keycode, t_game *game)
{
	if (keycode == 65480)
		printf("F11 key pressed - Maximize\n");
	else if (keycode == 9 || keycode == 65307)
	{
		printf("Escape key pressed - Quit\n");
		close_window(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	game->keys[keycode] = 1;
	printf("Key code pressed: %d\n", keycode);
	handle_movement_key(keycode);
	handle_arrow_key(keycode);
	handle_special_key(keycode, game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	game->keys[keycode] = 0;
	handle_movement_release(keycode);
	handle_arrow_release(keycode);
	return (0);
}
