/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:58:55 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 15:59:27 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_open_window(t_file_data *data)
{
	t_game	game;

	init_game(&game, data);
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		printf("Failed to initialize MLX\n");
		return (1);
	}
	game.win = mlx_new_window(game.mlx, 800, 600, "Cub3D");
	if (!game.win)
	{
		printf("Failed to create window\n");
		return (1);
	}
	// Creer l'image pour le double buffering
	game.img = mlx_new_image(game.mlx, 800, 600);
	if (!game.img)
	{
		printf("Failed to create image\n");
		return (1);
	}
	game.img_data = mlx_get_data_addr(game.img, &game.bpp, &game.line_len,
			&game.endian);
	// Charger les textures
	load_textures(&game, data);
	// Configurer les hooks pour les événements
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);   // Touche pressée
	mlx_hook(game.win, 3, 1L << 1, key_release, &game); // Touche relâchée
	mlx_hook(game.win, 17, 0L, close_window, &game);
	// Fermeture fenêtre (croix)
	mlx_hook(game.win, 15, 1L << 16, minimize_window, NULL); // Réduction
	mlx_hook(game.win, 22, 1L << 18, maximize_window, NULL);
	// Redimensionnement
	// Configurer la boucle de rendu
	mlx_loop_hook(game.mlx, (int (*)(void *))render, &game);
	mlx_loop(game.mlx);
	return (0);
}

