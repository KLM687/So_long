/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 09:52:12 by flee              #+#    #+#             */
/*   Updated: 2022/01/21 09:52:14 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include "libft.h"
# include "mlx.h"

# define FALSE 0
# define TRUE 1
# define BUFFER_SIZE 99999
# define IMG_SIZE 64

typedef struct s_map
{
	char	**map;
	size_t	x;
	size_t	y;
	size_t	move;
	size_t	collectible;
	size_t	pick;
	size_t	exit;
}	t_map;

typedef struct s_player
{
	size_t	player;
	size_t	x;
	size_t	y;
}	t_player;

typedef struct s_mlx
{
	void	*mlx;
	void	*windows;
	size_t	w_x;
	size_t	w_y;
}	t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		byte_p;
	int		line_l;
	int		end;
}	t_img;

typedef struct s_game
{
	t_map		map;
	t_mlx		mxl;
	t_player	player;
	t_img		gummy;
	t_img		wall;
	t_img		floor;
	t_img		exit;
	t_img		item;
	int 		step;
}	t_game;

t_game	*map_init(char **argv, t_game *game);
t_game	*get_map(char *file, t_game *game);
void	game_start(t_game *start);
int		input(int key, t_game *game);
t_game	*move_up(t_game *game);
t_game	*move_left(t_game *game);
t_game	*move_right(t_game *game);
t_game	*move_down(t_game *game);
void	display(t_game *game);
void	put_img(t_game *game, size_t x, size_t y);
bool	check_exit(t_game *game);
int		free_and_destroy(t_game *game, int step);
t_game	*check_map(t_game *game);
int    	free_and_destroy2(t_game *game);
void	check_img(t_game *game);

size_t	ft_strlen_gnl(const char *str, size_t state);
size_t	ft_strlcpy_gnl(char *dest, const char *src, size_t size);
char	*ft_strjoin_gnl(char *s1, char const *s2, size_t read_return);
size_t	ft_strlcat_gnl(char *dst, const char *src, size_t size);
char	*ft_substr_gnl(char *s, size_t start, size_t len, size_t state);
size_t	ft_check_gnl(char *memory);
char	*ft_fill_line_gnl(char *memory, char *line);
char	*ft_fill_memory_gnl(char *memory, char buf[BUFFER_SIZE + 1], int fd);
char	*get_next_line(int fd);

#endif
