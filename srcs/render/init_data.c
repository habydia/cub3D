/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:35:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 20:37:26 by lebroue          ###   ########.fr       */
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

void	init_player_position(t_game *game, t_file_data *data)
{
	game->player_x = data->player_x + 0.5;
	game->player_y = data->player_y + 0.5;
}
void	init_player_direction_north_south(t_game *game, t_file_data *data)
{
	if (data->player_dir == 'N')
	{
		game->player_dir_x = 0;
		game->player_dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (data->player_dir == 'S')
	{
		game->player_dir_x = 0;
		game->player_dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
}

void	init_player_direction_east_west(t_game *game, t_file_data *data)
{
	if (data->player_dir == 'E')
	{
		game->player_dir_x = 1;
		game->player_dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (data->player_dir == 'W')
	{
		game->player_dir_x = -1;
		game->player_dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
	}
}

void	init_player_direction(t_game *game, t_file_data *data)
{
	init_player_direction_north_south(game, data);
	init_player_direction_north_south(game, data);
}

void	init_key_press_state(t_game *game)
{
	memset(game->keys, 0, sizeof(game->keys));
}
void	init_game(t_game *game, t_file_data *data)
{
	init_data_map(game, data);
	init_player_position(game, data);
	init_player_direction(game, data);
	init_key_press_state(game);
}
