/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:30:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 17:08:41 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_textures(t_game *game)
{
	if (game->textures.north_img)
		mlx_destroy_image(game->mlx_ptr, game->textures.north_img);
	if (game->textures.south_img)
		mlx_destroy_image(game->mlx_ptr, game->textures.south_img);
	if (game->textures.east_img)
		mlx_destroy_image(game->mlx_ptr, game->textures.east_img);
	if (game->textures.west_img)
		mlx_destroy_image(game->mlx_ptr, game->textures.west_img);
}
