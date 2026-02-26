/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:27 by hadia             #+#    #+#             */
/*   Updated: 2026/02/26 15:43:14 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# include "../libft/libft.h"
typedef struct s_list	t_list;
typedef struct s_game	t_game;

typedef struct s_file_data
{
	// Path to north wall texture
	char				*north_texture;
	// Path to south wall texture
	char				*south_texture;
	// Path to west wall texture
	char				*west_texture;
	// Path to east wall texture
	char				*east_texture;
	// Flag: north texture parsed
	int					north_set;
	// Flag: south texture parsed
	int					south_set;
	// Flag: west texture parsed
	int					west_set;
	// Flag: east texture parsed
	int					east_set;
	// Floor color RGB components [R, G, B]
	int					floor_color[3];
	// Ceiling color RGB components [R, G, B]
	int					ceiling_color[3];
	// Flag: floor color parsed
	int					floor_set;
	// Flag: ceiling color parsed
	int					ceiling_set;
	// Player starting X position on map (in cells)
	int					player_pos_x;
	// Player starting Y position on map (in cells)
	int					player_pos_y;
	// Player starting direction (N/S/E/W)
	char				player_dir;
	// 2D array of map (rows of cells)
	char				**map;
	// Map width in cells
	int					map_width;
	// Map height in cells
	int					map_height;
	// Flag: map parsing has started
	int					has_map_started;
	// Linked list of map lines (for parsing phase)
	t_list				*map_lines;
}						t_file_data;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////FILE PARSING/////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*PARSING ARGS: PARSE COMMAND LINE ARGUMENTS AND VALIDATE FILE EXTENSION*/
int						parsing_args(t_file_data *data, char **argv);

/*READ FILE: READ AND PROCESS CONFIGURATION FILE LINE BY LINE*/
int						read_file(char *file_path, t_file_data *data);

/*PROCESS LINE: PARSE A SINGLE LINE AND ROUTE TO APPROPRIATE HANDLER*/
int						process_line(char *line, t_file_data *data);

/*PROCESS TEXTURES: PARSE TEXTURE CONFIGURATION LINES (NO, SO, WE, EA)*/
int						process_textures(char *line, t_file_data *data);

/*PROCESS COLORS: PARSE FLOOR AND CEILING COLOR CONFIGURATION LINES*/
int						process_colors(char *line, t_file_data *data);

/*PROCESS MAP: PARSE MAP LAYOUT LINES AND BUILD GAME MAP*/
int						process_map(char *line, t_file_data *data);

/*LSTMAP TO CHARMAP: CONVERT LINKED LIST MAP REPRESENTATION TO 2D ARRAY*/
int						lstmap_to_charmap(t_file_data *data);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////DATA VALIDATION/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*VALIDATE PLAYER: CHECK THAT EXACTLY ONE PLAYER SPAWN POINT EXISTS*/
int						validate_player(t_file_data *data);

/*VALIDATE CHARACTERS: VERIFY THAT MAP CONTAINS ONLY VALID CHARACTERS*/
int						validate_characters(t_file_data *data);

/*VALIDATE BORDERS ONLY: ENSURE ALL MAP BORDERS ARE WALLS*/
int						validate_borders_only(t_file_data *data);

/*VALIDATE TOP BOTTOM: CHECK THAT TOP AND BOTTOM MAP ROWS ARE SOLID WALLS*/
int						validate_top_bottom(t_file_data *data);

/*VALIDATE LEFT RIGHT: CHECK THAT LEFT AND RIGHT MAP COLUMNS ARE SOLID WALLS*/
int						validate_left_right(t_file_data *data);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////UTILITY FUNCTIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*PARSE RGB: EXTRACT AND VALIDATE RGB COLOR VALUES FROM STRING*/
int						parse_rgb(char *str, int color[3]);

/*EXTRACT TEXTURE: PARSE AND VALIDATE TEXTURE FILE PATH FROM CONFIGURATION*/
int						extract_texture(char *path, char **texture);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////MEMORY CLEANUP///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*FREE FILE DATA: DEALLOCATE ALL DYNAMICALLY ALLOCATED FILE DATA MEMORY*/
void					free_file_data(t_file_data *data);

/*FREE GAME: DEALLOCATE ALL GAME RESOURCES AND CLEANUP BEFORE EXIT*/
void					free_game(t_game *game);

#endif /* PARSING_H */
