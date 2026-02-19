/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:58:55 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 16:24:08 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_mlx_and_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("Failed to initialize MLX\n"), 1);
	game->win = mlx_new_window(game->mlx, 800, 600, "Cub3D");
	if (!game->win)
		return (printf("Failed to create window\n"), 1);
	game->img = mlx_new_image(game->mlx, 800, 600);
	if (!game->img)
		return (printf("Failed to create image\n"), 1);
	game->img_data = mlx_get_data_addr(game->img, &game->bpp, &game->line_len,
			&game->endian);
	return (0);
}

void	setup_hooks(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_hook(game->win, 15, 1L << 16, minimize_window, NULL);
	mlx_hook(game->win, 22, 1L << 18, maximize_window, NULL);
	mlx_loop_hook(game->mlx, (int (*)(void *))render, game);
}

int	ft_open_window(t_file_data *data)
{
	t_game	game;

	init_game(&game, data);
	if (init_mlx_and_window(&game))
		return (1);
	load_textures(&game, data);
	setup_hooks(&game);
	mlx_loop(game.mlx);
	return (0);
}
