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
            printf("Parsing successful!\n");
            return 0;
        }
    }
    ft_open_window();
    return 0;
}