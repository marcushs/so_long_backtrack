#include "backtrack.h"

Path	*ft_lstnew(Point *point)
{
	Path	*new;

	new = malloc(sizeof(Path));
	if (!new)
		return (NULL);
	new->point = point;
	new->next = NULL;
	return (new);
}

Path	*ft_lstlast(Path *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(Path **path, Path *new)
{
	Path	*last;

	if (!*path)
		*path = new;
	else
	{
		last = ft_lstlast(*path);
		last->next = new;
	}
}

void	ft_lst_push(Path **path, Point *point)
{
	ft_lstadd_back(path, ft_lstnew(point));
}

void	print_lst(Path *path)
{
	Path	*tmp;

	tmp = path;
	while (tmp->next)
	{
		path = tmp->next;
		printf("x: %d y: %d\n", path->point->x, path->point->y);
		tmp = path;
	}

}

void	ft_lst_pop(Path **path)
{
	Path	*tmp;
	Path	*prev;

	tmp = *path;
	if (!*path)
		return ;
	if (tmp->next == NULL)
	{
		path = NULL;
	}
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	free(tmp);
}

// int	main(void)
// {
// 	Path	*path;
// 	Point	*point;
// 	Point	*point2;
// 	Point	*point3;

// 	path = malloc(sizeof(Path));
// 	point = malloc(sizeof(Point));
// 	point2 = malloc(sizeof(Point));
// 	point3 = malloc(sizeof(Point));
// 	point->x = 3;
// 	point->y = 3;
// 	point2->x = 4;
// 	point2->y = 4;
// 	point3->x = 5;
// 	point3->y = 5;
// 	ft_lst_push(&path, point);
// 	ft_lst_push(&path, point2);
// 	ft_lst_push(&path, point3);
// 	print_lst(path);
// 	ft_lst_pop(&path);
// 	ft_lst_pop(&path);
// 	print_lst(path);
// 	// while (tmp->next)
// 	// {
// 	// 	path = tmp->next;
// 	// 	printf("x: %d y: %d\n", path->point->x, path->point->y);
// 	// 	tmp = path;
// 	// }
// 	// ft_lst_pop(&path);
// 	// while (tmp2->next)
// 	// {
// 	// 	path = tmp2->next;
// 	// 	printf("x: %d y: %d\n", path->point->x, path->point->y);
// 	// 	tmp2 = path;
// 	// }
// }
