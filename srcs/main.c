#include "../includes/cub3d.h"

void init_game(t_game *game, t_file_data *data)
{
    game->data = data;
    game->mlx = NULL;
    game->win = NULL;
    
    // Initialiser la position du joueur (conversion int vers double + 0.5 pour centrer)
    game->player_x = data->player_x + 0.5;
    game->player_y = data->player_y + 0.5;
    
    // Initialiser la direction selon player_dir
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
    
    // Initialiser l'état des touches
    memset(game->keys, 0, sizeof(game->keys));
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

int render(t_game *game)
{
    // Mettre à jour la position du joueur selon les touches pressées
    update_player(game);
    
    // Dessiner la carte 2D (minimap)
    int map_scale = 20; // 20 pixels par cellule
    int y, x;
    for (y = 0; y < game->data->map_height; y++)
    {
        for (x = 0; x < game->data->map_width; x++)
        {
            int color = (game->data->map[y][x] == '1') ? 0xFFFFFF : 0x000000; // Blanc pour murs, noir pour vide
            int py, px;
            for (py = 0; py < map_scale; py++)
            {
                for (px = 0; px < map_scale; px++)
                {
                    mlx_pixel_put(game->mlx, game->win, x * map_scale + px, y * map_scale + py, color);
                }
            }
        }
    }
    
    // Dessiner le joueur (carré rouge)
    int player_px = (int)(game->player_x * map_scale);
    int player_py = (int)(game->player_y * map_scale);
    for (int i = -3; i <= 3; i++)
    {
        for (int j = -3; j <= 3; j++)
        {
            mlx_pixel_put(game->mlx, game->win, player_px + i, player_py + j, 0xFF0000);
        }
    }
    
    // Ici viendra le code de raycasting pour dessiner la vue 3D
    
    return (0);
}

int ft_open_window(t_file_data *data)
{
    t_game game;
    
    init_game(&game, data);
    
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        printf("Failed to initialize MLX\n");
        return (1);
    }
    game.win = mlx_new_window(game.mlx, 800, 600, "Cub3D");
    if (!game.win)
    {
        printf("Failed to create window\n");
        return (1);
    }
    
    // Charger les textures
    load_textures(&game, data);
    
    // Configurer les hooks pour les événements
    mlx_hook(game.win, 2, 1L<<0, key_press, &game);      // Touche pressée
    mlx_hook(game.win, 3, 1L<<1, key_release, &game);    // Touche relâchée
    mlx_hook(game.win, 17, 0L, close_window, &game);     // Fermeture fenêtre (croix)
    mlx_hook(game.win, 15, 1L<<16, minimize_window, NULL); // Réduction
    mlx_hook(game.win, 22, 1L<<18, maximize_window, NULL); // Redimensionnement
    
    // Configurer la boucle de rendu
    mlx_loop_hook(game.mlx, (int (*)(void *))render, &game);
    
    mlx_loop(game.mlx);
    return (0);
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