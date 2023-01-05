#include "backtrack.h"

// int	pathfinder(char **map, char wall, Point start, Point end)
// {

// }

int	main(void)
{
	Map	*map = parse_map("test.ber");
	
	for (int i = 0; map->parsed_map[i]; i++)
		printf("%s", map->parsed_map[i]);

	printf("\n");
	printf("%d\n", map->rows);
	printf("%d\n", map->cols);

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

}
