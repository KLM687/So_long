#include "so_long.h"

char **fill_map(char *map, char **map_ret, int x)
{
    int fd;
    int i;
    char *line;

    fd = open(map, O_RDONLY);
    i = 0;
    while (i < x)
    {
        line = get_next_line(fd);
        map_ret[i] = line;
        i++;
    }
    close (fd);
    return (map_ret);
}

int get_x(char *file)
{
	int		fd;
	int		read_ret;
	char	c;
    int     x;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
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

t_game *get_map(char *file, t_game *game)
{
    int     x;
    
    x = (get_x(file) + 1);
    game->map.x = x - 1;
    game->map.map = malloc(sizeof(char *) * x);
    if (!game->map.map)
        return (NULL);
    game->map.map = fill_map(file, game->map.map, x);
    return (game);
}