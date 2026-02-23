/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:54:29 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 18:43:01 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

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
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	double				perp_wall_dist;
	int					wall_dir;
}						t_ray;

typedef struct s_draw_params
{
	char				*tex_data;
	int					tex_w;
	int					tex_height;
	int					line_len;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				step;
	double				tex_pos;
}						t_draw_params;

void					raycasting(t_game *game);
void					init_ray(t_game *game, t_ray *ray, int x, int w);
void					calculate_step(t_game *game, t_ray *ray);
void					perform_dda(t_game *game, t_ray *ray);
void					calculate_wall_distance(t_game *game, t_ray *ray);
char					get_wall_face(t_game *game, t_ray *ray);
void					draw_vertical_line(t_game *game, t_ray *ray, int x,
							int h);

#endif /* RAYCASTING_H */
