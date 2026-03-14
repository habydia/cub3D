/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:24 by hadia             #+#    #+#             */
/*   Updated: 2026/03/14 01:43:09 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Reads and parses the .cub file line by line.
 * Opens the file, processes each line, and converts the map to a 2D array.
 * @param file_path Path to the .cub file.
 * @param data Pointer to the file data structure to fill.
 * @return 0 on success, -1 on error.
 */
int	read_file(char *file_path, t_file_data *data)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCould not open file\n");
		return (-1);
	}
	if (process_file_lines(fd, data) == -1)
	{
		close(fd);
		get_next_line(-1);
		return (-1);
	}
	close(fd);
	get_next_line(-1);
	if (lstmap_to_charmap(data) == -1)
		return (-1);
	return (0);
}

/**
 * Processes a single line from the file.
 * Trims the line, checks for emptiness,
 * and attempts to parse textures or colors, or processes as map line.
 * @param line The line to process.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int	process_line(char *line, t_file_data *data)
{
	char	*trimmed;
	int		ret;

	if (!line)
		return (0);
	trimmed = ft_strtrim(line, " \t");
	ret = handle_empty_line(trimmed, data);
	if (ret != 1)
	{
		free(trimmed);
		return (ret);
	}
	ret = try_process_line_components(trimmed, line, data);
	free(trimmed);
	return (ret);
}
