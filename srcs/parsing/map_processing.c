/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:00:00 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 11:20:45 by hadia            ###   ########.fr       */
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
	ft_lstadd_back(&data->map_data.map_lines, temp_map);
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
	tmp = data->map_data.map_lines;
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

	height = ft_lstsize(data->map_data.map_lines);
	if (height == 0)
		return (0);
	temp_map = allocate_and_fill_temp_map(data, height);
	if (!temp_map)
		return (-1);
	data->map_data.map_height = height;
	data->map_data.map_width = ft_strlen(temp_map[0]);
	data->map_data.map = temp_map;
	if (run_validations(data) == -1)
	{
		for (int j = 0; j < height; j++)
			free(temp_map[j]);
		free(temp_map);
		ft_lstclear(&data->map_data.map_lines, free);
		data->map_data.map = NULL;
		return (-1);
	}
	ft_lstclear(&data->map_data.map_lines, free);
	return (0);
}