/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:47:42 by hadia             #+#    #+#             */
/*   Updated: 2026/03/14 14:52:49 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	handle_floor_ceilling_error(t_file_data *data)
{
	if (!data->floor_set)
	{
		printf("Error\nFloor color (F) is missing\n");
		return (-1);
	}
	if (!data->ceiling_set)
	{
		printf("Error\nCeiling color (C) is missing\n");
		return (-1);
	}
	if (data->map_height == 0)
	{
		printf("Error\nMap is missing\n");
		return (-1);
	}
	return (0);
}

int	parsing_args(t_file_data *data, char **argv)
{
	char	*filename;
	int		len;

	filename = argv[1];
	len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
	{
		printf("Error\nFile must have .cub extension\n");
		return (-1);
	}
	if (read_file(argv[1], data) == -1)
		return (-1);
	if (!data->north_set || !data->south_set || !data->west_set
		|| !data->east_set)
	{
		printf("Error\nAll textures (NO, SO, WE, EA) are required\n");
		return (-1);
	}
	if (handle_floor_ceilling_error(data) == -1)
		return (-1);
	return (0);
}

void	free_file_data(t_file_data *data)
{
	if (!data)
		return ;
	free(data->north_texture);
	free(data->south_texture);
	free(data->west_texture);
	free(data->east_texture);
	if (data->map)
	{
		for (int i = 0; i < data->map_height; i++)
			free(data->map[i]);
		free(data->map);
	}
	if (data->map_lines)
		ft_lstclear(&data->map_lines, free);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_textures(game);
	free_file_data(game->data);
	if (game->mlx_image_ptr && game->mlx_ptr)
		mlx_destroy_image(game->mlx_ptr, game->mlx_image_ptr);
	if (game->mlx_ptr && game->mlx_window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->mlx_window_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
}
