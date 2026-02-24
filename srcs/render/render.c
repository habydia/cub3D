/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:31:59 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 15:08:00 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	render(t_game *game)
{
	update_player(game);
	draw_floor_and_ceiling(game);
	raycasting(game);
	draw_minimap(game);
	mlx_put_image_to_window(game->mlx_ptr, game->mlx_window_ptr,
		game->mlx_image_ptr, 0, 0);
	return (0);
}
