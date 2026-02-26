/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:58:22 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 15:43:14 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

typedef struct s_game	t_game;

typedef struct s_pixel_square
{
	// Screen X coordinate where square starts
	int					screen_start_x;
	// Screen Y coordinate where square starts
	int					screen_start_y;
	// Size of the square in pixels (width and height)
	int					square_size;
	// Color to fill the square with (ARGB format)
	int					color;
}						t_pixel_square;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////MINIMAP RENDERING///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*DRAW MINIMAP: RENDER A REAL-TIME MINIMAP DISPLAY OF THE GAME MAP AND PLAYER*/
void					draw_minimap(t_game *game);

#endif /* MINIMAP_BONUS_H */
