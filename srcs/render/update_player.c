/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:40:07 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 18:21:58 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	left_rotation_arrow_or_a_key(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_dir_x;
	old_plane_x = game->plane_x;
	if (game->keys[65361] || game->keys[97])
	{
		game->player_dir_x = game->player_dir_x * cos(-rot_speed)
			- game->player_dir_y * sin(-rot_speed);
		game->player_dir_y = old_dir_x * sin(-rot_speed) + game->player_dir_y
			* cos(-rot_speed);
		game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y
			* sin(-rot_speed);
		game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y
			* cos(-rot_speed);
	}
}

void	right_rotation_arrow_or_d_key(t_game *game, double rot_speed)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player_dir_x;
	old_plane_x = game->plane_x;
	if (game->keys[65363] || game->keys[100])
	{
		game->player_dir_x = game->player_dir_x * cos(rot_speed)
			- game->player_dir_y * sin(rot_speed);
		game->player_dir_y = old_dir_x * sin(rot_speed) + game->player_dir_y
			* cos(rot_speed);
		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y
			* sin(rot_speed);
		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y
			* cos(rot_speed);
	}
}

void	move_forward(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x + game->player_dir_x * move_speed;
	new_y = game->player_y + game->player_dir_y * move_speed;
	if (game->data->map[(int)new_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
	}
}

void	move_backward(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	new_x = game->player_x - game->player_dir_x * move_speed;
	new_y = game->player_y - game->player_dir_y * move_speed;
	if (game->data->map[(int)new_y][(int)new_x] != '1')
	{
		game->player_x = new_x;
		game->player_y = new_y;
	}
}

void	update_player(t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.005;
	rot_speed = 0.003;
	left_rotation_arrow_or_a_key(game, rot_speed);
	right_rotation_arrow_or_d_key(game, rot_speed);
	if (game->keys[65362] || game->keys[119])
		move_forward(game, move_speed);
	if (game->keys[65364] || game->keys[115])
		move_backward(game, move_speed);
}
