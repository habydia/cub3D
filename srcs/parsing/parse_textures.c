/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:19:20 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


//ok norme
// refracorer pour éviter les répétitions

/**
 * Processes the north texture definition.
 * Checks for duplicates and extracts the texture path.
 * @param data Pointer to the file data structure.
 * @param line The line containing the texture definition.
 * @return 0 on success, -1 on error.
 */
static int	north_texture(t_file_data *data, char *line)
{
	if (data->textures.north_texture)
	{
		printf("Error\nDuplicate NO texture\n");
		return (-1);
	}
	if (extract_texture(line + 3, &data->textures.north_texture) == 0)
	{
		data->textures.north_set = 1;
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
static int south_texture(t_file_data *data, char *line)
{
    if (data->textures.south_texture)
    {
        printf("Error\nDuplicate SO texture\n");
        return (-1);
    }
    if (extract_texture(line + 3, &data->textures.south_texture) == 0)
    {
        data->textures.south_set = 1;
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
static  int west_texture(t_file_data *data, char *line)
{
    if (data->textures.west_texture)
    {
        printf("Error\nDuplicate WE texture\n");
        return (-1);
    }
    if (extract_texture(line + 3, &data->textures.west_texture) == 0)
    {
        data->textures.west_set = 1;
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
static int east_texture(t_file_data *data, char *line)
{
    if (data->textures.east_texture)
    {
        printf("Error\nDuplicate EA texture\n");
        return (-1);
    }
    if (extract_texture(line + 3, &data->textures.east_texture) == 0)
    {
        data->textures.east_set = 1;
        return (0);
    }
    return (-1);
}

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
 * Trims leading spaces, checks for .xpm extension, and duplicates the path.
 * @param path The string containing the path.
 * @param texture Pointer to store the duplicated path.
 * @return 0 on success, -1 on error.
 */
int	extract_texture(char *path, char **texture)
{
	while (*path == ' ')
		path++;
	if (*path == '\0')
		return (-1);
	int len = ft_strlen(path);
	if (len < 4 || ft_strcmp(path + len - 4, ".xpm") != 0)
	{
		printf("Error\nTexture file must have .xpm extension\n");
		return (-1);
	}
	*texture = ft_strdup(path);
	if (!*texture)
		return -1;
	return 0;
}
