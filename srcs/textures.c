/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:15:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 17:47:57 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	load_one_texture(void *mlx, char *path, void **img, char **data,
		int *w, int *h, int *line_len, int *bpp, int *endian)
{
	*img = mlx_xpm_file_to_image(mlx, path, w, h);
	if (!*img)
	{
		printf("Error\nFailed to load texture: %s\n", path);
		exit(1);
	}
	*data = mlx_get_data_addr(*img, bpp, line_len, endian);
	if (!*data)
	{
		printf("Error: Failed to get data address for %s\n", path);
		exit(1);
	}
	printf("  Loaded %s: %dx%d, bpp=%d, line_len=%d\n", path, *w, *h, *bpp,
		*line_len);
	if (!*data)
		printf("  WARNING: Data pointer is NULL for %s\n", path);
	else
		printf("  Data ptr OK: %p\n", *data);
}

void	load_textures(t_game *game, t_file_data *data)
{
	char	*path_n;
	char	*path_s;
	char	*path_e;
	char	*path_w;

	// Use paths from parsing if available, otherwise use defaults
	path_n = (data
			&& data->north_texture) ? data->north_texture : "textures/N.xpm";
	path_s = (data
			&& data->south_texture) ? data->south_texture : "textures/S.xpm";
	path_e = (data
			&& data->east_texture) ? data->east_texture : "textures/E.xpm";
	path_w = (data
			&& data->west_texture) ? data->west_texture : "textures/W.xpm";
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
	printf("✓ Textures loaded successfully\n");
	printf("  N: %s | S: %s | E: %s | W: %s\n", path_n, path_s, path_e, path_w);
}

void	free_textures(t_game *game)
{
	if (game->textures.north_img)
		mlx_destroy_image(game->mlx, game->textures.north_img);
	if (game->textures.south_img)
		mlx_destroy_image(game->mlx, game->textures.south_img);
	if (game->textures.west_img)
		mlx_destroy_image(game->mlx, game->textures.west_img);
	if (game->textures.east_img)
		mlx_destroy_image(game->mlx, game->textures.east_img);
}

void	free_game(t_game *game)
{
	free_textures(game);
	if (game->data)
	{
		if (game->data->map)
		{
			for (int i = 0; i < game->data->map_height; i++)
				free(game->data->map[i]);
			free(game->data->map);
		}
		free(game->data->north_texture);
		free(game->data->south_texture);
		free(game->data->west_texture);
		free(game->data->east_texture);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}