#include "../includes/cub3d.h"

// Initialisation du jeu avec position et direction
void init_game(t_game *game, t_file_data *data)
{
    memset(game, 0, sizeof(t_game)); // Initialise tout à zéro
    game->data = data;

    // Position du joueur (centré)
    game->player_x = data->player_x + 0.5;
    game->player_y = data->player_y + 0.5;

    // Direction selon player_dir
    if (data->player_dir == 'N')
    {
        game->player_dir_x = 0;
        game->player_dir_y = -1;
        game->plane_x = 0.66;
        game->plane_y = 0;
    }
    else if (data->player_dir == 'S')
    {
        game->player_dir_x = 0;
        game->player_dir_y = 1;
        game->plane_x = -0.66;
        game->plane_y = 0;
    }
    else if (data->player_dir == 'E')
    {
        game->player_dir_x = 1;
        game->player_dir_y = 0;
        game->plane_x = 0;
        game->plane_y = 0.66;
    }
    else if (data->player_dir == 'W')
    {
        game->player_dir_x = -1;
        game->player_dir_y = 0;
        game->plane_x = 0;
        game->plane_y = -0.66;
    }

    memset(game->keys, 0, sizeof(game->keys)); // touches à zéro
}

int key_press(int keycode, t_game *game)
{
    game->keys[keycode] = 1;
    if (keycode == 119) // W
        printf("Touche W pressée - Avancer\n");
    else if (keycode == 97) // A
        printf("Touche A pressée - Gauche\n");
    else if (keycode == 115) // S
        printf("Touche S pressée - Reculer\n");
    else if (keycode == 100) // D
        printf("Touche D pressée - Droite\n");
    else if (keycode == 65361) // Left arrow
        printf("Flèche gauche pressée - Rotation gauche\n");
    else if (keycode == 65363) // Right arrow
        printf("Flèche droite pressée - Rotation droite\n");
    else if (keycode == 65362) // Up arrow
        printf("Flèche haut pressée\n");
    else if (keycode == 65364) // Down arrow
        printf("Flèche bas pressée\n");
    else if (keycode == 65480) // F11
        printf("Touche F11 pressée - Maximisation\n");
    else
        printf("Touche pressée: %d\n", keycode);
    return (0);
}

int key_release(int keycode, t_game *game)
{
    game->keys[keycode] = 0;
    if (keycode == 119) // W
        printf("Touche W relâchée\n");
    else if (keycode == 97) // A
        printf("Touche A relâchée\n");
    else if (keycode == 115) // S
        printf("Touche S relâchée\n");
    else if (keycode == 100) // D
        printf("Touche D relâchée\n");
    else if (keycode == 65361) // Left arrow
        printf("Flèche gauche relâchée\n");
    else if (keycode == 65363) // Right arrow
        printf("Flèche droite relâchée\n");
    else if (keycode == 65362) // Up arrow
        printf("Flèche haut relâchée\n");
    else if (keycode == 65364) // Down arrow
        printf("Flèche bas relâchée\n");
    return (0);
}

int close_window(t_game *game)
{
    printf("Fermeture de la fenêtre...\n");
    free_game(game);
    exit(0);
    return (0);
}

int minimize_window(void *param)
{
    (void)param;
    printf("Fenêtre réduite\n");
    return (0);
}

int maximize_window(void *param)
{
    (void)param;
    printf("Fenêtre agrandie\n");
    return (0);
}

