/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sync_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:31:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 17:10:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	sync_north_texture_fields(t_game *game)
{
	game->textures.north_img = game->textures.north.image_ptr;
	game->textures.north_data = game->textures.north.pixel_buffer;
	game->textures.north_width = game->textures.north.width;
	game->textures.north_height = game->textures.north.height;
	game->textures.north_bpp = game->textures.north.bits_per_pixel;
	game->textures.north_line_len = game->textures.north.bytes_per_scanline;
	game->textures.north_endian = game->textures.north.byte_order;
}

static void	sync_south_texture_fields(t_game *game)
{
	game->textures.south_img = game->textures.south.image_ptr;
	game->textures.south_data = game->textures.south.pixel_buffer;
	game->textures.south_width = game->textures.south.width;
	game->textures.south_height = game->textures.south.height;
	game->textures.south_bpp = game->textures.south.bits_per_pixel;
	game->textures.south_line_len = game->textures.south.bytes_per_scanline;
	game->textures.south_endian = game->textures.south.byte_order;
}

static void	sync_east_texture_fields(t_game *game)
{
	game->textures.east_img = game->textures.east.image_ptr;
	game->textures.east_data = game->textures.east.pixel_buffer;
	game->textures.east_width = game->textures.east.width;
	game->textures.east_height = game->textures.east.height;
	game->textures.east_bpp = game->textures.east.bits_per_pixel;
	game->textures.east_line_len = game->textures.east.bytes_per_scanline;
	game->textures.east_endian = game->textures.east.byte_order;
}

static void	sync_west_texture_fields(t_game *game)
{
	game->textures.west_img = game->textures.west.image_ptr;
	game->textures.west_data = game->textures.west.pixel_buffer;
	game->textures.west_width = game->textures.west.width;
	game->textures.west_height = game->textures.west.height;
	game->textures.west_bpp = game->textures.west.bits_per_pixel;
	game->textures.west_line_len = game->textures.west.bytes_per_scanline;
	game->textures.west_endian = game->textures.west.byte_order;
}

void	sync_all_texture_fields(t_game *game)
{
	sync_north_texture_fields(game);
	sync_south_texture_fields(game);
	sync_east_texture_fields(game);
	sync_west_texture_fields(game);
}
