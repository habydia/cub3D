/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:27 by hadia             #+#    #+#             */
/*   Updated: 2025/12/15 17:07:52 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/cub3d.h"

typedef struct s_file_data t_file_data;

// Structure temporaire pour les lignes de map
typedef struct s_map_line {
    char *line;
    struct s_map_line *next;
} t_map_line;


// File reading
int read_file(char *file_path, t_file_data *data);
int process_line(char *line, t_file_data *data);

// Textures
int process_textures(char *line, t_file_data *data);
int extract_texture(char *path, char **texture);
//colors
int process_colors(char *line, t_file_data *data);
int parse_rgb(char *str, int color[3]);

// Map
int process_map(char *line, t_file_data *data);
int lstmap_to_charmap(t_file_data *data);

int lstmap_to_charmap(t_file_data *data);
int validate_characters(t_file_data *data);
int validate_player(t_file_data *data);
int validate_borders_only(t_file_data *data);
int validate_top_bottom(t_file_data *data);
int validate_left_right(t_file_data *data);
#endif /* PARSING_H */