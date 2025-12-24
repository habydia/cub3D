/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:26:42 by lebroue           #+#    #+#             */
/*   Updated: 2025/12/24 17:26:53 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_ray
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;

    int map_x;
    int map_y;

    double side_dist_x;
    double side_dist_y;

    double delta_dist_x;
    double delta_dist_y;

    double perp_wall_dist;

    int step_x;
    int step_y;
    int hit;
    int side; // 0 = x, 1 = y
} t_ray;
