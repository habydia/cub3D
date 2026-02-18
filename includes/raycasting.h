/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:54:29 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 21:02:18 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

typedef struct s_game	t_game;
typedef struct s_ray
{
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;

	int					map_x;
	int					map_y;

	double				side_dist_x;
	double				side_dist_y;

	double				delta_dist_x;
	double				delta_dist_y;

	double				perp_wall_dist;

	int					step_x;
	int					step_y;
	int					hit;
	int side; // 0 = x, 1 = y
}						t_ray;

void					raycasting(t_game *game);
int						rgb_to_int(int r, int g, int b);
void					put_pixel(struct s_game *game, int x, int y, int color);
void					init_game(t_game *game, t_file_data *data);
int						key_press(int keycode, t_game *game);
int						key_release(int keycode, t_game *game);

int						close_window(t_game *game);
int						minimize_window(void *param);
int						maximize_window(void *param);

void					update_player(t_game *game);
int						render(t_game *game);
int						ft_open_window(t_file_data *data);


void draw_player_red_minimap(t_game *game, int map_scale_for_pixel);

void	init_player_position(t_game *game, t_file_data *data);
void	init_player_direction_north_south(t_game *game, t_file_data *data);
void	init_player_direction_east_west(t_game *game, t_file_data *data);
void	init_player_direction(t_game *game, t_file_data *data);
#endif