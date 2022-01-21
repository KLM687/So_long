/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:48:47 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:09:15 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_img(t_game *game)
{
	int	err;

	err = 0;
	if (!game->floor.img)
		err++;
	if (!game->wall.img)
		err++;
	if (!game->item.img)
		err++;
	if (!game->exit.img)
		err++;
	if (!game->gummy.img)
		err++;
	if (err > 0)
		free_and_destroy(game, 1);
}

void	free_map(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < game->map.x)
	{
		free(game->map.map[i]);
		i++;
	}
	free(game->map.map);
}

int	free_and_destroy(t_game *game, int step)
{
	if (step > 0)
	{
		if (game->floor.img)
			mlx_destroy_image(game->mxl.mlx, game->floor.img);
		if (game->wall.img)
			mlx_destroy_image(game->mxl.mlx, game->wall.img);
		if (game->item.img)
			mlx_destroy_image(game->mxl.mlx, game->item.img);
		if (game->gummy.img)
			mlx_destroy_image(game->mxl.mlx, game->gummy.img);
		if (game->exit.img)
			mlx_destroy_image(game->mxl.mlx, game->exit.img);
		mlx_destroy_window(game->mxl.mlx, game->mxl.windows);
		mlx_destroy_display(game->mxl.mlx);
		free (game->mxl.mlx);
	}
	if (step >= 0)
		free_map(game);
	free(game);
	exit(EXIT_SUCCESS);
}

int	free_and_destroy2(t_game *game)
{
	mlx_destroy_image(game->mxl.mlx, game->floor.img);
	mlx_destroy_image(game->mxl.mlx, game->wall.img);
	mlx_destroy_image(game->mxl.mlx, game->item.img);
	mlx_destroy_image(game->mxl.mlx, game->gummy.img);
	mlx_destroy_image(game->mxl.mlx, game->exit.img);
	mlx_destroy_window(game->mxl.mlx, game->mxl.windows);
	mlx_destroy_display(game->mxl.mlx);
	free(game->mxl.mlx);
	free_map(game);
	free(game);
	exit (EXIT_SUCCESS);
}
