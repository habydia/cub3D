/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:27:06 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 15:47:09 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// void	init_game(t_game *game, t_file_data *data)
// {
// 	game->data = data;
// 	game->mlx = NULL;
// 	game->win = NULL;
// 	game->img = NULL;
// 	game->img_data = NULL;
// 	/* Initialiser la position du joueur (conversion int vers double
// 		+ 0.5 pour centrer) */
// 	game->player_x = data->player_x + 0.5;
// 	game->player_y = data->player_y + 0.5;
// 	// Initialiser la direction selon player_dir
// 	if (data->player_dir == 'N')
// 	{
// 		game->player_dir_x = 0;
// 		game->player_dir_y = -1;
// 		game->plane_x = 0.66;
// 		game->plane_y = 0;
// 	}
// 	else if (data->player_dir == 'S')
// 	{
// 		game->player_dir_x = 0;
// 		game->player_dir_y = 1;
// 		game->plane_x = -0.66;
// 		game->plane_y = 0;
// 	}
// 	else if (data->player_dir == 'E')
// 	{
// 		game->player_dir_x = 1;
// 		game->player_dir_y = 0;
// 		game->plane_x = 0;
// 		game->plane_y = 0.66;
// 	}
// 	else if (data->player_dir == 'W')
// 	{
// 		game->player_dir_x = -1;
// 		game->player_dir_y = 0;
// 		game->plane_x = 0;
// 		game->plane_y = -0.66;
// 	}
// 	// Initialiser l'etat des touches
// 	memset(game->keys, 0, sizeof(game->keys));
// }

// int	key_press(int keycode, t_game *game)
// {
// 	game->keys[keycode] = 1;
// 	if (keycode == 119) // W
// 		printf("Touche W pressée - Avancer\n");
// 	else if (keycode == 97) // A
// 		printf("Touche A pressée - Gauche\n");
// 	else if (keycode == 115) // S
// 		printf("Touche S pressée - Reculer\n");
// 	else if (keycode == 100) // D
// 		printf("Touche D pressée - Droite\n");
// 	else if (keycode == 65361) // Left arrow
// 		printf("Flèche gauche pressée - Rotation gauche\n");
// 	else if (keycode == 65363) // Right arrow
// 		printf("Flèche droite pressée - Rotation droite\n");
// 	else if (keycode == 65362) // Up arrow
// 		printf("Flèche haut pressée\n");
// 	else if (keycode == 65364) // Down arrow
// 		printf("Flèche bas pressée\n");
// 	else if (keycode == 65480) // F11
// 		printf("Touche F11 pressée - Maximisation\n");
// 	else
// 		printf("Touche pressée: %d\n", keycode);
// 	return (0);
// }

// int	key_release(int keycode, t_game *game)
// {
// 	game->keys[keycode] = 0;
// 	if (keycode == 119) // W
// 		printf("Touche W relâchée\n");
// 	else if (keycode == 97) // A
// 		printf("Touche A relâchée\n");
// 	else if (keycode == 115) // S
// 		printf("Touche S relâchée\n");
// 	else if (keycode == 100) // D
// 		printf("Touche D relâchée\n");
// 	else if (keycode == 65361) // Left arrow
// 		printf("Flèche gauche relâchée\n");
// 	else if (keycode == 65363) // Right arrow
// 		printf("Flèche droite relâchée\n");
// 	else if (keycode == 65362) // Up arrow
// 		printf("Flèche haut relâchée\n");
// 	else if (keycode == 65364) // Down arrow
// 		printf("Flèche bas relâchée\n");
// 	return (0);
// }

// int	close_window(t_game *game)
// {
// 	printf("Fermeture de la fenêtre...\n");
// 	free_game(game);
// 	exit(0);
// 	return (0);
// }

// int	minimize_window(void *param)
// {
// 	(void)param;
// 	printf("Fenêtre réduite\n");
// 	return (0);
// }

// int	maximize_window(void *param)
// {
// 	(void)param;
// 	printf("Fenêtre agrandie\n");
// 	return (0);
// }

// void	update_player(t_game *game) // MODIFIED BY LEO FOR UPDATE AND CORRECT ROTATION 
// {
// 	double	move_speed;
// 	double	rot_speed;
// 	double	old_dir_x;
// 	double	old_plane_x;
// 	double	new_x;
// 	double	new_y;

