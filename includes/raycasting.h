/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:54:29 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 12:23:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

typedef struct s_game	t_game;

typedef struct s_ray
{
	// Ray position relative to camera
	double				ray_camera_pos_x;

	// Ray direction vector
	double				ray_dir_vector_x;
	double				ray_dir_vector_y;

	// Current grid cell the ray is in (map coordinates)
	int					in_map_grid_cell_x;
	int					in_map_grid_cell_y;

	// DDA: Distance from ray origin to next grid cell boundary
	double				ray_dda_distance_to_next_grid_cell_x;
	double				ray_dda_distance_to_next_grid_cell_y;

	// DDA: Distance between grid lines (delta distance)
	double				ray_dda_distance_between_grid_lines_x;
	double				ray_dda_distance_between_grid_lines_y;

	// DDA: Direction to increment grid cell (-1 or +1)
	int					ray_dda_grid_increment_direction_x;
	int					ray_dda_grid_increment_direction_y;

	// Collision detection
	int					ray_wall_collision_found;
	int					ray_wall_collision_is_vertical;

	// Perpendicular distance to wall (prevents fisheye effect)
	double				ray_perpendicular_distance_to_wall;

	// Wall cardinal direction (N=0, S=1, E=2, W=3)
	int					ray_wall_cardinal_direction;
}						t_ray;

typedef struct s_texture_data
{
	char				*texture_pixel_buffer;
	int					texture_width;
	int					texture_height;
	int					texture_bytes_per_scanline;
}						t_texture_data;

typedef struct s_wall_column_render_params
{
	t_texture_data		*texture;
	int					wall_column_pixel_height;
	int					screen_draw_start_y;
	int					screen_draw_end_y;
	double				texture_sample_step;
	double				texture_vertical_position;
}						t_wall_column_render_params;

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////RAYCASTING ENGINE/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*RAYCASTING: MAIN RAYCASTING LOOP - CAST RAYS AND RENDER ALL VERTICAL LINES*/
void					raycasting(t_game *game);

///////////////////////////////////////////////////////////////////////////////
////////////////////////////RAY INITIALIZATION///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*INIT RAY: INITIALIZE RAY STRUCTURE FOR A GIVEN SCREEN COLUMN (X COORDINATE)*/
void					init_ray(t_game *game, t_ray *ray, int x, int w);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////DDA ALGORITHM STEPS//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*CALCULATE STEP: COMPUTE INITIAL DDA STEP DIRECTION AND SIDE DISTANCES*/
void					calculate_step(t_game *game, t_ray *ray);

/*PERFORM DDA: EXECUTE DIGITAL DIFFERENTIAL ANALYZER TO FIND WALL COLLISION*/
void					perform_dda(t_game *game, t_ray *ray);

/*CALCULATE WALL DISTANCE: COMPUTE PERPENDICULAR DISTANCE TO WALL (FISHEYE CORRECTION)*/
void					calculate_wall_distance(t_game *game, t_ray *ray);

///////////////////////////////////////////////////////////////////////////////
//////////////////////TEXTURE MAPPING & RENDERING//////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*GET WALL FACE: DETERMINE WHICH WALL WAS HIT (N/S/E/W) BY RAY*/
char					get_wall_face(t_game *game, t_ray *ray);

/*GET TEXTURE DATA: RETRIEVE AND FILL TEXTURE DATA FOR A SPECIFIC WALL FACE*/
void					get_texture_data(t_game *game, char face,
							t_texture_data *info);

/*COMPUTE TEXTURE X: CALCULATE HORIZONTAL TEXTURE COORDINATE FOR PIXEL SAMPLING*/
int						compute_texture_x(t_game *game, t_ray *ray, int tex_w);

/*RENDER PIXEL COLUMN: DRAW A VERTICAL LINE OF PIXELS WITH TEXTURE SAMPLING*/
void					render_pixel_column(t_game *game, int x, int tex_x,
							t_wall_column_render_params params);

/*DRAW VERTICAL LINE: MAIN FUNCTION TO RENDER A COMPLETE TEXTURED WALL COLUMN*/
void					draw_vertical_line(t_game *game, t_ray *ray, int x,
							int h);

#endif /* RAYCASTING_H */
