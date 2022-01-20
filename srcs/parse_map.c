/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:19:29 by flee              #+#    #+#             */
/*   Updated: 2022/01/19 17:19:34 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game *check_size(t_game *game)
{
    size_t i;
    size_t a;
    size_t b;

    i = 0;
    a = ft_strlen_gnl(game->map.map[i], 1);
    game->map.y = a;
    while (i < game->map.x)
    {
        b = ft_strlen_gnl(game->map.map[i], 1);
        printf("b = %zu\n",b);
        if (b != a)
        {
            printf("Map is not rectangular\n");
            free_and_destroy(game, 0);
            exit (EXIT_FAILURE);
        }
        i++;
    }
    return (game);
}

void elem_check(char c, t_game *game)
{
    if (c != '1' && c != 'E' && c != '0' 
        && c != 'P' && c != 'C')
    {
        printf("invalid element !\n");
        free_and_destroy(game, 0);
        exit (EXIT_FAILURE);
    }
}

bool check_elem(t_game *game)
{
    size_t x;
    size_t y;

    x = 0;
    while (x < game->map.x)
    {
        y = 0;
        while (y < game->map.y)
        {
            elem_check(game->map.map[x][y], game);
            y++;
        }
        x++;
    }
    return (TRUE);
}

t_game *check_map(t_game *game)
{
    if (check_size(game))
    {
        if (check_elem(game))
            return (game);
    }
    return (game);
}
