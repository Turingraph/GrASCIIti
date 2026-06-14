#ifndef TYPE_H
# define TYPE_H

#include <stdlib.h>

typedef struct t_rgb t_rgb;

struct t_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

// input/llist_load/

typedef struct t_llist_fdf t_llist_fdf;

struct t_llist_fdf
{
	int				*arr;
	t_rgb			**rgb;
	size_t			len;
	t_llist_fdf		*next;
	char			int_err;
	char			rgb_err;
};

// input/table/

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

typedef struct t_table_char t_table_char;

struct t_table_char
{
	size_t			row;
	size_t			col;
	unsigned char	**arr;
};

// input/synesthesia/

typedef struct t_synesthesia t_synesthesia;

struct t_synesthesia
{
	char			*alphabet;
	size_t			row;
	size_t			col;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};

// graphic/triangle_pair/

typedef struct t_triangle t_triangle;

struct t_triangle
{
	double			*p1;
	double			*p2;
	double			*p3;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

// graphic/triangle_arr/

typedef struct t_triangle_arr t_triangle_arr;

struct t_triangle_arr
{
	t_triangle	*arr;
	size_t		length;
	size_t		capacity;
};

#endif
