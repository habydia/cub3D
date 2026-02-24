/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:35:51 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/23 23:01:11 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_game *game)
{
	printf("Closing window...\n");
	free_game(game);
	exit(0);
	return (0);
}

int	minimize_window(void *param)
{
	(void)param;
	printf("Window minimized\n");
	return (0);
}

int	maximize_window(void *param)
{
	(void)param;
	printf("Window maximized\n");
	return (0);
}
