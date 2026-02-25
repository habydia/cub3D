/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:02:51 by hadia             #+#    #+#             */
/*   Updated: 2026/02/25 12:18:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H

# define TEXTURES_H
# include "../libft/libft.h"
# include "parsing.h"

typedef struct s_file_data	t_file_data;
typedef struct s_game		t_game;

typedef struct s_wall_texture
{
	void					*image_ptr;
	char					*pixel_buffer;
	int						width;
	int						height;
	int						bits_per_pixel;
	int						bytes_per_scanline;
	int						byte_order;
}							t_wall_texture;

typedef struct s_texture_load_buffers
{
	// Pointers to individual texture fields in s_textures (for temp loading)
	void **image_ptr;  // Pointer to MLX image (void*)
	char **buffer_ptr; // Pointer to pixel buffer (char*)
	int *width_ptr;    // Pointer to texture width
	int *height_ptr;   // Pointer to texture height
	int *line_len_ptr; // Pointer to bytes per scanline
	int *bpp_ptr;      // Pointer to bits per pixel
	int *endian_ptr;   // Pointer to byte order
}							t_texture_load_buffers;

typedef struct s_textures
{
	// Global texture dimensions
	int						global_width;
	int						global_height;

	// Individual wall textures (consolidated using t_wall_texture)
	t_wall_texture			north;
	t_wall_texture			south;
	t_wall_texture			east;
	t_wall_texture			west;

	// Legacy fields for backward compatibility during refactoring
	void					*north_img;
	void					*south_img;
	void					*west_img;
	void					*east_img;
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

///////////////////////////////////////////////////////////////////////////////
///////////////////////TEXTURE LOADING & MANAGEMEN/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*LOAD TEXTURE: Load all textures from file_data and synchronize them with t_wall_texture structures */
void						load_textures(t_game *game, t_file_data *data);

/*LOAD TEXTURE BY FACE: LOAD A SINGLE TEXTURE FILE (.xpm) FOR A SPECIFIC WALL FACE (N/S/E/W)*/
void						load_texture_by_face(t_game *game, char *path,
								char face);

///////////////////////////////////////////////////////////////////////////////
///////////////////////TEXTURE POINTER ACCESSORS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*GET NORTH PTRS: GET AND INITIALIZE TEXTURE DATA POINTERS FOR THE NORTH WALL*/
void						get_north_ptrs(t_game *game,
								t_texture_load_buffers *tex);

/*GET SOUTH PTRS: GET AND INITIALIZE TEXTURE DATA POINTERS FOR THE SOUTH WALL*/
void						get_south_ptrs(t_game *game,
								t_texture_load_buffers *tex);

/*GET EAST PTRS: GET AND INITIALIZE TEXTURE DATA POINTERS FOR THE EAST WALL*/
void						get_east_ptrs(t_game *game,
								t_texture_load_buffers *tex);

/*GET WEST PTRS: GET AND INITIALIZE TEXTURE DATA POINTERS FOR THE WEST WALL*/
void						get_west_ptrs(t_game *game,
								t_texture_load_buffers *tex);

/*GET TEXTURE PTRS: DISPATCHER FUNCTION
	- ROUTE TO CORRECT WALL-SPECIFIC POINTER GETTER (N/S/E/W)*/
void						get_texture_ptrs(t_game *game, char face,
								t_texture_load_buffers *tex);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////CLEANUP & DEALLOCATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*FREE TEXTURES: FREE ALL LOADED TEXTURES AND DESTROY MLX IMAGE POINTERS*/
void						free_textures(t_game *game);

#endif /* TEXTURES_H */
