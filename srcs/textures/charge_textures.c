/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:48:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 11:06:40 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture_path(t_file_data *data, char face)
{
	if (face == 'N' && data && data->north_texture)
		return (data->north_texture);
	else if (face == 'S' && data && data->south_texture)
		return (data->south_texture);
	else if (face == 'E' && data && data->east_texture)
		return (data->east_texture);
	else if (face == 'W' && data && data->west_texture)
		return (data->west_texture);
	return (NULL);
}

static void	load_all_textures(t_game *game, t_file_data *data)
{
	char	*path;

	path = get_texture_path(data, 'N');
	if (path)
		load_texture_by_face(game, path, 'N');
	path = get_texture_path(data, 'S');
	if (path)
		load_texture_by_face(game, path, 'S');
	path = get_texture_path(data, 'E');
	if (path)
		load_texture_by_face(game, path, 'E');
	path = get_texture_path(data, 'W');
	if (path)
		load_texture_by_face(game, path, 'W');
}

void	load_textures(t_game *game, t_file_data *file_data)
{
	load_all_textures(game, file_data);
	// Synchronize legacy fields with new t_wall_texture fields
	game->textures.north_img = game->textures.north.image_ptr;
	game->textures.north_data = game->textures.north.pixel_buffer;
	game->textures.north_width = game->textures.north.width;
	game->textures.north_height = game->textures.north.height;
	game->textures.north_bpp = game->textures.north.bits_per_pixel;
	game->textures.north_line_len = game->textures.north.bytes_per_scanline;
	game->textures.north_endian = game->textures.north.byte_order;
	game->textures.south_img = game->textures.south.image_ptr;
	game->textures.south_data = game->textures.south.pixel_buffer;
	game->textures.south_width = game->textures.south.width;
	game->textures.south_height = game->textures.south.height;
	game->textures.south_bpp = game->textures.south.bits_per_pixel;
	game->textures.south_line_len = game->textures.south.bytes_per_scanline;
	game->textures.south_endian = game->textures.south.byte_order;
	game->textures.east_img = game->textures.east.image_ptr;
	game->textures.east_data = game->textures.east.pixel_buffer;
	game->textures.east_width = game->textures.east.width;
	game->textures.east_height = game->textures.east.height;
	game->textures.east_bpp = game->textures.east.bits_per_pixel;
	game->textures.east_line_len = game->textures.east.bytes_per_scanline;
	game->textures.east_endian = game->textures.east.byte_order;
	game->textures.west_img = game->textures.west.image_ptr;
	game->textures.west_data = game->textures.west.pixel_buffer;
	game->textures.west_width = game->textures.west.width;
	game->textures.west_height = game->textures.west.height;
	game->textures.west_bpp = game->textures.west.bits_per_pixel;
	game->textures.west_line_len = game->textures.west.bytes_per_scanline;
	game->textures.west_endian = game->textures.west.byte_order;
	printf("All textures loaded\n");
}

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
