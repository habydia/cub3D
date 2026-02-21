/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:15:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// Calculs pour déterminer quelle partie d'une texture afficher sur un mur (basés sur la hauteur de la ligne et la position relative).
void load_textures(t_game *game, t_file_data *data)
{
    // Chargement de la texture NORTH
    game->textures.north_img = mlx_xpm_file_to_image(game->mlx, data->textures.north_texture,
                                                   &game->textures.width, &game->textures.height);
    if (!game->textures.north_img)
    {
        printf("Error\nFailed to load north texture: %s\n", data->textures.north_texture);
        exit(1);
    }
    game->textures.north_data = mlx_get_data_addr(game->textures.north_img,
                                                &game->textures.width, &game->textures.height, &game->textures.width);

    // Chargement de la texture SOUTH
    game->textures.south_img = mlx_xpm_file_to_image(game->mlx, data->textures.south_texture,
                                                   &game->textures.width, &game->textures.height);
    if (!game->textures.south_img)
    {
        printf("Error\nFailed to load south texture: %s\n", data->textures.south_texture);
        exit(1);
    }
    game->textures.south_data = mlx_get_data_addr(game->textures.south_img,
                                                &game->textures.width, &game->textures.height, &game->textures.width);

    // Chargement de la texture WEST
    game->textures.west_img = mlx_xpm_file_to_image(game->mlx, data->textures.west_texture,
                                                  &game->textures.width, &game->textures.height);
    if (!game->textures.west_img)
    {
        printf("Error\nFailed to load west texture: %s\n", data->textures.west_texture);
        exit(1);
    }
    game->textures.west_data = mlx_get_data_addr(game->textures.west_img,
                                               &game->textures.width, &game->textures.height, &game->textures.width);

    // Chargement de la texture EAST
    game->textures.east_img = mlx_xpm_file_to_image(game->mlx, data->textures.east_texture,
                                                  &game->textures.width, &game->textures.height);
    if (!game->textures.east_img)
    {
        printf("Error\nFailed to load east texture: %s\n", data->textures.east_texture);
        exit(1);
    }
    game->textures.east_data = mlx_get_data_addr(game->textures.east_img,
                                               &game->textures.width, &game->textures.height, &game->textures.width);

    printf("Textures loaded successfully\n");
}

void free_textures(t_game *game)
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

void free_game(t_game *game)
{
    free_textures(game);
    if (game->data)
    {
        // Free map
        if (game->data->map_data.map)
        {
            int i = 0;
            while (i < game->data->map_data.map_height)
            {
                free(game->data->map_data.map[i]);
                i++;
            }
            free(game->data->map_data.map);
        }
        // Free texture paths
        free(game->data->textures.north_texture);
        free(game->data->textures.south_texture);
        free(game->data->textures.west_texture);
        free(game->data->textures.east_texture);
    }
    if (game->win)
        mlx_destroy_window(game->mlx, game->win);
    if (game->mlx)
        mlx_destroy_display(game->mlx);
}