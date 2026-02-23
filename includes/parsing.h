/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:27 by hadia             #+#    #+#             */
/*   Updated: 2026/02/21 14:15:19 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H
# include "../libft/libft.h"
typedef struct s_list	t_list;

typedef struct s_file_data
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					north_set;
	int					south_set;
	int					west_set;
	int					east_set;
	int					floor_color[3];
	int					ceiling_color[3];
	int					floor_set;
	int					ceiling_set;
	int					player_x;
	int					player_y;
	char				player_dir;
	char				**map;
	int					map_width;
	int					map_height;
	int					has_map_started;
	t_list				*map_lines;
}						t_file_data;

// Prototypes de parsing
int						parsing_args(t_file_data *data, char **argv);
int						read_file(char *file_path, t_file_data *data);
int						process_line(char *line, t_file_data *data);
int						process_textures(char *line, t_file_data *data);
int						process_colors(char *line, t_file_data *data);
int						process_map(char *line, t_file_data *data);
int						lstmap_to_charmap(t_file_data *data);

// Fonctions utilitaires pour le parsing
int						parse_rgb(char *str, int color[3]);
int						extract_texture(char *path, char **texture);
int						validate_player(t_file_data *data);
int						validate_characters(t_file_data *data);
int						validate_borders_only(t_file_data *data);
int validate_top_bottom(t_file_data *data);
int validate_left_right(t_file_data *data);

#endif /* PARSING_H */
