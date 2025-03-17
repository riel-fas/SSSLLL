/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_handl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: riel-fas <riel-fas@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 08:49:02 by riel-fas          #+#    #+#             */
/*   Updated: 2025/03/17 10:27:09 by riel-fas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	errors()
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
