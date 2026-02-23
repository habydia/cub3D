/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:48:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 18:26:04 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	load_one_texture(void *mlx, char *path, void **img, char **data,
		int *w, int *h, int *line_len, int *bpp, int *endian)
{
	*img = mlx_xpm_file_to_image(mlx, path, w, h);
	if (!*img)
	{
		printf("Error loading texture: %s\n", path);
		return ;
	}
	*data = mlx_get_data_addr(*img, bpp, line_len, endian);
	printf("  Loaded %s: %dx%d\n", path, *w, *h);
}

void	load_textures(t_game *game, t_file_data *file_data)
{
	char	*path_n;
	char	*path_s;
	char	*path_e;
	char	*path_w;

	path_n = (file_data
			&& file_data->north_texture) ? file_data->north_texture : "textures/N.xpm";
	path_s = (file_data
			&& file_data->south_texture) ? file_data->south_texture : "textures/S.xpm";
	path_e = (file_data
			&& file_data->east_texture) ? file_data->east_texture : "textures/E.xpm";
	path_w = (file_data
			&& file_data->west_texture) ? file_data->west_texture : "textures/W.xpm";
	load_one_texture(game->mlx, path_n, &game->textures.north_img,
		&game->textures.north_data, &game->textures.north_width,
		&game->textures.north_height, &game->textures.north_line_len,
		&game->textures.north_bpp, &game->textures.north_endian);
	load_one_texture(game->mlx, path_s, &game->textures.south_img,
		&game->textures.south_data, &game->textures.south_width,
		&game->textures.south_height, &game->textures.south_line_len,
		&game->textures.south_bpp, &game->textures.south_endian);
	load_one_texture(game->mlx, path_e, &game->textures.east_img,
		&game->textures.east_data, &game->textures.east_width,
		&game->textures.east_height, &game->textures.east_line_len,
		&game->textures.east_bpp, &game->textures.east_endian);
	load_one_texture(game->mlx, path_w, &game->textures.west_img,
		&game->textures.west_data, &game->textures.west_width,
		&game->textures.west_height, &game->textures.west_line_len,
		&game->textures.west_bpp, &game->textures.west_endian);
	printf("✓ All textures loaded\n");
}

void	free_textures(t_game *game)
{
	if (game->textures.north_img)
		mlx_destroy_image(game->mlx, game->textures.north_img);
	if (game->textures.south_img)
		mlx_destroy_image(game->mlx, game->textures.south_img);
	if (game->textures.east_img)
		mlx_destroy_image(game->mlx, game->textures.east_img);
	if (game->textures.west_img)
		mlx_destroy_image(game->mlx, game->textures.west_img);
}