/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:59:18 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player_position(t_game *game, t_file_data *data)
{
	game->player_x = data->player.player_x + 0.5;
	game->player_y = data->player.player_y + 0.5;
}

void	init_player_direction_north_south(t_game *game, t_file_data *data)
{
	if (data->player.player_dir == 'N')
	{
		game->player_dir_x = 0;
		game->player_dir_y = -1;
		game->plane_x = 0.66;
		game->plane_y = 0;
	}
	else if (data->player.player_dir == 'S')
	{
		game->player_dir_x = 0;
		game->player_dir_y = 1;
		game->plane_x = -0.66;
		game->plane_y = 0;
	}
}

void	init_player_direction_east_west(t_game *game, t_file_data *data)
{
	if (data->player.player_dir == 'E')
	{
		game->player_dir_x = 1;
		game->player_dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
	}
	else if (data->player.player_dir == 'W')
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
