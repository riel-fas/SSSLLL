/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 14:42:12 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game, int dx, int dy)
{
	int new_x = game->map.player_x + dx;
	int new_y = game->map.player_y + dy;

	// Check if the new position is within the map boundaries
	if (new_x < 0 || new_x >= game->map.width || new_y < 0 || new_y >= game->map.height)
		return; // Out of bounds

	// Check if the new position is a wall
	if (game->map.grid[new_y][new_x] == '1')
		return; // Wall collision

	// Handle collectibles
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.collected++; // Increment collected count
		game->map.grid[new_y][new_x] = '0'; // Remove collectible from the map
	}

	// Handle exit
	if (game->map.grid[new_y][new_x] == 'E')
	{
		if (game->map.collected == game->map.collectibles)
		{
			printf("You win! Moves: %d\n", game->moves + 1);
			mlx_close_window(game->mlx); // Close the game window
			return;
		}
		else
		{
			printf("Collect all collectibles before exiting!\n");
			return;
		}
	}

	// Update player position
	game->map.grid[game->map.player_y][game->map.player_x] = '0'; // Clear old position
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->map.grid[new_y][new_x] = 'P'; // Set new position

	// Increment move counter
	game->moves++;

	// Redraw the map
	render_map(game);

	// Debug print
	printf("Player moved to (%d, %d). Moves: %d\n", new_x, new_y, game->moves);
}

void handle_keypress(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    // Check if the key is pressed (not released or repeated)
    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        // Move player based on key pressed
        if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
            move_player(game, 0, -1); // Move up
        else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
            move_player(game, 0, 1);  // Move down
        else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
            move_player(game, -1, 0); // Move left
        else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
            move_player(game, 1, 0);  // Move right
        else if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(game->mlx); // Close the window
    }
}

