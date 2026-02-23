/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 21:39:39 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 17:53:56 by lebroue          ###   ########.fr       */
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

static char	get_wall_face(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			return ('W');
		return ('E');
	}
	else
	{
		if (ray->ray_dir_y > 0)
			return ('S');
		return ('N');
	}
}

static char	*get_texture_ptr(t_game *game, char face)
{
	if (face == 'N')
		return (game->textures.north_data);
	if (face == 'S')
		return (game->textures.south_data);
	if (face == 'E')
		return (game->textures.east_data);
	return (game->textures.west_data);
}

static int	get_width_by_face(t_game *game, char face)
{
	if (face == 'N')
		return (game->textures.north_width);
	if (face == 'S')
		return (game->textures.south_width);
	if (face == 'E')
		return (game->textures.east_width);
	return (game->textures.west_width);
}

static int	get_line_len_by_face(t_game *game, char face)
{
	if (face == 'N')
		return (game->textures.north_line_len);
	if (face == 'S')
		return (game->textures.south_line_len);
	if (face == 'E')
		return (game->textures.east_line_len);
	return (game->textures.west_line_len);
}

static int	get_tex_x(t_game *game, t_ray *ray, char face)
{
	double	wall_x;
	int		tex_x;
	int		tex_width;

	tex_width = get_width_by_face(game, face);
	if (ray->side == 0)
		wall_x = game->player_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex_width);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		tex_x = tex_width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y > 0)
		tex_x = tex_width - tex_x - 1;
	return (tex_x);
}

static int	get_height_by_face(t_game *game, char face)
{
	if (face == 'N')
		return (game->textures.north_height);
	if (face == 'S')
		return (game->textures.south_height);
	if (face == 'E')
		return (game->textures.east_height);
	return (game->textures.west_height);
}

void	draw_vertical_line(t_game *game, t_ray *ray, int x, int h)
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		y;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	char	face;
	char	*tex;
	int		color;
	int		line_len;
	int		tex_width;
	int		tex_height;

	line_height = (int)(h / ray->perp_wall_dist);
	draw_start = -line_height / 2 + h / 2;
	draw_end = line_height / 2 + h / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= h)
		draw_end = h - 1;
	face = get_wall_face(ray);
	tex = get_texture_ptr(game, face);
	line_len = get_line_len_by_face(game, face);
	tex_width = get_width_by_face(game, face);
	tex_height = get_height_by_face(game, face);
	tex_x = get_tex_x(game, ray, face);
	// Boundary check for tex_x
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= tex_width)
		tex_x = tex_width - 1;
	if (!tex)
		printf("WARNING: tex is NULL for face %c\n", face);
	else if (x == 400)
		printf("CENTER: Face %c loaded\n", face);
	step = (double)tex_height / line_height;
	tex_pos = (draw_start - h / 2 + line_height / 2) * step;
	y = draw_start;
	while (y <= draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= tex_height)
			tex_y = tex_height - 1;
		tex_pos += step;
		if (tex && tex_x >= 0 && tex_x < tex_width && tex_y >= 0
			&& tex_y < tex_height)
		{
			color = *(unsigned int *)(tex + (tex_y * line_len) + (tex_x * 4));
		}
		else
		{
			color = 0xFFFFFF;
		}
		put_pixel(game, x, y, color);
		y++;
	}
}
