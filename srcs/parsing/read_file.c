/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:24 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 12:59:55 by hadia            ###   ########.fr       */
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
    return (0);
}



/*fonction chargée de traiter chaque ligne lue */
int process_line(char *line, t_file_data *data)
{
    int ret;

    if (!line || *line == '\0' || *line == '\n')
        return 0;
    ret = process_textures(line, data);
    if (ret != 1)
        return ret;
    ret = process_colors(line, data);
    if (ret != 1)
        return ret;
    // Sinon, map
    return process_map(line, data);
}
