/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:57:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/03/14 00:32:50 by lebroue          ###   ########.fr       */
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

/*INIT PLAYER DIR NORTH SOUTH: SET PLAYER DIRECTION FOR NORTH/SOUTH*/
void						init_player_direction_north_south(t_game *game,
								t_file_data *data);

/*INIT PLAYER DIR EAST WEST: SET PLAYER DIRECTION FOR EAST/WEST*/
void						init_player_direction_east_west(t_game *game,
								t_file_data *data);

/* ========== PLAYER UPDATE & MOVEMENT ========== */

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////PLAYER UPDATE & MOVEMENT//////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*UPDATE PLAYER: HANDLE ALL PLAYER INPUT, MOVEMENT AND ROTATION EACH FRAME*/
void						update_player(t_game *game);

/*MOVE FORWARD W OR UP ARROW: MOVE PLAYER FORWARD WITH W OR UP ARROW KEY*/
void						move_forward_w_or_up_arrow(t_game *game,
								double move_speed);

/*MOVE BACKWARD S OR DOWN ARROW: MOVE PLAYER BACKWARD WITH S OR DOWN ARROW*/
void						move_backward_s_or_down_arrow(t_game *game,
								double move_speed);

/*MOVE LEFT A KEY: MOVE PLAYER LEFT WITH A KEY (STRAFE LEFT)*/
void						move_left_a_key(t_game *game, double move_speed);

/*MOVE RIGHT D KEY: MOVE PLAYER RIGHT WITH D KEY (STRAFE RIGHT)*/
void						move_right_d_key(t_game *game, double move_speed);

/*LEFT ROTATION ARROW: ROTATE PLAYER VIEW LEFT WITH ARROW KEY*/
void						left_rotation_arrow(t_game *game, double rot_speed);

/*RIGHT ROTATION ARROW: ROTATE PLAYER VIEW RIGHT WITH ARROW KEY*/
void						right_rotation_arrow(t_game *game,
								double rot_speed);

/* ========== WALL COLLISION DETECTION ========== */

///////////////////////////////////////////////////////////////////////////////
///////////////////////// WALL COLLISION DETECTION ////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*CHECK WALL COLLISION: DETERMINES IF A GIVEN POSITION HAS A WALL*/
int							is_wall_collision(t_game *game, double new_x,
								double new_y);

#endif
