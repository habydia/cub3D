/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:03 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 13:58:00 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

typedef struct s_game t_game;

int render(t_game *game);
void draw_floor_and_ceiling(t_game *game);
void put_pixel(t_game *game, int x, int y, int color);
int rgb_to_int(int r, int g, int b);

#endif /* RENDER_H */

