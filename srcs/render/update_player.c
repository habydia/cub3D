/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:40:07 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 15:40:43 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void	update_player(t_game *game) // MODIFIED BY LEO FOR UPDATE AND CORRECT ROTATION 
{
	double	move_speed;
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;
	double	new_x;
	double	new_y;

	(void)move_speed;
	(void)new_x;
	(void)new_y;
	move_speed = 0.005;
	rot_speed = 0.003;
	// Rotation gauche (fleche gauche ou A)
	if (game->keys[65361] || game->keys[97])
	{
		old_dir_x = game->player_dir_x;
		game->player_dir_x = game->player_dir_x * cos(-rot_speed)
			- game->player_dir_y * sin(-rot_speed);
		game->player_dir_y = old_dir_x * sin(-rot_speed) + game->player_dir_y
			* cos(-rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y
			* sin(-rot_speed);
		game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y
			* cos(-rot_speed);
	}
	// Rotation droite (fleche droite ou D)
	if (game->keys[65363] || game->keys[100])
	{
		old_dir_x = game->player_dir_x;
		game->player_dir_x = game->player_dir_x * cos(rot_speed)
			- game->player_dir_y * sin(rot_speed);
		game->player_dir_y = old_dir_x * sin(rot_speed) + game->player_dir_y
			* cos(rot_speed);
		old_plane_x = game->plane_x;
		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y
			* sin(rot_speed);
		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y
			* cos(rot_speed);
	}
	// Mouvement avant (flèche haut ou W)
	if (game->keys[65362] || game->keys[119]) // 65362 = flèche haut, 119 = 'w'
	{
		new_x = game->player_x + game->player_dir_x * move_speed;
		new_y = game->player_y + game->player_dir_y * move_speed;
		if (game->data->map[(int)new_y][(int)new_x] != '1')
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
	// Mouvement arrière (flèche bas ou S)
	if (game->keys[65364] || game->keys[115]) // 65364 = flèche bas, 115 = 's'
	{
		new_x = game->player_x - game->player_dir_x * move_speed;
		new_y = game->player_y - game->player_dir_y * move_speed;
		if (game->data->map[(int)new_y][(int)new_x] != '1')
		{
			game->player_x = new_x;
			game->player_y = new_y;
		}
	}
}