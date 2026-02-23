/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:48:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 17:18:28 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	load_textures(t_game *game, t_file_data *data)
{
	int	bpp;
	int	endian;

	game->textures.north_img = mlx_xpm_file_to_image(game->mlx,
			"textures/N_64x64.xpm", &game->textures.width,
			&game->textures.height);
	if (!game->textures.north_img)
	{
		printf("Error: Failed to load North texture\n");
		return ;
	}
	game->textures.north_data = mlx_get_data_addr(game->textures.north_img,
			&game->textures.north_bpp, &game->textures.north_line_len,
			&game->textures.north_endian);
	game->textures.south_img = mlx_xpm_file_to_image(game->mlx,
			"textures/S_64x64.xpm", &game->textures.width,
			&game->textures.height);
	if (!game->textures.south_img)
	{
		printf("Error: Failed to load South texture\n");
		return ;
	}
	game->textures.south_data = mlx_get_data_addr(game->textures.south_img,
			&game->textures.south_bpp, &game->textures.south_line_len,
			&game->textures.south_endian);
	game->textures.east_img = mlx_xpm_file_to_image(game->mlx,
			"textures/E_64x64.xpm", &game->textures.width,
			&game->textures.height);
	if (!game->textures.east_img)
	{
		printf("Error: Failed to load East texture\n");
		return ;
	}
	game->textures.east_data = mlx_get_data_addr(game->textures.east_img,
			&game->textures.east_bpp, &game->textures.east_line_len,
			&game->textures.east_endian);
	game->textures.west_img = mlx_xpm_file_to_image(game->mlx,
			"textures/W_64x64.xpm", &game->textures.width,
			&game->textures.height);
	if (!game->textures.west_img)
	{
		printf("Error: Failed to load West texture\n");
		return ;
	}
	game->textures.west_data = mlx_get_data_addr(game->textures.west_img,
			&game->textures.west_bpp, &game->textures.west_line_len,
			&game->textures.west_endian);
	printf("Textures loaded: N=%p, S=%p, E=%p, W=%p\n",
		game->textures.north_data, game->textures.south_data,
		game->textures.east_data, game->textures.west_data);
}

void	free_textures(t_game *game)
{
	if (game->textures.north_img)
		mlx_destroy_image(game->mlx, game->textures.north_img);
	// Free toutes les images et data
}

void	free_game(t_game *game)
{
	free_textures(game);
	free_map(game->data->map, game->data->map_height);
	mlx_destroy_window(game->mlx, game->win);
	// mlx_destroy_display(game->mlx); sur Linux
}