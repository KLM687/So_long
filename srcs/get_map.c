/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:28:14 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 14:28:15 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(char *map, char **map_ret, int x, t_game *game)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd == -1)
	{
		printf("error fd\n");
		free_and_destroy(game, -1);
		exit (EXIT_FAILURE);
	}
	i = 0;
	while (i <= x)
	{
		line = get_next_line(fd);
		map_ret[i] = line;
		i++;
	}
	close (fd);
	return (map_ret);
}

int	get_x(char *file, t_game *game)
{
	int		fd;
	int		read_ret;
	char	c;
	int		x;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("error fd\n");
		free_and_destroy(game, -1);
		exit (EXIT_FAILURE);
	}
	x = 1;
	while (1)
	{
		read_ret = read(fd, &c, 1);
		if (read_ret == 0)
			break ;
		if (read_ret < 0)
			return (-1);
		if (c == '\n')
			x++;
	}
	close(fd);
	return (x);
}

t_game	*get_map(char *file, t_game *game)
{
	int	x;

	x = get_x(file, game);
	game->map.x = x;
	if (x <= 2)
	{
		printf("wrong size\n");
		free_and_destroy(game, -1);
		exit(EXIT_FAILURE);
	}
	game->map.map = malloc(sizeof(char *) * (x + 1));
	if (!game->map.map)
	{
		free_and_destroy(game, -1);
		exit (EXIT_FAILURE);
	}
	game->map.map = fill_map(file, game->map.map, x, game);
	game->map.y = ft_strlen_gnl(game->map.map[0], 1);
	if (game->map.y <= 3)
	{
		printf("wrong size\n");
		free_and_destroy(game, 0);
		exit(EXIT_FAILURE);
	}
	return (game);
}
