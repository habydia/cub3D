/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:57:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 12:20:17 by lebroue          ###   ########.fr       */
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

/*INIT PLAYER DIRECTION: SET INITIAL PLAYER VIEW DIRECTION FROM SPAWN ORIENTATION*/
void						init_player_direction(t_game *game,
								t_file_data *data);

/* ========== PLAYER UPDATE & MOVEMENT ========== */

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////PLAYER UPDATE & MOVEMENT//////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*UPDATE PLAYER: HANDLE ALL PLAYER INPUT, MOVEMENT AND ROTATION EACH FRAME*/
void						update_player(t_game *game);

#endif /* PLAYER_H */
