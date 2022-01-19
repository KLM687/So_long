/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:48:47 by flee              #+#    #+#             */
/*   Updated: 2022/01/19 09:48:48 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(t_game *game)
{
    size_t i;

    i = 0;
    while (game->map.map[i])
    {
        free(game->map.map[i]);
        i++;
    }
    free(game->map.map);
}

int    free_and_destroy(t_game *game)
{
    mlx_destroy_image(game->mxl.mlx, game->floor.img);
    mlx_destroy_image(game->mxl.mlx, game->wall.img);
    mlx_destroy_image(game->mxl.mlx, game->item.img);
    mlx_destroy_image(game->mxl.mlx, game->gummy.img);
    mlx_destroy_image(game->mxl.mlx, game->exit.img);
    mlx_destroy_window(game->mxl.mlx, game->mxl.windows);
    mlx_destroy_display(game->mxl.mlx);
    free (game->mxl.mlx);
    free_map(game);
    free(game);
    exit (EXIT_SUCCESS);
}