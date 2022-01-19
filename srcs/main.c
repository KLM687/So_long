/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:48:45 by flee              #+#    #+#             */
/*   Updated: 2022/01/03 18:48:49 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool    check_ber(char *str)
{
    int len;

    len = ft_strlen(str);
    if (len > 5)
    {
        if (str[len - 4] != '.')
            return(0);
        if (str[len - 3] != 'b')
            return(0);  
        if (str[len - 2] != 'e')
            return(0);
        if (str[len - 1] != 'r')
            return(0);
    }
    return (1);
}

int main(int argc, char **argv)
{   
    t_game *game;
    
    if (argc != 2)
    {
        printf("error\n./so_long map.ber\n");
        return (EXIT_FAILURE);
    }
    else if (!check_ber(argv[1]))
    {
        printf("error\n./so_long map.ber\n");
        return (EXIT_FAILURE);
    }
    game = malloc(sizeof(t_game));
    if (!game)
        return(EXIT_FAILURE);
    game = map_init(argv, game);
    if (!game)
        printf("map is incomplete\n");
    else
        game_start(game);
    return (EXIT_SUCCESS);
}