// 	(void)move_speed;
// 	(void)new_x;
// 	(void)new_y;
// 	move_speed = 0.005;
// 	rot_speed = 0.003;
// 	// Rotation gauche (fleche gauche ou A)
// 	if (game->keys[65361] || game->keys[97])
// 	{
// 		old_dir_x = game->player_dir_x;
// 		game->player_dir_x = game->player_dir_x * cos(-rot_speed)
// 			- game->player_dir_y * sin(-rot_speed);
// 		game->player_dir_y = old_dir_x * sin(-rot_speed) + game->player_dir_y
// 			* cos(-rot_speed);
// 		old_plane_x = game->plane_x;
// 		game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y
// 			* sin(-rot_speed);
// 		game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y
// 			* cos(-rot_speed);
// 	}
// 	// Rotation droite (fleche droite ou D)
// 	if (game->keys[65363] || game->keys[100])
// 	{
// 		old_dir_x = game->player_dir_x;
// 		game->player_dir_x = game->player_dir_x * cos(rot_speed)
// 			- game->player_dir_y * sin(rot_speed);
// 		game->player_dir_y = old_dir_x * sin(rot_speed) + game->player_dir_y
// 			* cos(rot_speed);
// 		old_plane_x = game->plane_x;
// 		game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y
// 			* sin(rot_speed);
// 		game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y
// 			* cos(rot_speed);
// 	}
// 	// Mouvement avant (flèche haut ou W)
// 	if (game->keys[65362] || game->keys[119]) // 65362 = flèche haut, 119 = 'w'
// 	{
// 		new_x = game->player_x + game->player_dir_x * move_speed;
// 		new_y = game->player_y + game->player_dir_y * move_speed;
// 		if (game->data->map[(int)new_y][(int)new_x] != '1')
// 		{
// 			game->player_x = new_x;
// 			game->player_y = new_y;
// 		}
// 	}
// 	// Mouvement arrière (flèche bas ou S)
// 	if (game->keys[65364] || game->keys[115]) // 65364 = flèche bas, 115 = 's'
// 	{
// 		new_x = game->player_x - game->player_dir_x * move_speed;
// 		new_y = game->player_y - game->player_dir_y * move_speed;
// 		if (game->data->map[(int)new_y][(int)new_x] != '1')
// 		{
// 			game->player_x = new_x;
// 			game->player_y = new_y;
// 		}
// 	}
// }

// int	render(t_game *game) // MIDIFIED  BY LEO
// {
// 	update_player(game);
// 	draw_floor_and_ceiling(game);
// 	raycasting(game);
// 	draw_minimap(game);
// 	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
// 	return (0);
// }

void	draw_minimap(t_game *game) // ADDED BY LEO
{
	int x;
	int y;
	int position_x;
	int position_y;
	int map_scale_for_pixel;
	int color;

	map_scale_for_pixel = 10; // taille d’une case en pixels
	y = 0;

	while (y < game->data->map_height)
	{
		x = 0;
		while (x < game->data->map_width)
		{
			// Choix de la couleur
			if (game->data->map[y][x] == '1')
				color = 0xFFFFFF; // mur blanc
			else
				color = 0x000000; // vide noir

			// Dessiner la case a la position (x, y) avec scale
			position_y = 0;
			while (position_y < map_scale_for_pixel)
			{
				position_x = 0;
				while (position_x < map_scale_for_pixel)
				{
					put_pixel(game, x * map_scale_for_pixel + position_x, y * map_scale_for_pixel + position_y,
						color);
					position_x++;
				}
				position_y++;
			}
			x++;
		}
		y++;
	}

	// Dessiner le joueur (rouge)
	int player_px = (int)(game->player_x * map_scale_for_pixel);
	int player_py = (int)(game->player_y * map_scale_for_pixel);

	int i = -2;
	while (i <= 2)
	{
		int j = -2;
		while (j <= 2)
		{
			put_pixel(game, player_px + i, player_py + j, 0xFF0000);
			j++;
		}
		i++;
	}
}

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

int	main(int argc, char **argv)
{
	t_file_data data;
	memset(&data, 0, sizeof(t_file_data));

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	else
	{
		if (parsing_args(&data, argv) == -1)
		{
			printf("error\nparsing failed\n");
			return (1);
		}
		else
		{
			printf("Parsing successful! Opening window...\n");
			ft_open_window(&data);
			return (0);
		}
	}
	return (0);
}