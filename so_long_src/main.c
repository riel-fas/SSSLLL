/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:24:15 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 13:59:57 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	into_game(t_game *game)
{
	game->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "so_long", true);
	// if (!game->mlx)
		// return (0);
	mlx_loop(game->mlx);



}

int main(int ac, char **av)
{
	// (void)ac;
    t_game game;

    if (ac != 2)
    {
        printf("Usage: %s map_file.ber\n", av[0]);
        return (1);
    }

    // Parse the map
    if (!parse_map(&game, av[1]))
    {
        printf("Map parsing failed\n");
        return (1);
    }

    // Initialize the game
    into_game(&game);

    // Start the game loop
    mlx_loop(game.mlx);

    return (0);
}
