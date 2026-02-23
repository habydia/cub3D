/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 09:46:24 by hadia             #+#    #+#             */
/*   Updated: 2026/02/23 10:52:00 by hadia            ###   ########.fr       */
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
static int	process_file_lines(int fd, t_file_data *data)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		size_t len = ft_strlen(line);
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

/*fonction chargée de lire un fichier et de traiter chaque ligne */
/**
 * Reads and parses the .cub file line by line.
 * Opens the file, processes each line, and converts the map to a 2D array.
 * @param file_path Path to the .cub file.
 * @param data Pointer to the file data structure to fill.
 * @return 0 on success, -1 on error.
 */
int read_file(char *file_path, t_file_data *data)
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
		return (-1);
	}
	close(fd);
	if (lstmap_to_charmap(data) == -1)
		return -1;
	return (0);
}
/**
 * Handles empty or whitespace-only lines.
 * Checks if the line is empty and if map has started.
 * @param trimmed The trimmed line.
 * @param data Pointer to the file data structure.
 * @return 0 if empty and valid, -1 if error, 1 if not empty.
 */
static int	handle_empty_line(char *trimmed, t_file_data *data)
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
static int	try_process_textures(char *trimmed, t_file_data *data)
{
	int ret = process_textures(trimmed, data);
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
static int	try_process_colors(char *trimmed, t_file_data *data)
{
	int ret = process_colors(trimmed, data);
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
 * Processes a single line from the file.
 * Trims the line, checks for emptiness, and attempts to parse textures or colors,
 * or processes as map line.
 * @param line The line to process.
 * @param data Pointer to the file data structure.
 * @return 0 on success, -1 on error.
 */
int process_line(char *line, t_file_data *data)
{
	char *trimmed;
	int ret;

	if (!line)
		return (0);
	trimmed = ft_strtrim(line, " \t");
	ret = handle_empty_line(trimmed, data);
	if (ret != 1)
	{
		free(trimmed);
		return (ret);
	}
	ret = try_process_textures(trimmed, data);
	if (ret != 1)
	{
		free(trimmed);
		return (ret);
	}
	ret = try_process_colors(trimmed, data);
	if (ret != 1)
	{
		free(trimmed);
		return (ret);
	}
	ret = process_map(line, data);
	free(trimmed);
	if (ret == 0)
		data->has_map_started = 1;
	return (ret);
}
