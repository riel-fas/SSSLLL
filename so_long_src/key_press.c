/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:38:04 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/18 14:20:33 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_player(t_game *game, int dx, int dy)
{
    int new_x = game->map.player_x + dx;
    int new_y = game->map.player_y + dy;

    // Update player direction based on movement
    if (dx == 1 && dy == 0)
        game->player_direction = DIR_RIGHT;
    else if (dx == -1 && dy == 0)
        game->player_direction = DIR_LEFT;
    else if (dx == 0 && dy == -1)
        game->player_direction = DIR_UP;
    else if (dx == 0 && dy == 1)
        game->player_direction = DIR_DOWN;

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

    // Update the rendering (much more efficient than redrawing everything)
    update_render_map(game);

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

void render_map(t_game *game)
{
    int x;
    int y;

    // Clear the screen (optional, depending on your MLX42 setup)
    // mlx_close_window(game->mlx, game->win);

    // Loop through the map grid
    y = 0;
    while (y < game->map.height)
    {
        x = 0;
        while (x < game->map.width)
        {
            // Calculate pixel coordinates
            int pixel_x = x * TILE_SIZE;
            int pixel_y = y * TILE_SIZE;

            // Draw floor first (background)
            mlx_image_to_window(game->mlx, game->floor_img, pixel_x, pixel_y);

            // Draw other tiles based on the map grid
            if (game->map.grid[y][x] == '1')
                mlx_image_to_window(game->mlx, game->wall_img, pixel_x, pixel_y);
            else if (game->map.grid[y][x] == 'P')
                mlx_image_to_window(game->mlx, game->player_img, pixel_x, pixel_y);
            else if (game->map.grid[y][x] == 'C')
                mlx_image_to_window(game->mlx, game->collectible_img, pixel_x, pixel_y);
            else if (game->map.grid[y][x] == 'E')
                mlx_image_to_window(game->mlx, game->exit_img, pixel_x, pixel_y);

            x++;
        }
        y++;
    }

    // Debug print
    printf("Map rendered successfully.\n");
}


// void render_map(t_game *game)
// {
//     int x, y;

//     // First, add all floor tiles to window
//     for (y = 0; y < game->map.height; y++) {
//         for (x = 0; x < game->map.width; x++) {
//             mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
//         }
//     }
//     printf("Floor tiles rendered successfully.\n");

//     // Then add wall, collectible, exit, and player tiles
//     for (y = 0; y < game->map.height; y++) {
//         for (x = 0; x < game->map.width; x++) {
//             if (game->map.grid[y][x] == '1') {
//                 mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->wall_count++;
//             } else if (game->map.grid[y][x] == 'C') {
//                 mlx_image_to_window(game->mlx, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->collectible_count++;
//             } else if (game->map.grid[y][x] == 'E') {
//                 mlx_image_to_window(game->mlx, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->exit_count++;
//             }
//         }
//     }
//     printf("Walls, collectibles, and exit rendered successfully.\n");

//     // Add all directional player sprites but make only one visible
//     mlx_image_to_window(game->mlx, game->player_down, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_up, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_left, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_right, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);

//     // Only make the current direction visible
//     game->player_down->instances[0].enabled = (game->player_direction == DIR_DOWN);
//     game->player_up->instances[0].enabled = (game->player_direction == DIR_UP);
//     game->player_left->instances[0].enabled = (game->player_direction == DIR_LEFT);
//     game->player_right->instances[0].enabled = (game->player_direction == DIR_RIGHT);

//     printf("Player sprites rendered successfully.\n");

//     printf("Map initialized with %d walls, %d collectibles, %d exits\n",
//            game->wall_count, game->collectible_count, game->exit_count);



// 	printf("Rendering player at (%d, %d)\n", game->map.player_x, game->map.player_y); // Debug print
// 	mlx_image_to_window(game->mlx, game->player_down, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
// 	mlx_image_to_window(game->mlx, game->player_up, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
// 	mlx_image_to_window(game->mlx, game->player_left, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
// 	mlx_image_to_window(game->mlx, game->player_right, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);

// // Only make the current direction visible
// 	game->player_down->instances[0].enabled = (game->player_direction == DIR_DOWN);
// 	game->player_up->instances[0].enabled = (game->player_direction == DIR_UP);
// 	game->player_left->instances[0].enabled = (game->player_direction == DIR_LEFT);
// 	game->player_right->instances[0].enabled = (game->player_direction == DIR_RIGHT);

// 	printf("Player sprites rendered successfully.\n");
// }


// void render_map(t_game *game)
// {
//     int x, y;


// 	for (int y = 0; y < game->map.height; y++) {
//         for (int x = 0; x < game->map.width; x++) {
//             if (mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//                 exit_with_error("ERROR: Failed to render floor tile.");
//             if (game->map.grid[y][x] == '1') {
//                 if (mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//                     exit_with_error("ERROR: Failed to render wall tile.");
//             }
//             // Repeat for other tiles (collectible, exit, player, etc.)
//         }
//     }
//     // First, add all floor tiles to window
//     // for (y = 0; y < game->map.height; y++) {
//     //     for (x = 0; x < game->map.width; x++) {
//     //         if (mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//     //             exit_with_error("ERROR: Failed to render floor tile.");
//     //     }
//     // }
//     // printf("Floor tiles rendered successfully.\n");

//     // Then add wall, collectible, exit, and player tiles
//     for (y = 0; y < game->map.height; y++) {
//         for (x = 0; x < game->map.width; x++) {
//             if (game->map.grid[y][x] == '1') {
//                 if (mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//                     exit_with_error("ERROR: Failed to render wall tile.");
//             } else if (game->map.grid[y][x] == 'C') {
//                 if (mlx_image_to_window(game->mlx, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//                     exit_with_error("ERROR: Failed to render collectible tile.");
//             } else if (game->map.grid[y][x] == 'E') {
//                 if (mlx_image_to_window(game->mlx, game->exit_img, x * TILE_SIZE, y * TILE_SIZE) < 0)
//                     exit_with_error("ERROR: Failed to render exit tile.");
//             }
//         }
//     }
//     printf("Walls, collectibles, and exit rendered successfully.\n");

//     // Render player
//     if (mlx_image_to_window(game->mlx, game->player_img, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE) < 0)
//         exit_with_error("ERROR: Failed to render player.");
//     printf("Player rendered successfully.\n");
// }











// void render_map(t_game *game)
// {
//     int x, y;

//     // First, add all floor tiles to window
//     for (y = 0; y < game->map.height; y++) {
//         for (x = 0; x < game->map.width; x++) {
//             mlx_image_to_window(game->mlx, game->floor_img, x * TILE_SIZE, y * TILE_SIZE);
//         }
//     }

//     // Then add wall, collectible, exit and player tiles
//     for (y = 0; y < game->map.height; y++) {
//         for (x = 0; x < game->map.width; x++) {
//             if (game->map.grid[y][x] == '1') {
//                 mlx_image_to_window(game->mlx, game->wall_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->wall_count++;
//             } else if (game->map.grid[y][x] == 'C') {
//                 mlx_image_to_window(game->mlx, game->collectible_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->collectible_count++;
//             } else if (game->map.grid[y][x] == 'E') {
//                 mlx_image_to_window(game->mlx, game->exit_img, x * TILE_SIZE, y * TILE_SIZE);
//                 game->exit_count++;
//             }
//         }
//     }

//     // Add all directional player sprites but make only one visible
//     mlx_image_to_window(game->mlx, game->player_down, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_up, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_left, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);
//     mlx_image_to_window(game->mlx, game->player_right, game->map.player_x * TILE_SIZE, game->map.player_y * TILE_SIZE);

//     // Only make the current direction visible
//     game->player_down->instances[0].enabled = (game->player_direction == DIR_DOWN);
//     game->player_up->instances[0].enabled = (game->player_direction == DIR_UP);
//     game->player_left->instances[0].enabled = (game->player_direction == DIR_LEFT);
//     game->player_right->instances[0].enabled = (game->player_direction == DIR_RIGHT);

//     printf("Map initialized with %d walls, %d collectibles, %d exits\n",
//            game->wall_count, game->collectible_count, game->exit_count);
// }

void update_render_map(t_game *game)
{
    int i = 0;
    int x, y;

    // Update player sprites based on direction
    update_player_sprite(game);

    // Update collectibles - hide collected ones
    i = 0;
    for (y = 0; y < game->map.height; y++) {
        for (x = 0; x < game->map.width; x++) {
            if (game->map.grid[y][x] == 'C' && i < game->collectible_count) {
                game->collectible_img->instances[i].enabled = true;
                i++;
            }
        }
    }

    // Disable collected collectibles
    while (i < game->collectible_count) {
        game->collectible_img->instances[i].enabled = false;
        i++;
    }
}


void game_loop(void *param)
{
    t_game *game = (t_game *)param;
    static int last_move_time = 0;
    int current_time;

    // Get current time
    current_time = mlx_get_time() * 1000; // Convert to milliseconds

    // Process input only if enough time has passed (100ms)
    if (current_time - last_move_time < 100)
        return;

    // Handle key inputs (one at a time with priority)
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
        mlx_close_window(game->mlx);
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP)) {
        move_player(game, 0, -1); // Move up
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
        move_player(game, 0, 1); // Move down
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT)) {
        move_player(game, -1, 0); // Move left
        last_move_time = current_time;
    }
    else if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)) {
        move_player(game, 1, 0); // Move right
        last_move_time = current_time;
    }

    // No need to call render_map here - we update visuals on movement
}


