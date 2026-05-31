#ifndef TYPE_H
# define TYPE_H

#include <stdlib.h>

typedef struct t_rgb t_rgb;
typedef struct t_llist_fdf t_llist_fdf;

struct t_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

struct t_llist_fdf
{
	int				*arr;
	t_rgb			**rgb;
	size_t			len;
	t_llist_fdf		*next;
	char			int_err;
	char			rgb_err;
};

typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				**arr;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};

#endif
