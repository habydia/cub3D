#ifndef CUB3D_H
 # define CUB3D_H


# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../includes/parsing.h"


typedef struct s_file_data
{
    char *north_texture;
    char *south_texture;
    char *west_texture;
    char *east_texture;
    int north_set;
    int south_set;
    int west_set;
    int east_set;
    int floor_color[3];
    int ceiling_color[3];
    int floor_set;
    int ceiling_set;
    char **map;
    int map_height;
    int map_width;
    int player_x;
    int player_y;
    char player_dir;
    int has_map_started;
    t_list *map_lines; // Liste temporaire pour les lignes de map
} t_file_data;

int parsing_args(t_file_data *data, char **argv);
int ft_open_window();
#endif  /* CUB3D_H */