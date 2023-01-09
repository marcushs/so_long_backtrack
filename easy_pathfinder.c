#include <stdio.h>
#include "backtrack.h"

int A[4][4] = {
		{1,1,0,1},
		{1,0,0,1},
		{1,1,1,0},
		{0,0,1,1}
	};

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

int findPath(int **path, int i, int j, int n)
{
	if (i == n-1 && j == n-1)
	{
		path[i][j] = 1;
		return (1);
	}
	if (A[i][j] == 1)
	{
		path[i][j] = 1;
		if (findPath(path, i, j + 1, n) == 1)
			return (1);
		if (findPath(path, i + 1, j, n) == 1)
			return (1);
		path[i][j] = 0;
	}
	return (0);
}

int main(void)
{	
	
	int **path = malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; i++)
	{
		path[i] = malloc(4 * sizeof(int));
		ft_bzero(path[i], 4);
	}

	findPath(path, 0, 0, 4);

	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (path[i][j])
			printf("(%d, %d) --> \n", i, j);
	printf("\n");
}
