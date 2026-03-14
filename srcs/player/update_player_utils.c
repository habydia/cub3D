/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 00:20:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 00:34:34 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left_rotation_arrow(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_camera_plane_x;

	old_dir_x = game->player_vector_direction_x;
	old_camera_plane_x = game->camera_plane_x;
	if (game->keys[65361])
	{
		game->player_vector_direction_x = game->player_vector_direction_x
			* cos(-rot_speed) - game->player_vector_direction_y
			* sin(-rot_speed);
		game->player_vector_direction_y = old_dir_x * sin(-rot_speed)
			+ game->player_vector_direction_y * cos(-rot_speed);
		game->camera_plane_x = game->camera_plane_x * cos(-rot_speed)
			- game->camera_plane_y * sin(-rot_speed);
		game->camera_plane_y = old_camera_plane_x * sin(-rot_speed)
			+ game->camera_plane_y * cos(-rot_speed);
	}
}

void	right_rotation_arrow(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_camera_plane_x;

	old_dir_x = game->player_vector_direction_x;
	old_camera_plane_x = game->camera_plane_x;
	if (game->keys[65363])
	{
		game->player_vector_direction_x = game->player_vector_direction_x
			* cos(rot_speed) - game->player_vector_direction_y * sin(rot_speed);
		game->player_vector_direction_y = old_dir_x * sin(rot_speed)
			+ game->player_vector_direction_y * cos(rot_speed);
		game->camera_plane_x = game->camera_plane_x * cos(rot_speed)
			- game->camera_plane_y * sin(rot_speed);
		game->camera_plane_y = old_camera_plane_x * sin(rot_speed)
			+ game->camera_plane_y * cos(rot_speed);
	}
}
