/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:00:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Validates that all characterfree the map are valid.
 * Allowed characters: 0, 1, N, S, E, W.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
int validate_characters(t_file_data *data)
{
    int y = 0;
    while (y < data->map_data.map_height)
    {
        int len = ft_strlen(data->map_data.map[y]);
        int x = 0;
        while (x < len)
        {
            char c = data->map_data.map[y][x];
            if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W')
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

/**
 * Processes a single character for player validation.
 * Increments count if player char found, sets position and direction.
 * @param c The character to check.
 * @param count Pointer to player count.
 * @param x X position.
 * @param y Y position.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
static int	process_player_char(char c, int *count, int x, int y, t_file_data *data)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*count > 0)
		{
			printf("Error\nMultiple players in map\n");
			return (-1);
		}
		(*count)++;
		data->player.player_x = x;
		data->player.player_y = y;
		data->player.player_dir = c;
		data->map_data.map[y][x] = '0';
	}
	return (0);
}

/**
 * Validates that there is exactly one player in the map.
 * Sets player position and direction, replaces player char with '0'.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
int validate_player(t_file_data *data)
{
	int count = 0;
	int y = 0;

	while (y < data->map_data.map_height)
	{
		int len = ft_strlen(data->map_data.map[y]);
		int x = 0;
		while (x < len)
		{
			if (process_player_char(data->map_data.map[y][x], &count, x, y, data) == -1)
				return (-1);
			x++;
		}
		y++;
	}
	if (count == 0)
	{
		printf("Error\nNo player in map\n");
		return (-1);
	}
	return (0);
}

/**
 * Validates that the map borders are properly walled.
 * Calls validation for top/bottom and left/right borders.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
int validate_borders_only(t_file_data *data)
{
    if (validate_top_bottom(data) == -1)
        return -1;
    if (validate_left_right(data) == -1)
        return -1;
    return 0;
}

/**
 * Validates that the top and bottom borders of the map are walls.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
int validate_top_bottom(t_file_data *data)
{
    int len_top = ft_strlen(data->map_data.map[0]);
    int x = 0;
    while (x < len_top) {
        if (data->map_data.map[0][x] != '1') {
            printf("Error\nMap top border must be walls\n");
            return -1;
        }
        x++;
    }

    int len_bottom = ft_strlen(data->map_data.map[data->map_data.map_height - 1]);
    x = 0;
    while (x < len_bottom) {
        if (data->map_data.map[data->map_data.map_height - 1][x] != '1') {
            printf("Error\nMap bottom border must be walls\n");
            return -1;
        }
        x++;
    }

    return 0;
}

/**
 * Validates that the left and right borders of the map are walls.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
int validate_left_right(t_file_data *data)
{
    int y = 0;
    while (y < data->map_data.map_height) {
        int len = ft_strlen(data->map_data.map[y]);
        if (data->map_data.map[y][0] != '1') {
            printf("Error\nMap left border must be walls\n");
            return -1;
        }
        if (data->map_data.map[y][len - 1] != '1') {
            printf("Error\nMap right border must be walls\n");
            return -1;
        }
        y++;
    }

    return 0;
}