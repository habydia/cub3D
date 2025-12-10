/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:24 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 19:27:50 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/*fonction chargée de lire un fichier et de traiter chaque ligne */
int read_file(char *file_path, t_file_data *data)
{
    int		fd;
    char	*line;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        printf("Error\nCould not open file\n");
        return (-1);
    }
    line = get_next_line(fd);
    while (line)
    {
        // Enlever le \n de fin si présent
        size_t len = ft_strlen(line);
        if (len > 0 && line[len - 1] == '\n')
            line[len - 1] = '\0';
        if (process_line(line, data) == -1)
        {
            free(line);
            close(fd);
            return (-1);
        }
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    if (lstmap_to_charmap(data) == -1)
        return -1;
    return (0);
}



/*fonction chargée de traiter chaque ligne lue */
int process_line(char *line, t_file_data *data)
{
    int ret;
    char *trimmed;

    if (!line || *line == '\0' || *line == '\n')
        return 0;
    trimmed = ft_strtrim(line, " \t");
    if (!trimmed || *trimmed == '\0')
    {
        free(trimmed);
        return 0;
    }
    ret = process_textures(trimmed, data);
    if (ret != 1)
    {
        if (data->has_map_started)
        {
            printf("Error\nMap must be at the end of the file\n");
            free(trimmed);
            return -1;
        }
        free(trimmed);
        return ret;
    }
    ret = process_colors(trimmed, data);
    if (ret != 1)
    {
        if (data->has_map_started)
        {
            printf("Error\nMap must be at the end of the file\n");
            free(trimmed);
            return -1;
        }
        free(trimmed);
        return ret;
    }
    // Sinon, map
    ret = process_map(trimmed, data);
    free(trimmed);
    if (ret == 0)
        data->has_map_started = 1;
    return ret;
}
