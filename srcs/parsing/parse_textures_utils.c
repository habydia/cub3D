/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:30:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 01:31:06 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Processes the north texture definition.
 * Checks for duplicates and extracts the texture path.
 * @param data Pointer to the file data structure.
 * @param line The line containing the texture definition.
 * @return 0 on success, -1 on error.
 */
int	north_texture(t_file_data *data, char *line)
{
	if (data->north_texture)
	{
		printf("Error\nDuplicate NO texture\n");
		return (-1);
	}
	if (extract_texture(line + 3, &data->north_texture) == 0)
	{
		data->north_set = 1;
		return (0);
	}
	return (-1);
}

/**
 * Processes the south texture definition.
 * Checks for duplicates and extracts the texture path.
 * @param data Pointer to the file data structure.
 * @param line The line containing the texture definition.
 * @return 0 on success, -1 on error.
 */
int	south_texture(t_file_data *data, char *line)
{
	if (data->south_texture)
	{
		printf("Error\nDuplicate SO texture\n");
		return (-1);
	}
	if (extract_texture(line + 3, &data->south_texture) == 0)
	{
		data->south_set = 1;
		return (0);
	}
	return (-1);
}

/**
 * Processes the west texture definition.
 * Checks for duplicates and extracts the texture path.
 * @param data Pointer to the file data structure.
 * @param line The line containing the texture definition.
 * @return 0 on success, -1 on error.
 */
int	west_texture(t_file_data *data, char *line)
{
	if (data->west_texture)
	{
		printf("Error\nDuplicate WE texture\n");
		return (-1);
	}
	if (extract_texture(line + 3, &data->west_texture) == 0)
	{
		data->west_set = 1;
		return (0);
	}
	return (-1);
}

/**
 * Processes the east texture definition.
 * Checks for duplicates and extracts the texture path.
 * @param data Pointer to the file data structure.
 * @param line The line containing the texture definition.
 * @return 0 on success, -1 on error.
 */
int	east_texture(t_file_data *data, char *line)
{
	if (data->east_texture)
	{
		printf("Error\nDuplicate EA texture\n");
		return (-1);
	}
	if (extract_texture(line + 3, &data->east_texture) == 0)
	{
		data->east_set = 1;
		return (0);
	}
	return (-1);
}
