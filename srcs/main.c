#include "../includes/cub3d.h"

int close_window(void *param)
{
    (void)param;
    printf("Fermeture de la fenêtre...\n");
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

int key_press(int keycode, void *param)
{
    if (keycode == 65480) // F11
    {
        printf("Touche F11 pressée - Maximisation\n");
        maximize_window(param);
    }
    return (0);
}

int render(void *param)
{
    // Fonction de rendu appelée à chaque frame
    // Pour l'instant, on ne fait rien - juste un test
    (void)param;
    return (0);
}

int ft_open_window()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
    {
        printf("Failed to initialize MLX\n");
        return (1);
    }
    win = mlx_new_window(mlx, 800, 600, "Cub3D");
    if (!win)
    {
        printf("Failed to create window\n");
        return (1);
    }
    
    // Gestion de la fermeture de la fenêtre (croix rouge)
    mlx_hook(win, 17, 0L, close_window, NULL);
    
    // Gestion de la réduction de la fenêtre
    mlx_hook(win, 15, 1L<<16, minimize_window, NULL); // VisibilityNotify
    
    // Gestion des touches (F11 pour maximiser)
    mlx_hook(win, 2, 1L<<0, key_press, NULL);
    
    // Gestion du redimensionnement de la fenêtre (pour détecter la maximisation)
    mlx_hook(win, 22, 1L<<18, maximize_window, NULL); // ConfigureNotify
    
    // Configurer la boucle de rendu
    mlx_loop_hook(mlx, render, NULL);
    
    mlx_loop(mlx);
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
            ft_open_window();
            return 0;
        }
    }
    ft_open_window();
    return 0;
}