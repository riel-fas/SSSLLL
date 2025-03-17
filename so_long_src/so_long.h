/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:18:36 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 14:30:34 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include "../MLX42/include/MLX42/MLX42.h"
// # include "/home/riad/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include <stdio.h>
#define TILE_SIZE 64
#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500


typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}		t_img;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		collected;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
}		t_map;

typedef struct s_game
{
    mlx_t       *mlx;           // MLX42 window
    mlx_image_t *player_img;    // Player sprite
    mlx_image_t *wall_img;      // Wall sprite
    mlx_image_t *collectible_img; // Collectible sprite
    mlx_image_t *exit_img;      // Exit sprite
    mlx_image_t *floor_img;     // Floor sprite
    t_map       map;            // Map data
    int         moves;          // Move counter
} t_game;




int		parse_map(t_game *game, char *map_path);
void	free_game(t_game *game);
int		validate_map(t_game *game);
void	exit_with_error(char *message);
int		handle_window_close(t_game *game);










#endif
