/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 10:29:53 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main()
// {
// 	t_game game;













// }
// #include "your_header_file.h" // Replace with your actual header file name
#include <stdio.h>

// Forward declaration of functions
int parse_map(t_game *game, char *map_path);
void free_game(t_game *game);

// Simple free_game implementation for testing
void free_game(t_game *game)
{
    int i;

    if (game->map.grid)
    {
        i = 0;
        while (i < game->map.height)
        {
            if (game->map.grid[i])
                free(game->map.grid[i]);
            i++;
        }
        free(game->map.grid);
    }
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        printf("Usage: %s map_file.ber\n", argv[0]);
        return (1);
    }

    // Initialize the game structure
    game.map.grid = NULL;

    // Parse the map
    if (!parse_map(&game, argv[1]))
    {
        printf("Map parsing failed\n");
        return (1);
    }

    // Print map information
    printf("Map loaded successfully!\n");
    printf("Map dimensions: %d x %d\n", game.map.width, game.map.height);
    printf("Player position: (%d, %d)\n", game.map.player_x, game.map.player_y);
    printf("Collectibles: %d\n", game.map.collectibles);
    printf("Exit: %d\n", game.map.exit);

    // Print the map
    printf("\nMap content:\n");
    for (int i = 0; i < game.map.height; i++)
    {
        printf("%s\n", game.map.grid[i]);
    }

    // Free allocated memory
    free_game(&game);

    return (0);
}
