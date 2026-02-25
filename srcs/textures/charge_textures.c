/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charge_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:48:20 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 17:10:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	*get_texture_path(t_file_data *data, char face)
{
	if (face == 'N' && data && data->north_texture)
		return (data->north_texture);
	else if (face == 'S' && data && data->south_texture)
		return (data->south_texture);
	else if (face == 'E' && data && data->east_texture)
		return (data->east_texture);
	else if (face == 'W' && data && data->west_texture)
		return (data->west_texture);
	return (NULL);
}

static void	load_all_textures(t_game *game, t_file_data *data)
{
	char	*path;

	path = get_texture_path(data, 'N');
	if (path)
		load_texture_by_face(game, path, 'N');
	path = get_texture_path(data, 'S');
	if (path)
		load_texture_by_face(game, path, 'S');
	path = get_texture_path(data, 'E');
	if (path)
		load_texture_by_face(game, path, 'E');
	path = get_texture_path(data, 'W');
	if (path)
		load_texture_by_face(game, path, 'W');
}

void	load_textures(t_game *game, t_file_data *file_data)
{
	load_all_textures(game, file_data);
	sync_all_texture_fields(game);
	printf("All textures loaded\n");
}
