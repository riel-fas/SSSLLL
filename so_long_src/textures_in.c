/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/18 14:29:42 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void load_assets(t_game *game)
// {
//     // Load player sprite
//     game->player_img = mlx_load_png("textures/player/frame66.png");
//     if (!game->player_img)
//         exit_with_error("ERROR: Failed to load player sprite.");

//     // Load wall sprite
//     game->wall_img = mlx_load_png("textures/1/wall2.png");
//     if (!game->wall_img)
//         exit_with_error("ERROR: Failed to load wall sprite.");

//     // Load collectible sprite
//     game->collectible_img = mlx_load_png("textures/collectibles/coin_gold0.png");
//     if (!game->collectible_img)
//         exit_with_error("ERROR: Failed to load collectible sprite.");

//     // Load exit sprite
//     game->exit_img = mlx_load_png("textures/1/wall4.png");
//     if (!game->exit_img)
//         exit_with_error("ERROR: Failed to load exit sprite.");

//     // Load floor sprite
//     game->floor_img = mlx_load_png("textures/0/tile_004055.png");
//     if (!game->floor_img)
//         exit_with_error("ERROR: Failed to load floor sprite.");

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }

// #include "so_long.h"

// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // Load player sprite
//     texture = mlx_load_png("textures/player/frame66.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load player sprite.");
//     game->player_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load wall sprite
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load collectible sprite
//     texture = mlx_load_png("textures/collectibles/coin_gold1.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load collectible sprite.");
//     game->collectible_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);
// 	// game->collectible_img->enabled = false;



//     // Load exit sprite
//     texture = mlx_load_png("textures/1/wall4.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load floor sprite
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }

void load_assets(t_game *game)
{
    mlx_texture_t *texture;

    // Load player sprites for different directions (multiple frames)
    game->player_down_frames = malloc(sizeof(mlx_image_t *) * 2); // 4 frames for down animation
    for (int i = 0; i < 3; i++) {
        char path[100];
        snprintf(path, sizeof(path), "textures/player/player_down/char_rundown_%d.png", i);
        texture = mlx_load_png(path);
        if (!texture)
            exit_with_error("ERROR: Failed to load player down sprite.");
        game->player_down_frames[i] = mlx_texture_to_image(game->mlx, texture);
        mlx_delete_texture(texture);
    }

    game->player_up_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for up animation
    for (int i = 0; i < 5; i++) {
        char path[100];
        snprintf(path, sizeof(path), "textures/player/player_up/char_runup_%d.png", i);
        texture = mlx_load_png(path);
        if (!texture)
            exit_with_error("ERROR: Failed to load player up sprite.");
        game->player_up_frames[i] = mlx_texture_to_image(game->mlx, texture);
        mlx_delete_texture(texture);
    }

    game->player_left_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for left animation
    for (int i = 0; i < 5; i++) {
        char path[100];
        snprintf(path, sizeof(path), "textures/player/player_left/char_runleft_%d.png", i);
        texture = mlx_load_png(path);
        if (!texture)
            exit_with_error("ERROR: Failed to load player left sprite.");
        game->player_left_frames[i] = mlx_texture_to_image(game->mlx, texture);
        mlx_delete_texture(texture);
    }

    game->player_right_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for right animation
    for (int i = 0; i < 5; i++) {
        char path[100];
        snprintf(path, sizeof(path), "textures/player/player_right/char_runright_%d.png", i);
        texture = mlx_load_png(path);
        if (!texture)
            exit_with_error("ERROR: Failed to load player right sprite.");
        game->player_right_frames[i] = mlx_texture_to_image(game->mlx, texture);
        mlx_delete_texture(texture);
    }

    // Set initial player direction and active sprite
    game->player_direction = DIR_DOWN;
    game->player_current_frame = 0;
    game->player_animation_timer = 0;

    // Load collectible sprites (multiple frames)
    game->collectible_frames = malloc(sizeof(mlx_image_t *) * 7); // 4 frames for collectible animation
    for (int i = 0; i < 7; i++) {
        char path[100];
        snprintf(path, sizeof(path), "textures/collectibles/coin_gold%d.png", i);
        texture = mlx_load_png(path);
        if (!texture)
            exit_with_error("ERROR: Failed to load collectible sprite.");
        game->collectible_frames[i] = mlx_texture_to_image(game->mlx, texture);
        mlx_delete_texture(texture);
    }

    game->collectible_current_frame = 0;
    game->collectible_animation_timer = 0;

    // Load wall sprite
    texture = mlx_load_png("textures/1/wall2.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load wall sprite.");
    game->wall_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load floor sprite
    texture = mlx_load_png("textures/0/tile_004055.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load floor sprite.");
    game->floor_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load exit sprite
    texture = mlx_load_png("textures/1/wall4.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load exit sprite.");
    game->exit_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Initialize counters
    game->wall_count = 0;
    game->collectible_count = 0;
    game->exit_count = 0;

    // Debug print
    printf("Assets loaded successfully.\n");
}


// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // Load player sprites for different directions (multiple frames)
//     game->player_down_frames = malloc(sizeof(mlx_image_t *) * 4); // 2 frames for down animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_down/char_rundown_%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player down sprite.");
//         game->player_down_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_up_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for up animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_up/char_runup_%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player up sprite.");
//         game->player_up_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_left_frames = malloc(sizeof(mlx_image_t *) * 4); // 5 frames for left animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_left/char_runleft_%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player left sprite.");
//         game->player_left_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_right_frames = malloc(sizeof(mlx_image_t *) * 4); // 5 frames for right animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_right/char_runright_%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player right sprite.");
//         game->player_right_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     // Set initial player direction and active sprite
//     game->player_direction = DIR_DOWN;
//     game->player_current_frame = 0;
//     game->player_animation_timer = 0;

//     // Load collectible sprites (multiple frames)
//     game->collectible_frames = malloc(sizeof(mlx_image_t *) * 7); // 7 frames for collectible animation
//     for (int i = 0; i < 7; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/collectibles/coin_gold%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load collectible sprite.");
//         game->collectible_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->collectible_current_frame = 0;
//     game->collectible_animation_timer = 0;

//     // Load wall sprite
//     printf("Loading texture: textures/1/wall2.png\n"); // Debug print
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load floor sprite
//     printf("Loading texture: textures/0/tile_004055.png\n"); // Debug print
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load exit sprite
//     printf("Loading texture: textures/1/wall4.png\n"); // Debug print
//     texture = mlx_load_png("textures/1/wall4.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Initialize counters
//     game->wall_count = 0;
//     game->collectible_count = 0;
//     game->exit_count = 0;

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }

// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // Load player sprites for different directions (multiple frames)
//     game->player_down_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for down animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_down/char_rundown_%d.png", i);
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player down sprite.");
//         game->player_down_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_up_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for up animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_up/char_runup_%d.png", i);
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player up sprite.");
//         game->player_up_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_left_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for left animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_left/char_runleft_%d.png", i);
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player left sprite.");
//         game->player_left_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->player_right_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for right animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_right/char_runright_%d.png", i);
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load player right sprite.");
//         game->player_right_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     // Set initial player direction and active sprite
//     game->player_direction = DIR_DOWN;
//     game->player_current_frame = 0;
//     game->player_animation_timer = 0;

//     // Load collectible sprites (multiple frames)
//     game->collectible_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for collectible animation
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/collectibles/coin_gold%d.png", i);
//         texture = mlx_load_png(path);
//         if (!texture)
//             exit_with_error("ERROR: Failed to load collectible sprite.");
//         game->collectible_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         mlx_delete_texture(texture);
//     }

//     game->collectible_current_frame = 0;
//     game->collectible_animation_timer = 0;

//     // Load wall sprite
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load floor sprite
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load exit sprite
//     texture = mlx_load_png("textures/1/wall4.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Initialize counters
//     game->wall_count = 0;
//     game->collectible_count = 0;
//     game->exit_count = 0;

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }


// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // mlx_texture_t *texture;

//     // Load floor sprite
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->floor_img)
//         exit_with_error("ERROR: Failed to convert floor texture to image.");
//     mlx_delete_texture(texture);

//     // Repeat for other textures (wall, collectible, exit, etc.)
//     // Load floor sprite
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->floor_img)
//         exit_with_error("ERROR: Failed to convert floor texture to image.");
//     mlx_delete_texture(texture);

//     // Load wall sprite
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->wall_img)
//         exit_with_error("ERROR: Failed to convert wall texture to image.");
//     mlx_delete_texture(texture);

