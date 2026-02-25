/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:58:22 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 18:54:48 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

typedef struct s_game	t_game;

typedef struct s_pixel_square
{
	int					screen_start_x;
	int					screen_start_y;
	int					square_size;
	int					color;
}						t_pixel_square;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////MINIMAP RENDERING///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*DRAW MINIMAP: RENDER A REAL-TIME MINIMAP DISPLAY OF THE GAME MAP AND PLAYER*/
void					draw_minimap(t_game *game);

#endif /* MINIMAP_BONUS_H */
