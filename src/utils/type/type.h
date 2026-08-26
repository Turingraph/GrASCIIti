#ifndef TYPE_H
# define TYPE_H

#include <stdlib.h>
#include <stdbool.h>

typedef enum e_rgba e_rgba;

enum e_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA,
	HEIGHT
};

typedef enum e_write_style e_write_style;

enum e_write_style
{
	HEIGHT_ONLY,
	HEIGHT_RGBA,
	HEIGHT_RGB
};

// input/load/

typedef enum e_load_warning e_load_warning;

enum e_load_warning
{
	CORRECT,
	NOT_DECIMAL,
	NOT_HEX,
	EMPTY
};

// input/load/

typedef struct t_load_fdf t_load_fdf;

struct t_load_fdf
{
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
	size_t			length;
	e_load_warning	int_warn;
	e_load_warning	rgb_warn;
};

typedef struct t_load_fdf_arr t_load_fdf_arr;

struct t_load_fdf_arr
{
	t_load_fdf	*arr;
	size_t		length;
	size_t		capacity;
};

// input/table/

typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	int				*arr;
	unsigned char	*r;
	unsigned char	*g;
	unsigned char	*b;
	unsigned char	*a;
};

// editor/paint/

typedef struct t_rgba t_rgba;

struct t_rgba
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

// utils/math/

typedef struct t_complex t_complex;

struct t_complex
{
	double	re;
	double	im;
};

#endif
