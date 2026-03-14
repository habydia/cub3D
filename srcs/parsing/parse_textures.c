/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:19:20 by hadia             #+#    #+#             */
/*   Updated: 2026/03/14 01:36:31 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include <unistd.h>

/**
 * Processes a line to check if it defines a texture.
 * Dispatches to the appropriate texture handler based on the prefix.
 * @param line The line to process.
 * @param data Pointer to the file data structure.
 * @return 0 if processed, 1 if not a texture, -1 on error.
 */
int	process_textures(char *line, t_file_data *data)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		return (north_texture(data, line));
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		return (south_texture(data, line));
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		return (west_texture(data, line));
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		return (east_texture(data, line));
	}
	return (1);
}

/**
 * Extracts and validates a texture path from a string.
 * Trims leading spaces, checks for .xpm extension, verifies file exists,
 * and duplicates the path.
 * @param path The string containing the path.
 * @param texture Pointer to store the duplicated path.
 * @return 0 on success, -1 on error.
 */
int	extract_texture(char *path, char **texture)
{
	int	len;

	while (*path == ' ')
		path++;
	if (*path == '\0')
		return (-1);
	len = ft_strlen(path);
	if (len < 4 || ft_strcmp(path + len - 4, ".xpm") != 0)
	{
		printf("Error\nTexture file must have .xpm extension\n");
		return (-1);
	}
	if (access(path, F_OK) == -1)
	{
		printf("Error\nTexture file not found: %s\n", path);
		return (-1);
	}
	*texture = ft_strdup(path);
	if (!*texture)
		return (-1);
	return (0);
}
