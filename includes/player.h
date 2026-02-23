/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:57:42 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 18:16:10 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct s_game t_game;
typedef struct s_file_data t_file_data;

void init_player_position(t_game *game, t_file_data *data);
void init_player_direction(t_game *game, t_file_data *data);
void update_player(t_game *game);

#endif /* PLAYER_H */
