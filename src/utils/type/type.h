#ifndef TYPE_H
# define TYPE_H

#include <stdlib.h>

/*
lack enum
1.	input/synesthesia/
2.	graphic/triangle_arr/
*/

typedef enum e_bool e_bool;

enum e_bool
{
	FALSE,
	TRUE
};

typedef enum e_rgba e_rgba;

enum e_rgba
{
	RED,
	GREEN,
	BLUE,
	ALPHA
};

typedef enum e_axis e_axis;

enum e_axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

typedef enum e_5cell_channels e_5cell_channels;

enum e_5cell_channels
{
	D5_RED,
	D5_GREEN,
	D5_BLUE,
	D5_ALPHA,
	D5_HEIGHT
};

typedef enum e_7cell_channels e_7cell_channels;

enum e_7cell_channels
{
	D7_RED,
	D7_GREEN,
	D7_BLUE,
	D7_ALPHA,
	D7_ROW,
	D7_COL,
	D7_HEIGHT
};

typedef enum e_write_style e_write_style;

enum e_write_style
{
	HEIGHT_ONLY,
	HEIGHT_RGBA,
	HEIGHT_RGB,
	FDF42
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
	size_t			origin_x;
	size_t			origin_y;
	int				**arr;
	unsigned char	**r;
	unsigned char	**g;
	unsigned char	**b;
	unsigned char	**a;
};

// editor/paint/

typedef struct t_rgb_input t_rgb_input;

struct t_rgb_input
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

// utils/math/
typedef struct t_complex t_complex;

struct t_complex
{
	float	re;
	float	im;
};

// ascii.c
char			mirror_tune(char a, e_bool is_left);
int				f_ctoi(char a, const char *dict);
void			ft_put_ascii_fd(int fd, int cell, const char *dict,
					e_bool is_left);

// table.c
unsigned char	**choose_rgb_channel(const t_table_fdf *src, e_rgba rgb_type,
					size_t row);
void			**choose_5cell_channel(const t_table_fdf *src,
					e_5cell_channels channel, size_t row);
e_bool			is_rgbah_table_not_null(const t_table_fdf *src, size_t row);
t_complex		get_table_fdf_coordinate(size_t row, size_t col,
					const t_table_fdf *dst);
e_bool			is_default_rgba(const unsigned char **r,
					const unsigned char **g,
					const unsigned char **b, const unsigned char **a);

#endif
