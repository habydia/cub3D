/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_game_key.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:35:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 16:24:36 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_data_map(t_game *game, t_file_data *data)
{
	game->data = data;
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
	game->img_data = NULL;
}

void	init_key_press_state(t_game *game)
{
	ft_memset(game->keys, 0, sizeof(game->keys));
}

void	init_game(t_game *game, t_file_data *data)
{
	init_data_map(game, data);
	init_player_position(game, data);
	init_player_direction(game, data);
	init_key_press_state(game);
}
