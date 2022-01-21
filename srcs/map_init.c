/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 19:54:10 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:44:19 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	*parse_elem(t_game *game)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < game->map.x)
	{
		y = 0;
		while (y < game->map.y)
		{
			if (game->map.map[x][y] == 'C')
				game->map.collectible++;
			else if (game->map.map[x][y] == 'E')
				game->map.exit++;
			else if (game->map.map[x][y] == 'P')
			{
				game->player.player++;
				game->player.x = x;
				game->player.y = y;
			}
			y++;
		}
		x++;
	}
	return (game);
}

bool	wall(char *str)
{
	int	i;

	i = 0;
	while (*str != '\n' && *str != '\0')
	{
		if (*str != '1')
		{
			printf("missing wall\n");
			return (FALSE);
		}
		str++;
	}
	return (TRUE);
}

t_game	*parse_wall(t_game *game)
{
	size_t	i;

	i = 0;
	game->map.y = ft_strlen_gnl(game->map.map[0], 1);
	if (!wall(game->map.map[0]) || !wall(game->map.map[game->map.x - 1]))
	{
		free_and_destroy(game, 0);
		exit(EXIT_FAILURE);
	}
	while (i < game->map.x)
	{
		if (game->map.map[i][0] != '1'
				|| game->map.map[i][game->map.y - 1] != '1')
		{
			printf("missing wall\n");
			free_and_destroy (game, 0);
			exit (EXIT_FAILURE);
		}
		i++;
	}
	return (game);
}

t_game	*map_init(char **argv, t_game *game)
{
	game->map.collectible = 0;
	game->map.pick = 0;
	game->map.exit = 0;
	game->player.player = 0;
	game->map.move = 0;
	game = get_map(argv[1], game);
	game = check_map(game);
	game = parse_wall(game);
	game = parse_elem(game);
	if (game->map.collectible == 0 || game->map.exit == 0
		|| game->player.player != 1)
	{
		printf("missing element\n");
		free_and_destroy(game, 0);
		exit(EXIT_FAILURE);
	}
	return (game);
}
