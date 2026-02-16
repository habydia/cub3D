#ifndef RAYCASTING_H
#define RAYCASTING_H

#include "cub3d.h"


typedef struct s_game t_game;
typedef struct s_ray
{
    double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
    
	int		map_x;
	int		map_y;
	
	double	side_dist_x;
	double	side_dist_y;
    
	double	delta_dist_x;
	double	delta_dist_y;
    
	double	perp_wall_dist;
    
	int		step_x;
	int		step_y;
	int		hit;
	int side; // 0 = x, 1 = y
}			t_ray;

void raycasting(t_game *game);
int			rgb_to_int(int r, int g, int b);
void		put_pixel(struct s_game *game, int x, int y, int color);
void	init_game(t_game *game, t_file_data *data);

#endif