void update_player(t_game *game)
{
    double move_speed = 0.05;
    double rot_speed = 0.03;
    
    // Rotation gauche (flèche gauche ou A)
    if (game->keys[65361] || game->keys[97]) // 65361 = flèche gauche, 97 = 'a'
    {
        double old_dir_x = game->player_dir_x;
        game->player_dir_x = game->player_dir_x * cos(rot_speed) - game->player_dir_y * sin(rot_speed);
        game->player_dir_y = old_dir_x * sin(rot_speed) + game->player_dir_y * cos(rot_speed);
        double old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(rot_speed) - game->plane_y * sin(rot_speed);
        game->plane_y = old_plane_x * sin(rot_speed) + game->plane_y * cos(rot_speed);
    }
    
    // Rotation droite (flèche droite ou D)
    if (game->keys[65363] || game->keys[100]) // 65363 = flèche droite, 100 = 'd'
    {
        double old_dir_x = game->player_dir_x;
        game->player_dir_x = game->player_dir_x * cos(-rot_speed) - game->player_dir_y * sin(-rot_speed);
        game->player_dir_y = old_dir_x * sin(-rot_speed) + game->player_dir_y * cos(-rot_speed);
        double old_plane_x = game->plane_x;
        game->plane_x = game->plane_x * cos(-rot_speed) - game->plane_y * sin(-rot_speed);
        game->plane_y = old_plane_x * sin(-rot_speed) + game->plane_y * cos(-rot_speed);
    }
    
    // Mouvement avant (flèche haut ou W)
    if (game->keys[65362] || game->keys[119]) // 65362 = flèche haut, 119 = 'w'
    {
        double new_x = game->player_x + game->player_dir_x * move_speed;
        double new_y = game->player_y + game->player_dir_y * move_speed;
        if (game->data->map[(int)new_y][(int)new_x] != '1')
        {
            game->player_x = new_x;
            game->player_y = new_y;
        }
    }
    
    // Mouvement arrière (flèche bas ou S)
    if (game->keys[65364] || game->keys[115]) // 65364 = flèche bas, 115 = 's'
    {
        double new_x = game->player_x - game->player_dir_x * move_speed;
        double new_y = game->player_y - game->player_dir_y * move_speed;
        if (game->data->map[(int)new_y][(int)new_x] != '1')
        {
            game->player_x = new_x;
            game->player_y = new_y;
        }
    }
}


// Dessine la mini-map en haut à gauche
void draw_minimap(t_game *game)
{
    int map_scale = 20; // chaque case = 20x20 pixels
    int x, y, px, py;

    // Parcours de la map
    y = 0;
    while (y < game->data->map_height)
    {
        x = 0;
        while (x < game->data->map_width)
        {
            int color = (game->data->map[y][x] == '1') ? 0xFFFFFF : 0x000000; // mur ou vide

            py = 0;
            while (py < map_scale)
            {
                px = 0;
                while (px < map_scale)
                {
                    put_pixel(game, x * map_scale + px, y * map_scale + py, color);
                    px++;
                }
                py++;
            }
            x++;
        }
        y++;
    }

    // Joueur sur la mini-map
    int player_px = (int)(game->player_x * map_scale);
    int player_py = (int)(game->player_y * map_scale);

    y = -3;
    while (y <= 3)
    {
        x = -3;
        while (x <= 3)
        {
            put_pixel(game, player_px + x, player_py + y, 0xFF0000);
            x++;
        }
        y++;
    }
}



