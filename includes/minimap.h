/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:58:22 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/21 13:58:23 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

typedef struct s_game t_game;

typedef struct s_draw_case
{
    int x;
    int y;
    int scale;
    int color;
} t_draw_case;

void draw_minimap(t_game *game);

#endif /* MINIMAP_H */
