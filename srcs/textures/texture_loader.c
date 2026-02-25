/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:15:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 12:05:33 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_texture_data(t_game *game, char *path,
		t_texture_load_buffers *tex)
{
	*tex->image_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, tex->width_ptr,
			tex->height_ptr);
	if (!*tex->image_ptr)
	{
		printf("Error loading texture: %s\n", path);
		return ;
	}
	*tex->buffer_ptr = mlx_get_data_addr(*tex->image_ptr, tex->bpp_ptr,
			tex->line_len_ptr, tex->endian_ptr);
}

void	load_texture_by_face(t_game *game, char *path, char face)
{
	t_texture_load_buffers	tex;

	ft_memset(&tex, 0, sizeof(tex));
	get_texture_ptrs(game, face, &tex);
	if (!tex.image_ptr)
		return ;
	load_texture_data(game, path, &tex);
	printf("  Loaded %s: %dx%d\n", path, *tex.width_ptr, *tex.height_ptr);
}