int render(t_game *game)
{
    int x, y;
    int ceiling_color, floor_color;
    // int map_scale;
    
    // 1 - Mettre à jour le joueur
    update_player(game);

    // 2 - Dessiner le sol et le plafond
    ceiling_color = rgb_to_int(game->data->ceiling_color[0],
                               game->data->ceiling_color[1],
                               game->data->ceiling_color[2]);
    floor_color = rgb_to_int(game->data->floor_color[0],
                             game->data->floor_color[1],
                             game->data->floor_color[2]);

    y = 0;
    while (y < 600)
    {
        x = 0;
        while (x < 800)
        {
            if (y < 300)
                put_pixel(game, x, y, ceiling_color);
            else
                put_pixel(game, x, y, floor_color);
            x++;
        }
        y++;
    }

    // 3 - Raycasting DDA pas encore precis
    x = 0;
    while (x < 800)
    {
        double camera_x = 2.0 * x / 800 - 1;
        double ray_dir_x = game->player_dir_x + game->plane_x * camera_x;
        double ray_dir_y = game->player_dir_y + game->plane_y * camera_x;

        int map_x = (int)game->player_x;
        int map_y = (int)game->player_y;

        double side_dist_x, side_dist_y;
        double delta_dist_x = fabs(1 / ray_dir_x);
        double delta_dist_y = fabs(1 / ray_dir_y);
        int step_x, step_y;
        int hit = 0;
        int side;

        if (ray_dir_x < 0)
        {
            step_x = -1;
            side_dist_x = (game->player_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1;
            side_dist_x = (map_x + 1.0 - game->player_x) * delta_dist_x;
        }
        if (ray_dir_y < 0)
        {
            step_y = -1;
            side_dist_y = (game->player_y - map_y) * delta_dist_y;
        }
        else
        {
            step_y = 1;
            side_dist_y = (map_y + 1.0 - game->player_y) * delta_dist_y;
        }

        // DDA
        while (hit == 0)
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += delta_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += delta_dist_y;
                map_y += step_y;
                side = 1;
            }
            if (game->data->map[map_y][map_x] == '1')
                hit = 1;
        }

        double perp_wall_dist;
        if (side == 0)
            perp_wall_dist = (map_x - game->player_x + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - game->player_y + (1 - step_y) / 2) / ray_dir_y;

        int line_height = (int)(600 / perp_wall_dist);
        int draw_start = -line_height / 2 + 300;
        int draw_end = line_height / 2 + 300;
        if (draw_start < 0)
            draw_start = 0;
        if (draw_end >= 600)
            draw_end = 599;

        // Couleur du mur avec scintillement
        int base_color = 0xAAAAAA;
        int flicker = (rand() % 50) - 25; // variation -25 à +24
        int wall_color = base_color + flicker * 0x10101; // applique variation sur R, G, B

        y = draw_start;
        while (y <= draw_end)
        {
            put_pixel(game, x, y, wall_color);
            y++;
        }

        x++;
    }

    // 4 - Mini-map
    draw_minimap(game);

    // 5 - Mettre à jour l’image sur la fenêtre
    mlx_put_image_to_window(game->mlx, game->win, game->mlx_img, 0, 0);

    return (0);
}



int ft_open_window(t_file_data *data)
{
    t_game *game;
    int endian;

    game = malloc(sizeof(t_game));
    if (!game)
        return 1;
    memset(game, 0, sizeof(t_game));

    init_game(game, data);

    game->mlx = mlx_init();
    if (!game->mlx)
    {
        free(game);
        return 1;
    }

    game->win = mlx_new_window(game->mlx, 800, 600, "Cub3D");
    if (!game->win)
    {
        free(game);
        return 1;
    }

    game->mlx_img = mlx_new_image(game->mlx, 800, 600);
    if (!game->mlx_img)
    {
        mlx_destroy_window(game->mlx, game->win);
        free(game);
        return 1;
    }

    game->img_data = mlx_get_data_addr(game->mlx_img,
                                       &game->bit_per_pixel,
                                       &game->line_len_in_octet,
                                       &endian);
    if (!game->img_data)
    {
        mlx_destroy_image(game->mlx, game->mlx_img);
        mlx_destroy_window(game->mlx, game->win);
        free(game);
        return 1;
    }

    load_textures(game, data);

    mlx_hook(game->win, 2, 1L<<0, key_press, game);
    mlx_hook(game->win, 3, 1L<<1, key_release, game);
    mlx_hook(game->win, 17, 0L, close_window, game);

    mlx_loop_hook(game->mlx, render, game);
    mlx_loop(game->mlx);

    return 0;
}



int main(int argc, char **argv)
{
    t_file_data data;
    memset(&data, 0, sizeof(t_file_data));
    
    if(argc != 2)
    {
        printf("Usage: %s <map_file>\n", argv[0]);
        return 1;
    }
    else
    {
        if (parsing_args(&data, argv) == -1)
        {
            printf("Error\nParsing failed\n");
            return 1;
        }
        else {
            printf("Parsing successful! Opening window...\n");
            ft_open_window(&data);
            return 0;
        }
    }
    return 0;
}
