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

typedef enum e_sampling_rgba e_sampling_rgba;

enum e_sampling_rgba
{
	SAMPLE_TOP_LEFT,
	SAMPLE_AVERAGE,
	SAMPLE_EDGE_AVERAGE
};

// input/table/

typedef struct t_table_fdf t_table_fdf;

struct t_table_fdf
{
	size_t			row;
	size_t			col;
	size_t			origin_x;
	size_t			origin_y;
	e_sampling_rgba	color_sampling;
	float			zoom;
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

// graphic/triangle_pair/

typedef struct t_triangle t_triangle;

struct t_triangle
{
	float			*p1;
	float			*p2;
	float			*p3;
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
	size_t		table_row;
	size_t		table_col;
	float		width_x;
	float		width_y;
	float		width_z;
};

// graphic/prism/
typedef struct t_prism t_prism;

struct t_prism
{
	t_triangle_arr	faces;
	t_triangle_arr	edges;
};

// utils/math/
typedef struct t_complex t_complex;

struct t_complex
{
	double	re;
	double	im;
};

#endif
