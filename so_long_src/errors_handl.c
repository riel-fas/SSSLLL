/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:49:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/18 10:45:16 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	errors()

void free_game(t_game *game)
{
    int i;

    // Free player animation frames
    if (game->player_down_frames) {
        for (i = 0; i < 4; i++) {
            if (game->player_down_frames[i])
                mlx_delete_image(game->mlx, game->player_down_frames[i]);
        }
        free(game->player_down_frames);
    }
    if (game->player_up_frames) {
        for (i = 0; i < 4; i++) {
            if (game->player_up_frames[i])
                mlx_delete_image(game->mlx, game->player_up_frames[i]);
        }
        free(game->player_up_frames);
    }
    if (game->player_left_frames) {
        for (i = 0; i < 4; i++) {
            if (game->player_left_frames[i])
                mlx_delete_image(game->mlx, game->player_left_frames[i]);
        }
        free(game->player_left_frames);
    }
    if (game->player_right_frames) {
        for (i = 0; i < 4; i++) {
            if (game->player_right_frames[i])
                mlx_delete_image(game->mlx, game->player_right_frames[i]);
        }
        free(game->player_right_frames);
    }

    // Free collectible animation frames
    if (game->collectible_frames) {
        for (i = 0; i < 4; i++) {
            if (game->collectible_frames[i])
                mlx_delete_image(game->mlx, game->collectible_frames[i]);
        }
        free(game->collectible_frames);
    }

    // Free map grid
    if (game->map.grid) {
        i = 0;
        while (i < game->map.height) {
            if (game->map.grid[i])
                free(game->map.grid[i]);
            i++;
        }
        free(game->map.grid);
    }

    // Free other MLX images (walls, floor, exit, etc.)
    if (game->wall_img) mlx_delete_image(game->mlx, game->wall_img);
    if (game->floor_img) mlx_delete_image(game->mlx, game->floor_img);
    if (game->exit_img) mlx_delete_image(game->mlx, game->exit_img);

    // Free MLX instance
    if (game->mlx) mlx_terminate(game->mlx);
}

// void free_game(t_game *game)
// {
//     int i;

//     if (game->map.grid)
//     {
//         i = 0;
//         while (i < game->map.height)
//         {
//             if (game->map.grid[i])
//                 free(game->map.grid[i]);
//             i++;
//         }
//         free(game->map.grid);
//     }
// }

void exit_with_error(char *message)
{
    write(2, message, ft_strlen(message));
    write(2, "\n", 1);
    exit(EXIT_FAILURE);
}

int handle_window_close(t_game *game)
{
    free_game(game); // Free allocated memory
    exit(0);
    return (0);
}
