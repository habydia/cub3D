/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 01:07:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 02:03:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	fill_n_texture(t_game *game, t_texture_data *info)
{
	info->texture_pixel_buffer = game->textures.north_data;
	info->texture_width = game->textures.north_width;
	info->texture_height = game->textures.north_height;
	info->texture_bytes_per_scanline = game->textures.north_line_len;
}

static void	fill_s_texture(t_game *game, t_texture_data *info)
{
	info->texture_pixel_buffer = game->textures.south_data;
	info->texture_width = game->textures.south_width;
	info->texture_height = game->textures.south_height;
	info->texture_bytes_per_scanline = game->textures.south_line_len;
}

static void	fill_e_texture(t_game *game, t_texture_data *info)
{
	info->texture_pixel_buffer = game->textures.east_data;
	info->texture_width = game->textures.east_width;
	info->texture_height = game->textures.east_height;
	info->texture_bytes_per_scanline = game->textures.east_line_len;
}

static void	fill_w_texture(t_game *game, t_texture_data *info)
{
	info->texture_pixel_buffer = game->textures.west_data;
	info->texture_width = game->textures.west_width;
	info->texture_height = game->textures.west_height;
	info->texture_bytes_per_scanline = game->textures.west_line_len;
}

void	get_texture_data(t_game *game, char face, t_texture_data *info)
{
	if (face == 'N')
		fill_n_texture(game, info);
	else if (face == 'S')
		fill_s_texture(game, info);
	else if (face == 'E')
		fill_e_texture(game, info);
	else if (face == 'W')
		fill_w_texture(game, info);
}
