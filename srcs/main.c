/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebroue <lebroue@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 15:27:06 by lebroue           #+#    #+#             */
/*   Updated: 2026/02/19 15:47:11 by lebroue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_file_data data;
	ft_memset(&data, 0, sizeof(t_file_data));

	if (argc != 2)
	{
		printf("Usage: %s <map_file>\n", argv[0]);
		return (1);
	}
	else
	{
		if (parsing_args(&data, argv) == -1)
		{
			printf("error\nparsing failed\n");
			return (1);
		}
		else
		{
			printf("Parsing successful! Opening window...\n");
			ft_open_window(&data);
			return (0);
		}
	}
	return (0);
}