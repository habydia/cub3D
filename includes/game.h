/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:21:14 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 18:24:12 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "mlx.h"
# include "parsing.h"
# include "textures.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *img_data;
    int     bpp;
    int     line_len;
    int     endian;

    t_file_data *data;
    t_textures textures;

    double  player_x;
    double  player_y;
    double  player_dir_x;
    double  player_dir_y;
    double  plane_x;
    double  plane_y;

    int     keys[65536];
}               t_game;

/* Prototypes */
void    init_game(t_game *game, t_file_data *data);
void    init_data_map(t_game *game, t_file_data *data);
void    init_key_press_state(t_game *game);
void    init_player_position(t_game *game, t_file_data *data);
void    init_player_direction(t_game *game, t_file_data *data);

#endif