//     // Load collectible sprite
//     texture = mlx_load_png("textures/collectibles/coin_gold1.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load collectible sprite.");
//     game->collectible_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->collectible_img)
//         exit_with_error("ERROR: Failed to convert collectible texture to image.");
//     mlx_delete_texture(texture);

//     // Load exit sprite
//     texture = mlx_load_png("textures/1/wall4.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->exit_img)
//         exit_with_error("ERROR: Failed to convert exit texture to image.");
//     mlx_delete_texture(texture);

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }


// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // Load player sprites for different directions (multiple frames)
//     game->player_down_frames = malloc(sizeof(mlx_image_t *) * 4); // 4 frames for down animation
//     if (!game->player_down_frames) {
//         exit_with_error("ERROR: Failed to allocate memory for player down frames.");
//     }
//     for (int i = 0; i < 4; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/player/player_down/char_rundown_%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture) {
//             exit_with_error("ERROR: Failed to load player down sprite.");
//         }
//         game->player_down_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         if (!game->player_down_frames[i]) {
//             exit_with_error("ERROR: Failed to convert texture to image for player down sprite.");
//         }
//         mlx_delete_texture(texture);
//     }

//     // Repeat similar checks for other frames...

//     // Set initial player direction and active sprite
//     game->player_direction = DIR_DOWN;
//     game->player_current_frame = 0;
//     game->player_animation_timer = 0;

//     // Load collectible sprites (multiple frames)
//     game->collectible_frames = malloc(sizeof(mlx_image_t *) * 7); // 7 frames for collectible animation
//     if (!game->collectible_frames) {
//         exit_with_error("ERROR: Failed to allocate memory for collectible frames.");
//     }
//     for (int i = 0; i < 7; i++) {
//         char path[100];
//         snprintf(path, sizeof(path), "textures/collectibles/coin_gold%d.png", i);
//         printf("Loading texture: %s\n", path); // Debug print
//         texture = mlx_load_png(path);
//         if (!texture) {
//             exit_with_error("ERROR: Failed to load collectible sprite.");
//         }
//         game->collectible_frames[i] = mlx_texture_to_image(game->mlx, texture);
//         if (!game->collectible_frames[i]) {
//             exit_with_error("ERROR: Failed to convert texture to image for collectible sprite.");
//         }
//         mlx_delete_texture(texture);
//     }

//     game->collectible_current_frame = 0;
//     game->collectible_animation_timer = 0;

//     // Load wall sprite
//     printf("Loading texture: textures/1/wall2.png\n"); // Debug print
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture) {
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     }
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->wall_img) {
//         exit_with_error("ERROR: Failed to convert texture to image for wall sprite.");
//     }
//     mlx_delete_texture(texture);

//     // Load floor sprite
//     printf("Loading texture: textures/0/tile_004055.png\n"); // Debug print
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture) {
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     }
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->floor_img) {
//         exit_with_error("ERROR: Failed to convert texture to image for floor sprite.");
//     }
//     mlx_delete_texture(texture);

//     // Load exit sprite
//     printf("Loading texture: textures/1/wall4.png\n"); // Debug print
//     texture = mlx_load_png("textures/1/wall4.png");
//     if (!texture) {
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     }
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     if (!game->exit_img) {
//         exit_with_error("ERROR: Failed to convert texture to image for exit sprite.");
//     }
//     mlx_delete_texture(texture);

//     // Initialize counters
//     game->wall_count = 0;
//     game->collectible_count = 0;
//     game->exit_count = 0;

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }


// void load_assets(t_game *game)
// {
//     mlx_texture_t *texture;

//     // Load player sprites for different directions
//     texture = mlx_load_png("textures/player/player_down/char_run down_2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load player down sprite.");
//     game->player_down = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     texture = mlx_load_png("textures/player/player_up/char_run up_0.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load player up sprite.");
//     game->player_up = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     texture = mlx_load_png("textures/player/player_left/char_run left_0.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load player left sprite.");
//     game->player_left = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     texture = mlx_load_png("textures/player/player_right/char_run right_0.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load player right sprite.");
//     game->player_right = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Set initial player direction and active sprite
//     game->player_direction = DIR_DOWN;
//     game->player_img = game->player_down;

