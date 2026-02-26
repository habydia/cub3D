/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:21:14 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 15:43:14 by lebroue          ###   ########.fr       */
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
	// MLX library pointer for graphics
	void		*mlx_ptr;
	// MLX window pointer
	void		*mlx_window_ptr;
	// MLX image pointer for off-screen rendering
	void		*mlx_image_ptr;
	// Pixel buffer for the image (ARGB format)
	char		*pixel_buffer;
	// Bits per pixel (typically 32)
	int			bits_for_one_pixel;
	// Bytes per scanline (pitch for memory layout)
	int			bytes_per_scanline;
	// Byte order (0=little endian, 1=big endian)
	int			byte_order;

	// Parsed file data (map, textures, colors)
	t_file_data	*data;
	// Loaded texture images
	t_textures	textures;

	// Player X position in game world
	double		player_pos_x;
	// Player Y position in game world
	double		player_pos_y;
	// Player direction vector X component
	double		player_vector_direction_x;
	// Player direction vector Y component
	double		player_vector_direction_y;
	// Camera plane vector X component (perpendicular to direction)
	double		camera_plane_x;
	// Camera plane vector Y component
	double		camera_plane_y;

	// Keyboard state array (65536 possible key codes)
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
