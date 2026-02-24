/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:02:51 by hadia             #+#    #+#             */
/*   Updated: 2026/02/24 00:12:51 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H
# include "../libft/libft.h"
# include "parsing.h"

typedef struct s_file_data	t_file_data;
typedef struct s_game		t_game;

typedef struct s_textures_data
{
	void					**img;
	char					**data;
	int						*w;
	int						*h;
	int						*line_len;
	int						*bpp;
	int						*endian;
}							t_textures_data;

typedef struct s_textures
{
	void					*north_img;
	void					*south_img;
	void					*west_img;
	void					*east_img;

	int						width;
	int						height;

	char					*north_data;
	char					*south_data;
	char					*west_data;
	char					*east_data;

	int						north_bpp;
	int						north_width;
	int						north_height;
	int						north_line_len;
	int						north_endian;

	int						south_bpp;
	int						south_line_len;
	int						south_height;
	int						south_width;
	int						south_endian;

	int						west_bpp;
	int						west_height;
	int						west_width;
	int						west_line_len;
	int						west_endian;

	int						east_bpp;
	int						east_line_len;
	int						east_height;
	int						east_width;
	int						east_endian;

}							t_textures;

void						load_textures(t_game *game, t_file_data *data);
void						load_texture_by_face(t_game *game, char *path,
								char face);
void						get_texture_ptrs(t_game *game, char face,
								t_textures_data *tex);
void						free_textures(t_game *game);
void						free_game(t_game *game);

#endif /* TEXTURES_H */
