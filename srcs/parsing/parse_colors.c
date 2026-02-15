/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:18:02 by hadia             #+#    #+#             */
/*   Updated: 2026/02/15 15:42:55 by hadia            ###   ########.fr       */
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
    int i = 0;
    int comma_count = 0;
    int start = 0;
    int j = 0;

    // Compter les virgules et vérifier qu'il n'y en a pas de consécutives ou en début/fin
    while (str[i])
    {
        if (str[i] == ',')
        {
            comma_count++;
            if (i == 0 || str[i + 1] == ',' || str[i + 1] == '\0' || (i > 0 && str[i - 1] == ','))
                return -1;  // Virgule en début, fin, ou consécutive
        }
        i++;
    }
    if (comma_count != 2)
        return -1;  // Pas exactement 2 virgules

    // Maintenant parser les valeurs
    i = 0;
    j = 0;
    while (str[i] && j < 3)
    {
        if (str[i] == ',')
        {
            // Extraire la valeur de start à i-1
            char *num_str = ft_substr(str, start, i - start);
            if (!num_str)
                return -1;
            color[j] = ft_atoi(num_str);
            free(num_str);
            if (color[j] < 0 || color[j] > 255)
                return -1;
            start = i + 1;
            j++;
        }
        i++;
    }
    // Dernière valeur
    if (j < 3)
    {
        char *num_str = ft_substr(str, start, i - start);
        if (!num_str)
            return -1;
        color[j] = ft_atoi(num_str);
        free(num_str);
        if (color[j] < 0 || color[j] > 255)
            return -1;
    }

    return 0;
}
