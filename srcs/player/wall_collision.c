/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:55:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 19:04:43 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall_collision(t_game *game, double new_x, double new_y)
{
	return (game->data->map[(int)new_y][(int)new_x] == '1');
}
