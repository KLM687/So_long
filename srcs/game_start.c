/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:26:30 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:13:47 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_addr(t_game *game)
{
	game->floor.addr = mlx_get_data_addr(game->floor.img,
			&game->floor.byte_p, &game->floor.line_l, &game->floor.end);
	game->wall.addr = mlx_get_data_addr(game->wall.img,
			&game->wall.byte_p, &game->wall.line_l, &game->wall.end);
	game->item.addr = mlx_get_data_addr(game->item.img,
			&game->item.byte_p, &game->item.line_l, &game->item.end);
	game->floor.addr = mlx_get_data_addr(game->exit.img,
			&game->exit.byte_p, &game->exit.line_l, &game->exit.end);
	game->floor.addr = mlx_get_data_addr(game->gummy.img,
			&game->gummy.byte_p, &game->gummy.line_l, &game->gummy.end);
}

t_game	*open_img(t_game *game)
{
	game->floor.img = mlx_xpm_file_to_image(game->mxl.mlx,
			"./img/floor.xpm", &game->floor.byte_p, &game->floor.line_l);
	game->item.img = mlx_xpm_file_to_image(game->mxl.mlx,
			"./img/collectible.xpm", &game->item.byte_p, &game->item.line_l);
	game->exit.img = mlx_xpm_file_to_image(game->mxl.mlx,
			"./img/exit.xpm", &game->exit.byte_p, &game->exit.line_l);
	game->gummy.img = mlx_xpm_file_to_image(game->mxl.mlx,
			"./img/player.xpm", &game->gummy.byte_p, &game->gummy.line_l);
	game->wall.img = mlx_xpm_file_to_image(game->mxl.mlx,
			"./img/wall.xpm", &game->wall.byte_p, &game->wall.line_l);
	check_img(game);
	img_addr(game);
	return (game);
}

void	put_img(t_game *game, size_t x, size_t y)
{
	if (game->map.map[x][y] == '1')
		mlx_put_image_to_window(game->mxl.mlx, game->mxl.windows,
			game->wall.img, y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map.map[x][y] == '0')
		mlx_put_image_to_window(game->mxl.mlx, game->mxl.windows,
			game->floor.img, y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map.map[x][y] == 'C')
		mlx_put_image_to_window(game->mxl.mlx, game->mxl.windows,
			game->item.img, y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map.map[x][y] == 'E')
		mlx_put_image_to_window(game->mxl.mlx, game->mxl.windows,
			game->exit.img, y * IMG_SIZE, x * IMG_SIZE);
	else if (game->map.map[x][y] == 'P')
		mlx_put_image_to_window(game->mxl.mlx, game->mxl.windows,
			game->gummy.img, y * IMG_SIZE, x * IMG_SIZE);
}

void	display(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->map.x)
	{
		y = 0;
		while (y < game->map.y)
		{
			put_img(game, x, y);
			y++;
		}		
		x++;
	}
}

void	game_start(t_game *game)
{
	game->mxl.mlx = mlx_init();
	game->mxl.w_x = game->map.x * IMG_SIZE;
	game->mxl.w_y = game->map.y * IMG_SIZE;
	game->mxl.windows = mlx_new_window(game->mxl.mlx,
			game->mxl.w_y, game->mxl.w_x, "./so_long");
	game = open_img(game);
	display(game);
	mlx_key_hook(game->mxl.windows, input, game);
	mlx_hook(game->mxl.windows, 33, 1l << 5, free_and_destroy2, game);
	mlx_loop(game->mxl.mlx);
}
