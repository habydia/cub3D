/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hadia <Hadia@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 21:02:51 by hadia             #+#    #+#             */
/*   Updated: 2025/12/15 17:07:52 by hadia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

typedef struct s_game t_game;
typedef struct s_file_data t_file_data;

void free_game(t_game *game);
void free_textures(t_game *game);
void load_textures(t_game *game, t_file_data *data);

typedef struct s_textures
{
    void *north_img;
    void *south_img;
    void *west_img;
    void *east_img;
    int width;
    int height;
    char *north_data;
    char *south_data;
    char *west_data;
    char *east_data;
} t_textures;


#endif /* TEXTURES_H */     