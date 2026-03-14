/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 01:35:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 01:44:16 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/**
 * Processes all lines from the file descriptor.
 * Reads lines using get_next_line and processes each one.
 * @param fd File descriptor of the open file.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int	process_file_lines(int fd, t_file_data *data)
{
	char	*line;
	size_t	len;

	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		if (process_line(line, data) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}

/**
 * Handles empty or whitespace-only lines.
 * Checks if the line is empty and if map has started.
 * @param trimmed The trimmed line.
 * @param data Pointer to the file data structure.
 * @return 0 if empty and valid, -1 if error, 1 if not empty.
 */
int	handle_empty_line(char *trimmed, t_file_data *data)
{
	if (!trimmed || *trimmed == '\0')
	{
		if (data->has_map_started)
		{
			printf("error\nline must be notempty\nparsing fail\n");
			return (-1);
		}
		return (0);
	}
	return (1);
}

/**
 * Attempts to process the line as a texture definition.
 * @param trimmed The trimmed line.
 * @param data Pointer to the file data structure.
 * @return 0 if processed, -1 on error, 1 if not a texture.
 */
int	try_process_textures(char *trimmed, t_file_data *data)
{
	int	ret;

	ret = process_textures(trimmed, data);
	if (ret != 1)
	{
		if (data->has_map_started)
		{
			printf("Error\nMap must be at the end of the file\n");
			return (-1);
		}
		return (ret);
	}
	return (1);
}

/**
 * Attempts to process the line as a color definition.
 * @param trimmed The trimmed line.
 * @param data Pointer to the file data structure.
 * @return 0 if processed, -1 on error, 1 if not a color.
 */
int	try_process_colors(char *trimmed, t_file_data *data)
{
	int	ret;

	ret = process_textures(trimmed, data);
	if (ret != 1)
	{
		if (data->has_map_started)
		{
			printf("Error\nMap must be at the end of the file\n");
			return (-1);
		}
		return (ret);
	}
	return (1);
}

/**
 * Tries to process the line as textures, colors, or map.
 * @param trimmed The trimmed line.
 * @param line The original line.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int	try_process_line_components(char *trimmed, char *line, t_file_data *data)
{
	int	ret;

	ret = try_process_textures(trimmed, data);
	if (ret != 1)
		return (ret);
	ret = try_process_colors(trimmed, data);
	if (ret != 1)
		return (ret);
	ret = process_map(line, data);
	if (ret == 0)
		data->has_map_started = 1;
	return (ret);
}
