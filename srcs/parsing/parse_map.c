/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:24:14 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 10:52:00 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Validates that a map line contains only valid characters.
 * Checks for spaces or tabs, which are not allowed.
 * @param line The line to validate.
 * @return 0 if valid, -1 otherwise.
 */
static int	check_map_line_valid(char *line)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
		{
			printf("Error\nMap lines cannot contain spaces or tabs\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

/**
 * Processes a map line by validating and storing it.
 * Checks for invalid characters and adds the line to the map list.
 * @param line The map line to process.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int process_map(char *line, t_file_data *data)
{
	t_list *temp_map;

	if (!line || *line == '\0' || *line == '\n')
		return (0);
	if (check_map_line_valid(line) == -1)
		return (-1);
	temp_map = ft_lstnew(ft_strdup(line));
	if (!temp_map || !temp_map->content)
	{
		free(temp_map);
		return (-1);
	}
	ft_lstadd_back(&data->map_lines, temp_map);
	return (0);
}

/**
 * Allocates and fills a temporary 2D array with map lines.
 * Reverses the order of lines from the list.
 * @param data Pointer to the file data structure.
 * @param height Number of lines.
 * @return Pointer to the allocated 2D array, or NULL on error.
 */
static char	**allocate_and_fill_temp_map(t_file_data *data, int height)
{
	char **temp_map;
	t_list *tmp;
	int i;

	temp_map = malloc(sizeof(char *) * height);
	if (!temp_map)
		return (NULL);
	tmp = data->map_lines;
	i = height - 1;
	while (i >= 0)
	{
		temp_map[i] = ft_strdup((char *)tmp->content);
		if (!temp_map[i])
		{
			while (++i < height)
				free(temp_map[i]);
			free(temp_map);
			return (NULL);
		}
		tmp = tmp->next;
		i--;
	}
	return (temp_map);
}

/**
 * Runs all map validation functions.
 * @param data Pointer to the file data structure.
 * @return 0 if all validations pass, -1 otherwise.
 */
static int	run_validations(t_file_data *data)
{
	if (validate_player(data) == -1)
		return (-1);
	if (validate_characters(data) == -1)
		return (-1);
	if (validate_borders_only(data) == -1)
		return (-1);
	return (0);
}

/**
 * Converts the linked list of map lines to a 2D char array.
 * Allocates the map, fills it, sets dimensions, runs validations.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int lstmap_to_charmap(t_file_data *data)
{
	int height;
	char **temp_map;

	height = ft_lstsize(data->map_lines);
	if (height == 0)
		return (0);
	temp_map = allocate_and_fill_temp_map(data, height);
	if (!temp_map)
		return (-1);
	data->map_height = height;
	data->map_width = ft_strlen(temp_map[0]);
	data->map = temp_map;
	if (run_validations(data) == -1)
	{
		for (int j = 0; j < height; j++)
			free(temp_map[j]);
		free(temp_map);
		ft_lstclear(&data->map_lines, free);
		data->map = NULL;
		return (-1);
	}
	ft_lstclear(&data->map_lines, free);
	return (0);
}

/**
 * Validates that all characterfree the map are valid.
 * Allowed characters: 0, 1, N, S, E, W.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
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
		data->player_x = x;
		data->player_y = y;
		data->player_dir = c;
		data->map[y][x] = '0';
	}
	return (0);
}

// Validation du joueur unique
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

	while (y < data->map_height)
	{
		int len = ft_strlen(data->map[y]);
		int x = 0;
		while (x < len)
		{
			if (process_player_char(data->map[y][x], &count, x, y, data) == -1)
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

// Validation simplifiée : vérifie que les bordures sont des murs '1'
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

/**
 * Validates that the left and right borders of the map are walls.
 * @param data Pointer to the file data structure.
 * @return 0 if valid, -1 otherwise.
 */
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
