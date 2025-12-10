/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:24:14 by hadia             #+#    #+#             */
/*   Updated: 2025/12/10 19:28:50 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int process_map(char *line, t_file_data *data)
{
    // Si la ligne est vide, ignorer
    if (!line || *line == '\0' || *line == '\n')
        return 0;

    // Ajouter la ligne à la liste
    t_list *temp_map = ft_lstnew(ft_strdup(line));
    if (!temp_map || !temp_map->content)
    {
        free(temp_map);
        return -1;
    }
    ft_lstadd_back(&data->map_lines, temp_map);

    return 0;
}

// Fonction à appeler après read_file pour finaliser la map
int lstmap_to_charmap(t_file_data *data)
{
    // Compter le nombre de lignes
    int height = ft_lstsize(data->map_lines);
    if (height == 0)
        return 0;

    // Allouer le tableau 2D
    data->map = malloc(sizeof(char *) * height);
    if (!data->map)
        return -1;

    // Remplir le tableau (inverser l'ordre si nécessaire)
    t_list *tmp = data->map_lines;
    int i = height - 1;
    while (i >= 0)
    {
        data->map[i] = (char *)tmp->content;
        tmp = tmp->next;
        i--;
    }

    data->map_height = height;
    data->map_width = ft_strlen(data->map[0]);
    
    // Validations
    if (validate_player(data) == -1)
        return -1;
    if (validate_characters(data) == -1)
        return -1;
    if (validate_borders_only(data) == -1)
        return -1;

    // Libérer la liste (mais pas le contenu, car c'est dans map)
    ft_lstclear(&data->map_lines, NULL);

    return 0;
}

// Validation des caractères de la map (doivent être 0, 1, N, S, E, W ou espaces)
int validate_characters(t_file_data *data)
{
    int y = 0;
    while (y < data->map_height)
    {
        int len = ft_strlen(data->map[y]);
        int x = 0;
        while (x < len)
        {
            char c = data->map[y][x];
            if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != ' ')
            {
                printf("Error\nInvalid character in map: '%c' (ASCII: %d) at y=%d x=%d\n", c, (int)c, y, x);
                return -1;
            }
            x++;
        }
        y++;
    }
    return 0;
}

// Validation du joueur unique
int validate_player(t_file_data *data)
{
    int count = 0;
    int y = 0;
    while (y < data->map_height)
    {
        int len = ft_strlen(data->map[y]);
        int x = 0;
        while (x < len)
        {
            char c = data->map[y][x];
            if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
            {
                if (count++ > 0)
                {
                    printf("Error\nMultiple players in map\n");
                    return -1;
                }
                data->player_x = x;
                data->player_y = y;
                data->player_dir = c;
                data->map[y][x] = '0';
            }
            x++;
        }
        y++;
    }
    if (count == 0)
    {
        printf("Error\nNo player in map\n");
        return -1;
    }
    return 0;
}

// Validation simplifiée : vérifie que les bordures sont des murs '1'
int validate_borders_only(t_file_data *data)
{
    if (validate_top_bottom(data) == -1)
        return -1;
    if (validate_left_right(data) == -1)
        return -1;
    return 0;
}

// Vérifier les bords haut et bas
int validate_top_bottom(t_file_data *data)
{
    int len_top = ft_strlen(data->map[0]);
    int x = 0;
    while (x < len_top) {
        if (data->map[0][x] != '1') {
            printf("Error\nMap top border must be walls\n");
            return -1;
        }
        x++;
    }

    int len_bottom = ft_strlen(data->map[data->map_height - 1]);
    x = 0;
    while (x < len_bottom) {
        if (data->map[data->map_height - 1][x] != '1') {
            printf("Error\nMap bottom border must be walls\n");
            return -1;
        }
        x++;
    }

    return 0;
}

// Vérifier les bords gauche et droite
int validate_left_right(t_file_data *data)
{
    int y = 0;
    while (y < data->map_height) {
        int len = ft_strlen(data->map[y]);
        if (data->map[y][0] != '1') {
            printf("Error\nMap left border must be walls\n");
            return -1;
        }
        if (data->map[y][len - 1] != '1') {
            printf("Error\nMap right border must be walls\n");
            return -1;
        }
        y++;
    }

    return 0;
}
