/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:21:14 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 15:29:15 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "parsing.h"
# include "player.h"
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

///////////////////////////////////////////////////////////////////////////////
////////////////////////////GAME INITIALIZATION///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*INIT GAME: INITIALIZE THE ENTIRE GAME STRUCTURE WITH ALL SUBSYSTEMS*/
void			init_game(t_game *game, t_file_data *data);

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////DATA INITIALIZATION//////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*INIT DATA MAP: INITIALIZE MAP DATA AND GAME SETTINGS FROM FILE DATA*/
void			init_data_map(t_game *game, t_file_data *data);

/*INIT KEY PRESS STATE: INITIALIZE THE KEYBOARD STATE ARRAY TO ALL UNPRESSED*/
void			init_key_press_state(t_game *game);

#endif
