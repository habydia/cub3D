/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:19:20 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 12:49:05 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int process_textures(char *line, t_file_data *data)
{
    if (ft_strncmp(line, "NO ", 3) == 0)
    {
        if (data->north_texture) return -1;  // Doublon
        return extract_texture(line + 3, &data->north_texture);
    }
    else if (ft_strncmp(line, "SO ", 3) == 0)
    {
        if (data->south_texture) return -1;
        return extract_texture(line + 3, &data->south_texture);
    }
    else if (ft_strncmp(line, "WE ", 3) == 0)
    {
        if (data->west_texture) return -1;
        return extract_texture(line + 3, &data->west_texture);
    }
    else if (ft_strncmp(line, "EA ", 3) == 0)
    {
        if (data->east_texture) return -1;
        return extract_texture(line + 3, &data->east_texture);
    }
    return 1;  // Pas une texture
}

int extract_texture(char *path, char **texture)
{
    
    while (*path == ' ')
        path++;
    if (*path == '\0')
        return -1;  
    *texture = ft_strdup(path);
    if (!*texture)
        return -1;
    return 0;
}