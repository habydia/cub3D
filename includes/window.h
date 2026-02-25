/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 13:22:32 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/25 12:30:47 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

typedef struct s_game		t_game;
typedef struct s_file_data	t_file_data;

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////WINDOW MANAGEMENT///////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*FT OPEN WINDOW: CREATE AND INITIALIZE THE GAME WINDOW AND MLX INSTANCE*/
int							ft_open_window(t_file_data *data);

/*INIT MLX AND WINDOW: INITIALIZE MLX GRAPHICS AND CREATE DISPLAY WINDOW*/
int							init_mlx_and_window(t_game *game);

/*SETUP HOOKS: REGISTER ALL EVENT CALLBACKS (KEY, CLOSE, MOUSE, ETC)*/
void						setup_hooks(t_game *game);

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////WINDOW EVENTS//////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

/*CLOSE WINDOW: HANDLE WINDOW CLOSE EVENT AND CLEANUP RESOURCES*/
int							close_window(t_game *game);

/*MINIMIZE WINDOW: HANDLE WINDOW MINIMIZE EVENT*/
int							minimize_window(void *param);

/*MAXIMIZE WINDOW: HANDLE WINDOW MAXIMIZE EVENT*/
int							maximize_window(void *param);

#endif /* WINDOW_H */
