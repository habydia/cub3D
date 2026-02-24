/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 23:15:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 15:07:49 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_texture_data(t_game *game, char *path, t_textures_data *tex)
{
	*tex->img = mlx_xpm_file_to_image(game->mlx_ptr, path, tex->w, tex->h);
	if (!*tex->img)
	{
		printf("Error loading texture: %s\n", path);
		return ;
	}
	*tex->data = mlx_get_data_addr(*tex->img, tex->bpp, tex->line_len,
			tex->endian);
}

void	load_texture_by_face(t_game *game, char *path, char face)
{
	t_textures_data	tex;

	ft_memset(&tex, 0, sizeof(tex));
	get_texture_ptrs(game, face, &tex);
	if (!tex.img)
		return ;
	load_texture_data(game, path, &tex);
	printf("  Loaded %s: %dx%d\n", path, *tex.w, *tex.h);
}
