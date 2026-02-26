/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:43:21 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 16:19:06 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	raycasting(t_game *game)
{
	int		x;
	int		w;
	int		h;
	t_ray	ray;

	w = 800;
	h = 600;
	x = 0;
	while (x < w)
	{
		init_ray(game, &ray, x, w);
		calculate_step(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);
		draw_wall_vertical_line(game, &ray, x, h);
		x++;
	}
}
