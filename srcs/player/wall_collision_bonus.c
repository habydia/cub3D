/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 19:30:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 14:55:58 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall_collision(t_game *game, double new_x, double new_y)
{
	int	x;
	int	y;

	x = (int)new_x;
	y = (int)new_y;
	if (x < 0 || x >= game->data->map_width || y < 0
		|| y >= game->data->map_height)
		return (1);
	return (game->data->map[y][x] == '1');
}
