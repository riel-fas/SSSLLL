/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 14:59:59 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	into_game(t_game *game)
// {
// 	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", true);
// 	// if (!game->mlx)
// 		// return (0);
// 	mlx_loop(game->mlx);



// }

void init_game(t_game *game)
{
    game->mlx = mlx_init(game->map.width * TILE_SIZE, game->map.height * TILE_SIZE, "so_long", false);
    if (!game->mlx)
        exit_with_error("ERROR: Failed to initialize MLX.");

    load_assets(game);

    game->moves = 0;

    // Set up hooks
    mlx_key_hook(game->mlx, handle_keypress, game); // Key press event
    // mlx_close_hook(game->mlx, handle_window_close, game); // Window close event

    // Debug print
    printf("Game initialized successfully.\n");
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        printf("Usage: %s map_file.ber\n", argv[0]);
        return (1);
    }

    // Parse the map
    if (!parse_map(&game, argv[1]))
    {
        printf("Map parsing failed\n");
        return (1);
    }

    // Initialize the game
    init_game(&game);

    // Start the game loop
    mlx_loop(game.mlx);

    return (0);
}
