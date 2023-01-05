#ifndef BACKTRACK_H
# define BACKTRACK_H
# define BUFFER_SIZE 1
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				Point;

typedef struct	s_map
{
	char	**parsed_map;
	int		rows;
	int		cols;
}				Map;

void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *str);
size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
//char	**parse_map(char *file_path);
Map		*parse_map(char *file_path);
int		count_line(char *file_path);
#endif
