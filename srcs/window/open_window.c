/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:58:55 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 15:11:52 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_mlx_and_window(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (printf("Failed to initialize MLX\n"), 1);
	game->mlx_window_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "Cub3D");
	if (!game->mlx_window_ptr)
		return (printf("Failed to create window\n"), 1);
	game->mlx_image_ptr = mlx_new_image(game->mlx_ptr, 800, 600);
	if (!game->mlx_image_ptr)
		return (printf("Failed to create image\n"), 1);
	game->pixel_buffer = mlx_get_data_addr(game->mlx_image_ptr,
			&game->bits_for_one_pixel, &game->bytes_per_scanline,
			&game->byte_order);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->mlx_window_ptr, 2, 1L << 0, key_press, game);
	mlx_hook(game->mlx_window_ptr, 3, 1L << 1, key_release, game);
	mlx_hook(game->mlx_window_ptr, 17, 0L, close_window, game);
	mlx_hook(game->mlx_window_ptr, 15, 1L << 16, minimize_window, NULL);
	mlx_hook(game->mlx_window_ptr, 22, 1L << 18, maximize_window, NULL);
	mlx_loop_hook(game->mlx_ptr, (int (*)(void *))render, game);
}

int	ft_open_window(t_file_data *data)
{
	t_game	game;

	init_game(&game, data);
	if (init_mlx_and_window(&game))
		return (1);
	load_textures(&game, data);
	setup_hooks(&game);
	mlx_loop(game.mlx_ptr);
	return (0);
}
