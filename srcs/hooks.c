/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:32:50 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:31:39 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	check_exit(t_game *game)
{
	if (game->map.pick == game->map.collectible)
	{
		printf("GG\n");
		free_and_destroy(game, 1000);
		return (TRUE);
	}
	return (FALSE);
}

int	input(int key, t_game *game)
{
	if (key == 65307)
		free_and_destroy(game, 1);
	else if (key == 119)
		game = move_left(game);
	else if (key == 97)
		game = move_up(game);
	else if (key == 100)
		game = move_down(game);
	else if (key == 115)
		game = move_right(game);
	display(game);
	return (0);
}
