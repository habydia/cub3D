#include "../includes/cub3d.h"

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
    win = mlx_new_window(mlx, 800, 600, "Cub3D Window");
    if (!win)
    {
        printf("Failed to create window\n");
        return (1);
    }
    mlx_loop(mlx);
    return (0);
}

int main()
{
    ft_open_window();
    return 0;
}