// void game_loop(void *param)
// {
//     t_game *game = (t_game *)param;
//     static int last_move_time = 0;
//     int current_time;

//     // Get current time
//     current_time = mlx_get_time() * 1000; // Convert to milliseconds

//     // Update player animation
//     game->player_animation_timer += current_time - last_move_time;
//     if (game->player_animation_timer > 100) { // Change frame every 100ms
//         game->player_current_frame = (game->player_current_frame + 1) % 4; // Cycle through 4 frames
//         game->player_animation_timer = 0;
//         update_player_sprite(game); // Update the player sprite
//     }

//     // Update collectible animation
//     game->collectible_animation_timer += current_time - last_move_time;
//     if (game->collectible_animation_timer > 100) { // Change frame every 100ms
//         game->collectible_current_frame = (game->collectible_current_frame + 1) % 4; // Cycle through 4 frames
//         game->collectible_animation_timer = 0;
//         update_collectible_sprites(game); // Update the collectible sprites
//     }

//     // Handle key inputs (one at a time with priority)
//     if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE)) {
//         mlx_close_window(game->mlx);
//     }
//     else if (mlx_is_key_down(game->mlx, MLX_KEY_W) || mlx_is_key_down(game->mlx, MLX_KEY_UP)) {
//         move_player(game, 0, -1); // Move up
//         last_move_time = current_time;
//     }
//     else if (mlx_is_key_down(game->mlx, MLX_KEY_S) || mlx_is_key_down(game->mlx, MLX_KEY_DOWN)) {
//         move_player(game, 0, 1); // Move down
//         last_move_time = current_time;
//     }
//     else if (mlx_is_key_down(game->mlx, MLX_KEY_A) || mlx_is_key_down(game->mlx, MLX_KEY_LEFT)) {
//         move_player(game, -1, 0); // Move left
//         last_move_time = current_time;
//     }
//     else if (mlx_is_key_down(game->mlx, MLX_KEY_D) || mlx_is_key_down(game->mlx, MLX_KEY_RIGHT)) {
//         move_player(game, 1, 0); // Move right
//         last_move_time = current_time;
//     }

//     // No need to call render_map here - we update visuals on movement
// }
