/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_processing_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:40:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 01:33:06 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Validates that a map line contains only valid characters.
 * Checks for spaces or tabs, which are not allowed.
 * @param line The line to validate.
 * @return 0 if valid, -1 otherwise.
 */
int	check_map_line_valid(char *line)
{
	int	i;

	i = 0;
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
 * Allocates and fills a temporary 2D array with map lines.
 * Reverses the order of lines from the list.
 * @param data Pointer to the file data structure.
 * @param height Number of lines.
 * @return Pointer to the allocated 2D array, or NULL on error.
 */
char	**allocate_and_fill_temp_map(t_file_data *data, int height)
{
	char	**temp_map;
	t_list	*tmp;
	int		i;

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
int	run_validations(t_file_data *data)
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
 * Cleans up temporary map data on validation failure.
 * @param temp_map The allocated map array.
 * @param height Number of lines.
 * @param data Pointer to the file data structure.
 */
void	cleanup_on_error(char **temp_map, int height, t_file_data *data)
{
	int	j;

	j = 0;
	while (j < height)
	{
		free(temp_map[j]);
		j++;
	}
	free(temp_map);
	ft_lstclear(&data->map_lines, free);
	data->map = NULL;
}
