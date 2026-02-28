/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:32 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/26 21:22:29 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYBOARD_H
# define KEYBOARD_H

typedef struct s_game	t_game;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////KEYBOARD INPUT/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*KEY PRESS: HANDLE KEY PRESS EVENT AND UPDATE GAME STATE*/
int						key_press(int keycode, t_game *game);

/*KEY RELEASE: HANDLE KEY RELEASE EVENT AND UPDATE GAME STATE*/
int						key_release(int keycode, t_game *game);

/*KEY UTILITIES: MOVEMENT AND ARROW HANDLERS*/
void					handle_movement_key(int keycode);
void					handle_arrow_key(int keycode);
void					handle_movement_release(int keycode);
void					handle_arrow_release(int keycode);

#endif
