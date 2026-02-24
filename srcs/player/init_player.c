/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:59:18 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 16:54:05 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player_position(t_game *game, t_file_data *data)
{
	game->player_pos_x = data->player_pos_x + 0.5;
	game->player_pos_y = data->player_pos_y + 0.5;
}

void	init_player_direction_north_south(t_game *game, t_file_data *data)
{
	if (data->player_dir == 'N')
	{
		game->player_vector_direction_x = 0;
		game->player_vector_direction_y = -1;
		game->camera_plane_x = 0.66;
		game->camera_plane_y = 0;
	}
	else if (data->player_dir == 'S')
	{
		game->player_vector_direction_x = 0;
		game->player_vector_direction_y = 1;
		game->camera_plane_x = -0.66;
		game->camera_plane_y = 0;
	}
}

void	init_player_direction_east_west(t_game *game, t_file_data *data)
{
	if (data->player_dir == 'E')
	{
		game->player_vector_direction_x = 1;
		game->player_vector_direction_y = 0;
		game->camera_plane_x = 0;
		game->camera_plane_y = 0.66;
	}
	else if (data->player_dir == 'W')
	{
		game->player_vector_direction_x = -1;
		game->player_vector_direction_y = 0;
		game->camera_plane_x = 0;
		game->camera_plane_y = -0.66;
	}
}

void	init_player_direction(t_game *game, t_file_data *data)
{
	init_player_direction_north_south(game, data);
	init_player_direction_east_west(game, data);
}
