/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 00:30:00 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/24 00:16:33 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	handle_movement_key(int keycode)
{
	if (keycode == 119)
		printf("W key pressed - Move forward\n");
	else if (keycode == 97)
		printf("A key pressed - Move left\n");
	else if (keycode == 115)
		printf("S key pressed - Move backward\n");
	else if (keycode == 100)
		printf("D key pressed - Move right\n");
}

void	handle_arrow_key(int keycode)
{
	if (keycode == 113)
		printf("Left arrow pressed - Rotate left\n");
	else if (keycode == 114)
		printf("Right arrow pressed - Rotate right\n");
	else if (keycode == 111)
		printf("Up arrow pressed\n");
	else if (keycode == 116)
		printf("Down arrow pressed\n");
}

void	handle_movement_release(int keycode)
{
	if (keycode == 119)
		printf("W key released\n");
	else if (keycode == 97)
		printf("A key released\n");
	else if (keycode == 115)
		printf("S key released\n");
	else if (keycode == 100)
		printf("D key released\n");
}

void	handle_arrow_release(int keycode)
{
	if (keycode == 113)
		printf("Left arrow released\n");
	else if (keycode == 114)
		printf("Right arrow released\n");
	else if (keycode == 111)
		printf("Up arrow released\n");
	else if (keycode == 116)
		printf("Down arrow released\n");
}
