#include "backtrack.h"

int	count_lines(char *file_path)
{
	int		fd;
	int		i;
	char	*line;
	
	fd = open(file_path, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	count_cols(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

Map	*parse_map(char *file_path)
{
	Map	*map;
	int	fd;
	int	i;

	map = (Map *)malloc(sizeof(Map));
	map->rows = count_lines(file_path);
	map->parsed_map = malloc(sizeof(char *) * map->rows);
	fd = open(file_path, O_RDONLY);
	map->parsed_map[0] = get_next_line(fd);
	i = 1;
	while (i < map->rows)
	{
		map->parsed_map[i] = get_next_line(fd);
		i++;
	}
	map->cols = count_cols(map->parsed_map[i - 1]);
	map->parsed_map[i] = 0;
	close(fd);
	return (map);
}

Point	*get_point(char	**map, char c)
{
	Point	*point;
	int x = 0;
	int y = 0;

	point = (Point *)malloc(sizeof(Point));
	while (map[y])
	{
		while (map[y][x] != 0 && map[y][x] != '\n')
		{
			if (map[y][x] == c)
			{
				point->x = x;
				point->y = y;
				return (point);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (NULL);
}
