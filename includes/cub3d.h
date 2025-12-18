/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:30 by hadia             #+#    #+#             */
/*   Updated: 2025/12/15 17:07:52 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "../includes/textures.h"


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

typedef struct s_game
{
    void *mlx;
    void *win;
    t_file_data *data;
    t_textures textures;
    double player_x;
    double player_y;
    double player_dir_x;
    double player_dir_y;
    double plane_x;
    double plane_y;
    int keys[65536]; // État des touches (0 = relâchée, 1 = pressée)
} t_game;

int parsing_args(t_file_data *data, char **argv);
int ft_open_window(t_file_data *data);
#endif  /* CUB3D_H */