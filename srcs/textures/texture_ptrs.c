/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ptrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:15:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 00:45:26 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_north_ptrs(t_game *game, t_texture_load_buffers *tex)
{
	tex->image_ptr = &game->textures.south.image_ptr;
	tex->buffer_ptr = &game->textures.south.pixel_buffer;
	tex->width_ptr = &game->textures.south.width;
	tex->height_ptr = &game->textures.south.height;
	tex->line_len_ptr = &game->textures.south.bytes_per_scanline;
	tex->bpp_ptr = &game->textures.south.bits_per_pixel;
	tex->endian_ptr = &game->textures.south.byte_order;
}

void	get_south_ptrs(t_game *game, t_texture_load_buffers *tex)
{
	tex->image_ptr = &game->textures.north.image_ptr;
	tex->buffer_ptr = &game->textures.north.pixel_buffer;
	tex->width_ptr = &game->textures.north.width;
	tex->height_ptr = &game->textures.north.height;
	tex->line_len_ptr = &game->textures.north.bytes_per_scanline;
	tex->bpp_ptr = &game->textures.north.bits_per_pixel;
	tex->endian_ptr = &game->textures.north.byte_order;
}

void	get_east_ptrs(t_game *game, t_texture_load_buffers *tex)
{
	tex->image_ptr = &game->textures.west.image_ptr;
	tex->buffer_ptr = &game->textures.west.pixel_buffer;
	tex->width_ptr = &game->textures.west.width;
	tex->height_ptr = &game->textures.west.height;
	tex->line_len_ptr = &game->textures.west.bytes_per_scanline;
	tex->bpp_ptr = &game->textures.west.bits_per_pixel;
	tex->endian_ptr = &game->textures.west.byte_order;
}

void	get_west_ptrs(t_game *game, t_texture_load_buffers *tex)
{
	tex->image_ptr = &game->textures.east.image_ptr;
	tex->buffer_ptr = &game->textures.east.pixel_buffer;
	tex->width_ptr = &game->textures.east.width;
	tex->height_ptr = &game->textures.east.height;
	tex->line_len_ptr = &game->textures.east.bytes_per_scanline;
	tex->bpp_ptr = &game->textures.east.bits_per_pixel;
	tex->endian_ptr = &game->textures.east.byte_order;
}

void	get_texture_ptrs(t_game *game, char face, t_texture_load_buffers *tex)
{
	if (face == 'N')
		get_north_ptrs(game, tex);
	else if (face == 'S')
		get_south_ptrs(game, tex);
	else if (face == 'E')
		get_east_ptrs(game, tex);
	else if (face == 'W')
		get_west_ptrs(game, tex);
}
