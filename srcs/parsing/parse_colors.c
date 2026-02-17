/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:18:02 by hadia             #+#    #+#             */
/*   Updated: 2026/02/17 19:30:53 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	process_colors(char *line, t_file_data *data)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (parse_rgb(line + 2, data->floor_color) == 0)
		{
			data->floor_set = 1;
			return (0);
		}
		return (-1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (parse_rgb(line + 2, data->ceiling_color) == 0)
		{
			data->ceiling_set = 1;
			return (0);
		}
		return (-1);
	}
	return (1); // Pas une couleur
}

static int	parse_coma(char *str)
{
	int	i;
	int	comma_count;

	i = 0;
	comma_count = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			comma_count++;
			if (i == 0 || str[i + 1] == ',' || str[i + 1] == '\0' || (i > 0
					&& str[i - 1] == ','))
				return (-1); // Virgule en début, fin, ou consécutive
		}
		i++;
	}
	if (comma_count != 2)
		return (-1); // Pas exactement 2 virgules
	return (0);
}

// Fonction pour parser RGB
int	parse_rgb(char *str, int color[3])
{
	int		start;
	int		j;
	int		i;
	char	*num_str;

	start = 0;
	j = 0;
	i = 0;
	if (parse_coma(str) == -1)
		return (-1);
	// Maintenant parser les valeurs
	i = 0;
	j = 0;
	while (str[i] && j < 3)
	{
		if (str[i] == ',')
		{
			// Extraire la valeur de start à i-1
			num_str = ft_substr(str, start, i - start);
			if (!num_str)
				return (-1);
			color[j] = ft_atoi(num_str);
			free(num_str);
			if (color[j] < 0 || color[j] > 255)
				return (-1);
			start = i + 1;
			j++;
		}
		i++;
	}
	// Dernière valeur
	if (j < 3)
	{
		num_str = ft_substr(str, start, i - start);
		if (!num_str)
			return (-1);
		color[j] = ft_atoi(num_str);
		free(num_str);
		if (color[j] < 0 || color[j] > 255)
			return (-1);
	}
	return (0);
}
