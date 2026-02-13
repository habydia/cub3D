#include "../../includes/cub3d.h"

void load_textures(t_game *game, t_file_data *data)
{
    game->textures.north_img = mlx_xpm_file_to_image(game->mlx, data->north_texture, 
                                                   &game->textures.width, &game->textures.height);
    // Même chose pour S, W, E
    // Récupérer les data avec mlx_get_data_addr
}

void free_textures(t_game *game)
{
    if (game->textures.north_img)
        mlx_destroy_image(game->mlx, game->textures.north_img);
    // Free toutes les images et data
}

void free_game(t_game *game)
{
    free_textures(game);
    free_map(game->data->map, game->data->map_height);
    mlx_destroy_window(game->mlx, game->win);
    // mlx_destroy_display(game->mlx); sur Linux
}