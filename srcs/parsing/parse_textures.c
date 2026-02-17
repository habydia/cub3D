/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:19:20 by hadia             #+#    #+#             */
/*   Updated: 2026/02/17 18:29:33 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


//ok norme
// refracorer pour éviter les répétitions

static int	north_texture(t_file_data *data, char *line)
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

static int south_texture(t_file_data *data, char *line)
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

static  int west_texture(t_file_data *data, char *line)
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

static int east_texture(t_file_data *data, char *line)
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
	return (1); // Pas une texture
}

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
