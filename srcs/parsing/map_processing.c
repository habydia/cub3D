/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:00:00 by hadia             #+#    #+#             */
/*   Updated: 2026/03/14 01:37:08 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Processes a map line by validating and storing it.
 * Checks for invalid characters and adds the line to the map list.
 * @param line The map line to process.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int	process_map(char *line, t_file_data *data)
{
	t_list	*temp_map;
	char	*line_copy;

	if (!line || *line == '\0' || *line == '\n')
		return (0);
	if (check_map_line_valid(line) == -1)
		return (-1);
	line_copy = ft_strdup(line);
	if (!line_copy)
		return (-1);
	temp_map = ft_lstnew(line_copy);
	if (!temp_map)
	{
		free(line_copy);
		return (-1);
	}
	ft_lstadd_back(&data->map_lines, temp_map);
	return (0);
}

/**
 * Converts the linked list of map lines to a 2D char array.
 * Allocates the map, fills it, sets dimensions, runs validations.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int	lstmap_to_charmap(t_file_data *data)
{
	int		height;
	char	**temp_map;

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
		cleanup_on_error(temp_map, height, data);
		return (-1);
	}
	ft_lstclear(&data->map_lines, free);
	return (0);
}
