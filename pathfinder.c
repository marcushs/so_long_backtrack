#include "backtrack.h"

// int	walk(Map *map, char wall, Point *curr, Point *end, Path *path)
// {
// 	//basecase1 (out of boundary)
// 	if (curr->x < 0 || curr->x >= map->cols || curr->y < 0 || curr->y >= map->rows)
	//return (0);
// 	//basecase2 (its a wall(1s))
// 	if (map->parsed_map[curr->y][curr->x] == '1')
	//return (0);

// 	//basecase3 (its the end)
	//if (curr->x == end->x && curr->y == end->y)
	//	return (1);

// 	//basecase4 (spot seen before)

	//recursion;
	//pre
	//ft_lstadd_back(path, curr);

	//recurse

	//post
	//ft_lstdel_last(path);
// }

// Point	*pathfinder(Map *map, char wall, Point start, Point end)
// {
		
// }

int	main(void)
{
	Map	*map = parse_map("test.ber");
	Point	*start;
	Point	*end;
	
	for (int i = 0; map->parsed_map[i]; i++)
		printf("%s", map->parsed_map[i]);

	start = get_point(map->parsed_map, 'P');
	end = get_point(map->parsed_map, 'E');
	printf("P's x = %d\n", start->x);
	printf("P's y = %d\n", start->y);
	printf("E's x = %d\n", end->x);
	printf("E's y =	%d\n", end->y);
	printf("no of rows = %d\n", map->rows);
	printf("no of cols = %d\n", map->cols);

	//find position
	// int x = 0;
	// int y = 0;

	// while (map[y])
	// {
	// 	while (map[y][x] != 0 && map[y][x] != '\n')
	// 	{
	// 		if (map[y][x] == 'P')
	// 		{
	// 			printf("x = %d\n", x);
	// 			printf("y = %d\n", y);
	// 			break;
	// 		}
	// 		x++;
	// 	}
	// 	x = 0;
	// 	y++;
	// }
	return (0);
}
