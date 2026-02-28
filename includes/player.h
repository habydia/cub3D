/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:57:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 21:22:39 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_game		t_game;
typedef struct s_file_data	t_file_data;

/* ========== PLAYER INITIALIZATION ========== */

///////////////////////////////////////////////////////////////////////////////
////////////////////////////PLAYER INITIALIZATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*INIT PLAYER POSITION: SET INITIAL PLAYER POSITION FROM MAP SPAWN POINT*/
void						init_player_position(t_game *game,
								t_file_data *data);

/*INIT PLAYER DIR: SET INITIAL PLAYER VIEW DIRECTION FROM SPAWN ORIENTATION*/
void						init_player_direction(t_game *game,
								t_file_data *data);

/* ========== PLAYER UPDATE & MOVEMENT ========== */

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////PLAYER UPDATE & MOVEMENT//////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*UPDATE PLAYER: HANDLE ALL PLAYER INPUT, MOVEMENT AND ROTATION EACH FRAME*/
void						update_player(t_game *game);

/* ========== WALL COLLISION DETECTION ========== */

///////////////////////////////////////////////////////////////////////////////
///////////////////////// WALL COLLISION DETECTION ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*CHECK WALL COLLISION: DETERMINES IF A GIVEN POSITION HAS A WALL*/
int							is_wall_collision(t_game *game, double new_x,
								double new_y);

#endif
