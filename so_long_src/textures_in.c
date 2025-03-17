/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 15:07:01 by riel-fas         ###   ########.fr       */
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
//     game->collectible_img = mlx_load_png("textures/collectibles/coin_gold1.png");
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

#include "so_long.h"

void load_assets(t_game *game)
{
    mlx_texture_t *texture;

    // Load player sprite
    texture = mlx_load_png("textures/player/frame66.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load player sprite.");
    game->player_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load wall sprite
    texture = mlx_load_png("textures/1/wall2.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load wall sprite.");
    game->wall_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load collectible sprite
    texture = mlx_load_png("textures/collectibles/coin_gold1.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load collectible sprite.");
    game->collectible_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load exit sprite
    texture = mlx_load_png("textures/1/wall4.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load exit sprite.");
    game->exit_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Load floor sprite
    texture = mlx_load_png("textures/0/tile_004055.png");
    if (!texture)
        exit_with_error("ERROR: Failed to load floor sprite.");
    game->floor_img = mlx_texture_to_image(game->mlx, texture);
    mlx_delete_texture(texture);

    // Debug print
    printf("Assets loaded successfully.\n");
}
