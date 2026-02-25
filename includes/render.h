/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:03 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 12:25:26 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "minimap.h"

typedef struct s_game	t_game;

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////MAIN RENDERING/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*RENDER: MAIN RENDERING LOOP - UPDATE AND DRAW ENTIRE FRAME TO SCREEN*/
int						render(t_game *game);

/*DRAW FLOOR AND CEILING: FILL BOTTOM AND TOP SCREEN AREAS WITH FLOOR/CEILING COLORS*/
void					draw_floor_and_ceiling(t_game *game);


///////////////////////////////////////////////////////////////////////////////
//////////////////////////////PIXEL OPERATIONS///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*PUT PIXEL: WRITE A SINGLE PIXEL COLOR TO FRAMEBUFFER AT (X, Y) COORDINATES*/
void					put_pixel(t_game *game, int x, int y, int color);

/*RGB TO INT: CONVERT RGB COLOR COMPONENTS TO 32-BIT INTEGER FORMAT*/
int						rgb_to_int(int r, int g, int b);


///////////////////////////////////////////////////////////////////////////////
////////////////////////////MINIMAP RENDERING///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*GET MINIMAP COLOR: DETERMINE COLOR FOR A MAP TILE BASED ON ITS CHARACTER*/
int						get_minimap_color(char tile);

/*DRAW MINIMAP CASE: DRAW A SINGLE SQUARE OF THE MINIMAP*/
void					draw_minimap_case(t_game *game, t_pixel_square pixel);

/*DRAW MINIMAP LINE: DRAW ONE ROW OF MINIMAP SQUARES*/
void					draw_minimap_line(t_game *game, int y, int square_size);

/*DRAW PLAYER RED MINIMAP: DRAW PLAYER POSITION AS RED CIRCLE ON MINIMAP*/
void					draw_player_red_minimap(t_game *game,
							int map_scale_for_pixel);

#endif /* RENDER_H */
