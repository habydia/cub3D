/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:47:42 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Checks if floor and ceiling colors are set and if a map exists.
 * @param data Pointer to the file data structure.
 * @return 0 if all required elements are present, -1 otherwise.
 */
static int	handle_floor_ceilling_error(t_file_data *data)
{
	if (!data->colors.floor_set)
	{
		printf("Error\nFloor color (F) is missing\n");
		return (-1);
	}
	if (!data->colors.ceiling_set)
	{
		printf("Error\nCeiling color (C) is missing\n");
		return (-1);
	}
	if (data->map_data.map_height == 0)
	{
		printf("Error\nMap is missing\n");
		return (-1);
	}
	return (0);
}

/**
 * Validates that the file has a .cub extension.
 * @param filename The filename to check.
 * @return 0 if valid, -1 otherwise.
 */
static int	check_file_extension(char *filename)
{
	int len = ft_strlen(filename);
	if (len < 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
	{
		printf("Error\nFile must have .cub extension\n");
		return (-1);
	}
	return (0);
}

/**
 * Checks if all required textures (NO, SO, WE, EA) are set.
 * @param data Pointer to the file data structure.
 * @return 0 if all textures are set, -1 otherwise.
 */
static int	check_textures(t_file_data *data)
{
	if (!data->textures.north_set || !data->textures.south_set || !data->textures.west_set
		|| !data->textures.east_set)
	{
		printf("Error\nAll textures (NO, SO, WE, EA) are required\n");
		return (-1);
	}
	return (0);
}

/**
 * Parses command line arguments and validates the .cub file.
 * Checks file extension, reads and parses the file content,
 * ensures all required textures and colors are set.
 * @param data Pointer to the file data structure to fill.
 * @param argv Command line arguments array.
 * @return 0 on success, -1 on error.
 */
int	parsing_args(t_file_data *data, char **argv)
{
	if (check_file_extension(argv[1]) == -1)
		return (-1);
	if (read_file(argv[1], data) == -1)
		return (-1);
	if (check_textures(data) == -1)
		return (-1);
	if (handle_floor_ceilling_error(data) == -1)
		return (-1);
	return (0);
}

/**
 * Frees all dynamically allocated memory in the file data structure.
 * @param data Pointer to the file data structure.
 */
void	free_file_data(t_file_data *data)
{
	if (data->textures.north_texture)
		free(data->textures.north_texture);
	if (data->textures.south_texture)
		free(data->textures.south_texture);
	if (data->textures.west_texture)
		free(data->textures.west_texture);
	if (data->textures.east_texture)
		free(data->textures.east_texture);
	if (data->map_data.map)
	{
		for (int i = 0; i < data->map_data.map_height; i++)
			free(data->map_data.map[i]);
		free(data->map_data.map);
		data->map_data.map = NULL;
	}
	else
	{
		ft_lstclear(&data->map_data.map_lines, free);
	}
}
