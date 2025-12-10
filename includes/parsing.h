#ifndef PARSING_H
# define PARSING_H

# include "../includes/cub3d.h"

typedef struct s_file_data t_file_data;

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
#endif /* PARSING_H */