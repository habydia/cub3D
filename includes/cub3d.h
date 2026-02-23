/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:07:30 by hadia             #+#    #+#             */
/*   Updated: 2026/02/21 18:28:35 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Librairies standards
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// MLX
# include "../minilibx-linux/mlx.h"

// Libft
# include "../libft/libft.h"

# include "../includes/minimap.h"
# include "../includes/parsing.h"
# include "../includes/player.h"
# include "../includes/raycasting.h"
# include "../includes/render.h"
# include "../includes/textures.h"
# include "../includes/window_events.h"
#include "../includes/game.h"

int	ft_open_window(t_file_data *data);

#endif /* CUB3D_H */
