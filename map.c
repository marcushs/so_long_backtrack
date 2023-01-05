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

// char	**parse_map(char *file_path)
// {
// 	char	**parsed_map;
// 	int		nb_lines;
// 	int		fd;
// 	int		i;

// 	nb_lines = count_lines(file_path);
// 	parsed_map = (char **)malloc(sizeof(char *) * nb_lines);
// 	if (!parsed_map)
// 		return (NULL);
// 	fd = open(file_path, O_RDONLY);
// 	parsed_map[0] = get_next_line(fd);
// 	i = 1;
// 	while (i < nb_lines)
// 	{
// 		parsed_map[i] = get_next_line(fd);
// 		i++;
// 	}
// 	parsed_map[i] = 0;
// 	close(fd);
// 	return (parsed_map);
// }

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
