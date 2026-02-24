/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:21:14 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 15:11:52 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "parsing.h"
# include "textures.h"

typedef struct s_game
{
	void		*mlx_ptr;
	void		*mlx_window_ptr;
	void		*mlx_image_ptr;
	char		*pixel_buffer;
	int			bits_for_one_pixel;
	int			bytes_per_scanline;
	int			byte_order;

	t_file_data	*data;
	t_textures	textures;

	double		player_pos_x;
	double		player_pos_y;
	double		player_vector_direction_x;
	double		player_vector_direction_y;
	double		camera_plane_x;
	double		camera_plane_y;

	int			keys[65536];
}				t_game;

/* Prototypes */
void			init_game(t_game *game, t_file_data *data);
void			init_data_map(t_game *game, t_file_data *data);
void			init_key_press_state(t_game *game);
void			init_player_position(t_game *game, t_file_data *data);
void			init_player_direction(t_game *game, t_file_data *data);

#endif
