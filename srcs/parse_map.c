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

bool check_size(t_game *game)
{
    size_t i;
    size_t a;
    size_t b;

    i = 0;
    a = ft_strlen_gnl(game->map.map[i], 1);
    while (game->map.map[i])
    {
        b = ft_strlen_gnl(game->map.map[i], 1);
        if (b != a)
            return (FALSE);
        i++;
    }
    printf("BOUM\n");
    return (TRUE);
}

bool elem_check(char c)
{
    printf("%c\n", c);
    if (c != '1' || c != 'E' || c != '0' 
        || c != 'P' || c != 'C')
        return (TRUE);
    return(FALSE);
}

bool check_elem(t_game *game)
{
    size_t x;
    size_t y;

    x = 0;
    while (game->map.map[x])
    {
        y = 0;
        while (game->map.map[x][y] != '\n' 
                && game->map.map[x][y])
        {
            if (elem_check(game->map.map[x][y]))
                return (FALSE);
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
        printf("size ok\n");
        if (check_elem(game))
        {
            printf("elem ok\n");
            return (game);
        }
    }
    return (NULL);
}
