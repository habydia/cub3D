/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_ptrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:15:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 00:13:34 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_north_ptrs(t_game *game, t_textures_data *tex)
{
	tex->img = &game->textures.north_img;
	tex->data = &game->textures.north_data;
	tex->w = &game->textures.north_width;
	tex->h = &game->textures.north_height;
	tex->line_len = &game->textures.north_line_len;
	tex->bpp = &game->textures.north_bpp;
	tex->endian = &game->textures.north_endian;
}

void	get_south_ptrs(t_game *game, t_textures_data *tex)
{
	tex->img = &game->textures.south_img;
	tex->data = &game->textures.south_data;
	tex->w = &game->textures.south_width;
	tex->h = &game->textures.south_height;
	tex->line_len = &game->textures.south_line_len;
	tex->bpp = &game->textures.south_bpp;
	tex->endian = &game->textures.south_endian;
}

void	get_east_ptrs(t_game *game, t_textures_data *tex)
{
	tex->img = &game->textures.east_img;
	tex->data = &game->textures.east_data;
	tex->w = &game->textures.east_width;
	tex->h = &game->textures.east_height;
	tex->line_len = &game->textures.east_line_len;
	tex->bpp = &game->textures.east_bpp;
	tex->endian = &game->textures.east_endian;
}

void	get_west_ptrs(t_game *game, t_textures_data *tex)
{
	tex->img = &game->textures.west_img;
	tex->data = &game->textures.west_data;
	tex->w = &game->textures.west_width;
	tex->h = &game->textures.west_height;
	tex->line_len = &game->textures.west_line_len;
	tex->bpp = &game->textures.west_bpp;
	tex->endian = &game->textures.west_endian;
}

void	get_texture_ptrs(t_game *game, char face, t_textures_data *tex)
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
