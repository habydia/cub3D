/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:43:21 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 15:42:09 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game, t_ray *ray, int x, int w)
{
	ray->camera_x = 2 * x / (double)w - 1;
	ray->ray_dir_x = game->player_dir_x + game->plane_x * ray->camera_x;
	ray->ray_dir_y = game->player_dir_y + game->plane_y * ray->camera_x;
	ray->map_x = (int)game->player_x;
	ray->map_y = (int)game->player_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	calculate_step(t_game *game, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (game->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - game->player_x)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (game->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - game->player_y)
			* ray->delta_dist_y;
	}
}

void	perform_dda(t_game *game, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->data->map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_wall_distance(t_game *game, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - game->player_x + (1 - ray->step_x)
				/ 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player_y + (1 - ray->step_y)
				/ 2) / ray->ray_dir_y;
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	int	color;
	int	y;

	line_height = (int)(h / ray->perp_wall_dist);
	draw_start = -line_height / 2 + h / 2;
	draw_end = line_height / 2 + h / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= h)
		draw_end = h - 1;
	color = 0xFFFFFF;
	if (ray->side == 1)
		color = 0xAAAAAA;
	y = draw_start;
	while (y <= draw_end)
	{
		put_pixel(game, x, y, color);
		y++;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	int		w;
	int		h;
	t_ray	ray; 

	w = 800;
	h = 600;
	x = 0;
	while (x < w)
	{
		init_ray(game, &ray, x, w);
		calculate_step(game, &ray);
		perform_dda(game, &ray);
		calculate_wall_distance(game, &ray);
		draw_vertical_line(game, &ray, x, h);
		x++;
	}
}

// void	raycasting(t_game *game)
// {
// 	int	x;
// 	int	w;
// 	int	h;
// 	int	line_height;
// 	int	draw_start;
// 	int	draw_end;
// 	int	color;
// 	int	y;
// 		t_ray ray;

// 	w = 800;
// 	h = 600;
// 	x = 0;
// 	while (x < w)
// 	{
// 		/* 1 -Calcul rayon camera */
// 		ray.camera_x = 2 * x / (double)w - 1;
// 		ray.ray_dir_x = game->player_dir_x + game->plane_x * ray.camera_x;
// 		ray.ray_dir_y = game->player_dir_y + game->plane_y * ray.camera_x;
// 		ray.map_x = (int)game->player_x;
// 		ray.map_y = (int)game->player_y;
// 		ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
// 		ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
// 		ray.hit = 0;
// 		/* 2 -Calcul step et sideDist */
// 		if (ray.ray_dir_x < 0)
// 		{
// 			ray.step_x = -1;
// 			ray.side_dist_x = (game->player_x - ray.map_x) * ray.delta_dist_x;
// 		}
// 		else
// 		{
// 			ray.step_x = 1;
// 			ray.side_dist_x = (ray.map_x + 1.0 - game->player_x)
// 				* ray.delta_dist_x;
// 		}
// 		if (ray.ray_dir_y < 0)
// 		{
// 			ray.step_y = -1;
// 			ray.side_dist_y = (game->player_y - ray.map_y) * ray.delta_dist_y;
// 		}
// 		else
// 		{
// 			ray.step_y = 1;
// 			ray.side_dist_y = (ray.map_y + 1.0 - game->player_y)
// 				* ray.delta_dist_y;
// 		}
// 		/* 3 - DDA */
// 		while (ray.hit == 0)
// 		{
// 			if (ray.side_dist_x < ray.side_dist_y)
// 			{
// 				ray.side_dist_x += ray.delta_dist_x;
// 				ray.map_x += ray.step_x;
// 				ray.side = 0;
// 			}
// 			else
// 			{
// 				ray.side_dist_y += ray.delta_dist_y;
// 				ray.map_y += ray.step_y;
// 				ray.side = 1;
// 			}
// 			if (game->data->map[ray.map_y][ray.map_x] == '1')
// 				ray.hit = 1;
// 		}
// 		/* 4  -Distance perpendiculaire */
// 		if (ray.side == 0)
// 			ray.perp_wall_dist = (ray.map_x - game->player_x + (1 - ray.step_x)
// 					/ 2) / ray.ray_dir_x;
// 		else
// 			ray.perp_wall_dist = (ray.map_y - game->player_y + (1 - ray.step_y)
// 					/ 2) / ray.ray_dir_y;
// 		/* 5 - Hauteur du mur */
// 		line_height = (int)(h / ray.perp_wall_dist);
// 		draw_start = -line_height / 2 + h / 2;
// 		draw_end = line_height / 2 + h / 2;
// 		if (draw_start < 0)
// 			draw_start = 0;
// 		if (draw_end >= h)
// 			draw_end = h - 1;
// 		/* 6 - Couleur */
// 		color = 0xFFFFFF;
// 		if (ray.side == 1)
// 			color = 0xAAAAAA;
// 		/* 7 -Dessiner colonne */
// 		y = draw_start;
// 		while (y <= draw_end)
// 		{
// 			put_pixel(game, x, y, color);
// 			y++;
// 		}
// 		x++;
// 	}
// }
