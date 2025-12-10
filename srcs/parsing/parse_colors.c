/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:18:02 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 18:17:35 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int process_colors(char *line, t_file_data *data)
{
    if (ft_strncmp(line, "F ", 2) == 0)
    {
        if (parse_rgb(line + 2, data->floor_color) == 0)
        {
            data->floor_set = 1;
            return 0;
        }
        return -1;
    }
    else if (ft_strncmp(line, "C ", 2) == 0)
    {
        if (parse_rgb(line + 2, data->ceiling_color) == 0)
        {
            data->ceiling_set = 1;
            return 0;
        }
        return -1;
    }
    return 1;  // Pas une couleur
}


// Fonction pour parser RGB
int parse_rgb(char *str, int color[3])
{
    char **tokens = ft_split(str, ',');

    if (!tokens || !tokens[0]
        || !tokens[1] || !tokens[2])
    {
        printf("Error\nInvalid RGB format\n");
        return -1;
    }

    color[0] = ft_atoi(tokens[0]);
    color[1] = ft_atoi(tokens[1]);
    color[2] = ft_atoi(tokens[2]);

    if (color[0] < 0 || color[0] > 255 || color[1] < 0 
        || color[1] > 255 || color[2] < 0 || color[2] > 255)
    {
        printf("Error\nRGB values must be between 0 and 255\n");
        free(tokens[0]);
        free(tokens[1]);
        free(tokens[2]);
        free(tokens);
        return -1;
    }

    free(tokens[0]);
    free(tokens[1]);
    free(tokens[2]);
    free(tokens);
    return 0;
}
