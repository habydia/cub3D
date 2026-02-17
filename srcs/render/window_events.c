/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:35:51 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/17 15:36:22 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_game *game)
{
	printf("Fermeture de la fenêtre...\n");
	free_game(game);
	exit(0);
	return (0);
}

int	minimize_window(void *param)
{
	(void)param;
	printf("Fenêtre réduite\n");
	return (0);
}

int	maximize_window(void *param)
{
	(void)param;
	printf("Fenêtre agrandie\n");
	return (0);
}