/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:55:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 19:05:05 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLLISION_BONUS_H
# define COLLISION_BONUS_H

typedef struct s_game	t_game;

///////////////////////////////////////////////////////////////////////////////
////////////////////////////WALL COLLISIONS//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*IS WALL COLLISION: CHECK IF NEW POSITION HITS A WALL ('1' IN MAP)*/
int						is_wall_collision(t_game *game, double new_x,
							double new_y);

#endif /* COLLISION_BONUS_H */
