#ifndef FDF_H
# define FDF_H

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

typedef struct t_llist_fdf t_llist_fdf;
typedef struct t_table_fdf t_table_fdf;

struct t_llist_fdf
{
	int				*arr;
	t_rgb			**rgb;
	size_t			len;
	t_llist_fdf		*next;
	char			int_err;
	char			rgb_err;
};

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				**table;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};

// all_lines.c
void		free_llist_fdf(t_llist_fdf *src);
t_llist_fdf	*all_lines(char *file, int fd, t_llist_fdf *(*one_line)(char *));
void		write_all_lines(int fd, t_llist_fdf *llist);

// ascii.c
t_llist_fdf	*init_llist_fdf(size_t line_len);
t_llist_fdf	*one_ascii_line(char *line);

// fdf.c
t_llist_fdf	*one_fdf_line(char *line);

// table.c
void		*free_table_fdf(t_table_fdf *table);
t_table_fdf	*init_table(size_t col, size_t row);
t_table_fdf	*llist_to_table_fdf(t_llist_fdf *src);

#endif