//     // Load wall sprite
//     texture = mlx_load_png("textures/1/wall2.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load wall sprite.");
//     game->wall_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load collectible sprite
//     texture = mlx_load_png("textures/collectibles/coin_gold4.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load collectible sprite.");
//     game->collectible_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load exit sprite
//     texture = mlx_load_png("textures/1/wall1.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load exit sprite.");
//     game->exit_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Load floor sprite
//     texture = mlx_load_png("textures/0/tile_004055.png");
//     if (!texture)
//         exit_with_error("ERROR: Failed to load floor sprite.");
//     game->floor_img = mlx_texture_to_image(game->mlx, texture);
//     mlx_delete_texture(texture);

//     // Initialize counters
//     game->wall_count = 0;
//     game->collectible_count = 0;
//     game->exit_count = 0;

//     // Debug print
//     printf("Assets loaded successfully.\n");
// }

void update_player_sprite(t_game *game)
{
    // Update player position for all directional sprites
    game->player_down->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_down->instances[0].y = game->map.player_y * TILE_SIZE;
    game->player_up->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_up->instances[0].y = game->map.player_y * TILE_SIZE;
    game->player_left->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_left->instances[0].y = game->map.player_y * TILE_SIZE;
    game->player_right->instances[0].x = game->map.player_x * TILE_SIZE;
    game->player_right->instances[0].y = game->map.player_y * TILE_SIZE;

    // Enable only the current direction sprite
    game->player_down->instances[0].enabled = (game->player_direction == DIR_DOWN);
    game->player_up->instances[0].enabled = (game->player_direction == DIR_UP);
    game->player_left->instances[0].enabled = (game->player_direction == DIR_LEFT);
    game->player_right->instances[0].enabled = (game->player_direction == DIR_RIGHT);
}


// void update_player_sprite(t_game *game)
// {
//     // Disable all player frames
//     for (int i = 0; i < 4; i++) {
//         if (game->player_down_frames[i]) game->player_down_frames[i]->instances[0].enabled = false;
//         if (game->player_up_frames[i]) game->player_up_frames[i]->instances[0].enabled = false;
//         if (game->player_left_frames[i]) game->player_left_frames[i]->instances[0].enabled = false;
//         if (game->player_right_frames[i]) game->player_right_frames[i]->instances[0].enabled = false;
//     }

//     // Enable the current frame based on direction
//     if (game->player_direction == DIR_DOWN) {
//         game->player_down_frames[game->player_current_frame]->instances[0].enabled = true;
//     } else if (game->player_direction == DIR_UP) {
//         game->player_up_frames[game->player_current_frame]->instances[0].enabled = true;
//     } else if (game->player_direction == DIR_LEFT) {
//         game->player_left_frames[game->player_current_frame]->instances[0].enabled = true;
//     } else if (game->player_direction == DIR_RIGHT) {
//         game->player_right_frames[game->player_current_frame]->instances[0].enabled = true;
//     }

//     // Update player position for all directional sprites
//     int x = game->map.player_x * TILE_SIZE;
//     int y = game->map.player_y * TILE_SIZE;
//     for (int i = 0; i < 4; i++) {
//         if (game->player_down_frames[i]) {
//             game->player_down_frames[i]->instances[0].x = x;
//             game->player_down_frames[i]->instances[0].y = y;
//         }
//         if (game->player_up_frames[i]) {
//             game->player_up_frames[i]->instances[0].x = x;
//             game->player_up_frames[i]->instances[0].y = y;
//         }
//         if (game->player_left_frames[i]) {
//             game->player_left_frames[i]->instances[0].x = x;
//             game->player_left_frames[i]->instances[0].y = y;
//         }
//         if (game->player_right_frames[i]) {
//             game->player_right_frames[i]->instances[0].x = x;
//             game->player_right_frames[i]->instances[0].y = y;
//         }
//     }
// }

void update_collectible_sprites(t_game *game)
{
    int i = 0;
    for (int y = 0; y < game->map.height; y++) {
        for (int x = 0; x < game->map.width; x++) {
            if (game->map.grid[y][x] == 'C' && i < game->collectible_count) {
                game->collectible_frames[game->collectible_current_frame]->instances[i].enabled = true;
                i++;
            }
        }
    }
}
