/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:32 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 13:58:57 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_EVENTS_H
# define WINDOW_EVENTS_H

typedef struct s_game t_game;

int close_window(t_game *game);
int minimize_window(void *param);
int maximize_window(void *param);
int key_press(int keycode, t_game *game);
int key_release(int keycode, t_game *game);

#endif /* WINDOW_EVENTS_H */

