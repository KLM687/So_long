/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 07:13:54 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:49:02 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_pos(size_t x, size_t y, t_game *game)
{
	if (x >= 0 && x <= game->map.x)
	{
		if (y >= 0 && y <= game->map.y)
		{
			if (game->map.map[x][y] != '1')
			{
				if (game->map.map[x][y] == 'E')
				{
					if (check_exit(game))
						return (TRUE);
					else
						return (FALSE);
				}
				return (TRUE);
			}
		}
	}
	return (FALSE);
}

t_game	*move_up(t_game *game)
{
	if (check_pos(game->player.x, game->player.y - 1, game))
	{
		game->map.map[game->player.x][game->player.y] = '0';
		if (game->map.map[game->player.x][game->player.y - 1] == 'C')
			printf("pizza %zu / %zu\n", ++game->map.pick, game->map.collectible);
		game->map.map[game->player.x][game->player.y - 1] = 'P';
		game->player.y -= 1;
		printf("move = %zu\n", ++game->map.move);
		return (game);
	}
	return (game);
}

t_game	*move_left(t_game *game)
{
	if (check_pos(game->player.x - 1, game->player.y, game))
	{
		game->map.map[game->player.x][game->player.y] = '0';
		if (game->map.map[game->player.x - 1][game->player.y] == 'C')
			printf("pizza %zu / %zu\n", ++game->map.pick, game->map.collectible);
		game->map.map[game->player.x -1][game->player.y] = 'P';
		game->player.x -= 1;
		printf("move = %zu\n", ++game->map.move);
		return (game);
	}
	return (game);
}

t_game	*move_right(t_game *game)
{
	if (check_pos(game->player.x + 1, game->player.y, game))
	{
		game->map.map[game->player.x][game->player.y] = '0';
		if (game->map.map[game->player.x + 1][game->player.y] == 'C')
			printf("pizza %zu / %zu\n", ++game->map.pick, game->map.collectible);
		game->map.map[game->player.x + 1][game->player.y] = 'P';
		game->player.x += 1;
		printf("move = %zu\n", ++game->map.move);
		return (game);
	}
	return (game);
}

t_game	*move_down(t_game *game)
{
	if (check_pos(game->player.x, game->player.y + 1, game))
	{
		game->map.map[game->player.x][game->player.y] = '0';
		if (game->map.map[game->player.x][game->player.y + 1] == 'C')
			printf("pizza %zu / %zu\n", ++game->map.pick, game->map.collectible);
		game->map.map[game->player.x][game->player.y + 1] = 'P';
		game->player.y += 1;
		printf("move = %zu\n", ++game->map.move);
		return (game);
	}
	return (game);
}
