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

typedef struct	s_path
{
	Point	*point;
	struct s_path *next;
}				Path;


typedef struct	s_map
{
	char	**parsed_map;
	int		rows;
	int		cols;
}				Map;

//gnl && gnl_utils
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_line(char *str);
size_t	ft_strlen(char *s);
int		ft_strchr(char *s, int c);
char	*get_next_line(int fd);
//map
Map		*parse_map(char *file_path);
int		count_line(char *file_path);
int		count_cols(char *s);
Point	*get_point(char	**map, char c);
//linked list
Path	*ft_lstnew(Point *point);
Path	*ft_lstlast(Path *lst);
void	ft_lstadd_back(Path **path, Path *new);
void	ft_lst_push(Path **path, Point *point);
void	ft_lst_pop(Path **path);
void	print_lst(Path *path);
//pathfinder && pathfinder utils
int		**allocate_2D_array(int rows, int cols);
int		**create_dir_array();
#endif
