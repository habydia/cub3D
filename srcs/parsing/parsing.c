/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:47:42 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 18:17:35 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int parsing_args(t_file_data *data, char **argv)
{
    char *filename = argv[1];
    int len = ft_strlen(filename);
    if (len < 4 || ft_strcmp(filename + len - 4, ".cub") != 0)
    {
        printf("Error\nFile must have .cub extension\n");
        return -1;
    }
    if (read_file(argv[1], data) == -1)
        return -1;
    if (!data->north_set || !data->south_set || !data->west_set || !data->east_set)
    {
        printf("Error\nAll textures (NO, SO, WE, EA) are required\n");
        return -1;
    }
    if (!data->floor_set)
    {
        printf("Error\nFloor color (F) is missing\n");
        return -1;
    }
    if (!data->ceiling_set)
    {
        printf("Error\nCeiling color (C) is missing\n");
        return -1;
    }
    if (data->map_height == 0)
    {
        printf("Error\nMap is missing\n");
        return -1;
    }
    return (0);
}