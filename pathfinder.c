#include "backtrack.h"

int	walk(Map *map, char wall, Point *curr, Point *end, int **seen, int **dir, Path *path)
{
	//basecase1 (out of boundary)
	if (curr->x < 0 || curr->x >= map->cols || curr->y < 0 || curr->y >= map->rows)
		return (0);
	//basecase2 (its a wall(1s)
	if (map->parsed_map[curr->y][curr->x] == wall)
		return (0);

 	//basecase3 (its the end)
	if (curr->x == end->x && curr->y == end->y)
		return (1);

	//basecase4 already seen
	if (seen[curr->y][curr->x])
		return (0);
	//recursion;
	seen[curr->y][curr->x] = 1;
	ft_lst_push(&path, curr);

	//recurse
	for (int i = 0; i < 4; i++)
	{
		curr->x = curr->x + dir[i][1];
		curr->y = curr->y + *(dir[i]);
		printf("x: %d y: %d ", curr->x, curr->y);
		if (walk(map, '1', curr, end, seen, dir, path))
			return (1);
		curr->x = curr->x - dir[i][1];
		curr->y = curr->y - *(dir[i]);
	}

	//post
	ft_lst_pop(&path);
	return (0);
}

Path	*pathfinder(Map *map, char wall, Point *start, Point *end)
{
		Path	*path;
		int		**seen;
		int		**dir;
		
		path = malloc(sizeof(Path));
		path->point = NULL;
		path->next = NULL;
		seen = allocate_2D_array(map->rows, map->cols);
		dir = create_dir_array();
		walk(map, wall, start, end, seen, dir, path);
		return (path);
}

int	main(void)
{
	Map	*map = parse_map("map1.ber");
	Path *path;
	Point	*start;
	Point	*end;

	
	for (int i = 0; map->parsed_map[i]; i++)
		printf("%s", map->parsed_map[i]);

	start = get_point(map->parsed_map, 'P');
	end = get_point(map->parsed_map, 'E');
	printf("\n");
	printf("P's x = %d\n", start->x);
	printf("P's y = %d\n", start->y);
	printf("E's x = %d\n", end->x);
	printf("E's y =	%d\n", end->y);
	printf("no of rows = %d\n", map->rows);
	printf("no of cols = %d\n", map->cols);
	printf("\n");
	path = pathfinder(map, '1', start, end);
	print_lst(path);
	// int **dir;

	// dir[0]
	// for (int i = 0; i < 4; i++)
	// {
	// 	for (int j = 0; j < 2; j++)
	// 		printf("%d ",dir[i][j]);
	// 	printf("\n");
	// }

}
