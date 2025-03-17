/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:11 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 14:33:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_assets(t_game *game)
{
    // Load player sprite
    game->player_img = mlx_load_png("assets/player.png");
    if (!game->player_img)
        exit_with_error("ERROR: Failed to load player sprite.");

    // Load wall sprite
    game->wall_img = mlx_load_png("assets/wall.png");
    if (!game->wall_img)
        exit_with_error("ERROR: Failed to load wall sprite.");

    // Load collectible sprite
    game->collectible_img = mlx_load_png("assets/collectible.png");
    if (!game->collectible_img)
        exit_with_error("ERROR: Failed to load collectible sprite.");

    // Load exit sprite
    game->exit_img = mlx_load_png("assets/exit.png");
    if (!game->exit_img)
        exit_with_error("ERROR: Failed to load exit sprite.");

    // Load floor sprite
    game->floor_img = mlx_load_png("assets/floor.png");
    if (!game->floor_img)
        exit_with_error("ERROR: Failed to load floor sprite.");

    // Debug print
    printf("Assets loaded successfully.\n");
}
