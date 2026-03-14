/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:40:07 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 00:51:47 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward_w_or_up_arrow(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	if (game->keys[65362] || game->keys[119])
	{
		new_x = game->player_pos_x + game->player_vector_direction_x
			* move_speed;
		new_y = game->player_pos_y + game->player_vector_direction_y
			* move_speed;
		if (!is_wall_collision(game, new_x, new_y))
		{
			game->player_pos_x = new_x;
			game->player_pos_y = new_y;
		}
	}
}

void	move_backward_s_or_down_arrow(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	if (game->keys[65364] || game->keys[115])
	{
		new_x = game->player_pos_x - game->player_vector_direction_x
			* move_speed;
		new_y = game->player_pos_y - game->player_vector_direction_y
			* move_speed;
		if (!is_wall_collision(game, new_x, new_y))
		{
			game->player_pos_x = new_x;
			game->player_pos_y = new_y;
		}
	}
}

void	move_left_a_key(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	if (game->keys[97])
	{
		new_x = game->player_pos_x - game->camera_plane_x * move_speed;
		new_y = game->player_pos_y - game->camera_plane_y * move_speed;
		if (!is_wall_collision(game, new_x, new_y))
		{
			game->player_pos_x = new_x;
			game->player_pos_y = new_y;
		}
	}
}

void	move_right_d_key(t_game *game, double move_speed)
{
	double	new_x;
	double	new_y;

	if (game->keys[100])
	{
		new_x = game->player_pos_x + game->camera_plane_x * move_speed;
		new_y = game->player_pos_y + game->camera_plane_y * move_speed;
		if (!is_wall_collision(game, new_x, new_y))
		{
			game->player_pos_x = new_x;
			game->player_pos_y = new_y;
		}
	}
}

void	update_player(t_game *game)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.007;
	rot_speed = 0.003;
	move_forward_w_or_up_arrow(game, move_speed);
	move_backward_s_or_down_arrow(game, move_speed);
	move_left_a_key(game, move_speed);
	move_right_d_key(game, move_speed);
	left_rotation_arrow(game, rot_speed);
	right_rotation_arrow(game, rot_speed);
}
