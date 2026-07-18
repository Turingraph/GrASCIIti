#ifndef PAINT_H
# define PAINT_H

# include "../../utils/math/math.h"
# include<unistd.h>

typedef struct t_ink t_ink;

struct t_ink
{
	e_rgba	channel;
	int		color;
	size_t	thickness;
};

typedef struct t_2d_int t_2d_int;

struct t_2d_int
{
	int	x;
	int	y;
};

typedef struct t_line t_line;

struct t_line
{
	t_2d_int	p1;
	t_2d_int	p2;
};

typedef struct t_2d_polygon t_2d_polygon;

struct t_2d_polygon
{
	t_complex	*arr;
	size_t		length;
	bool		is_loop;
};

typedef struct t_2d_polygon_arr t_2d_polygon_arr;

struct t_2d_polygon_arr
{
	t_2d_polygon	*arr;
	size_t			length;
};

typedef enum e_line_direction e_line_direction;

enum e_line_direction
{
	LINE_XY_INVALID,
	LINE_X_POSITIVE_Y,
	LINE_X_NEGATIVE_Y,
	LINE_Y_POSITIVE_X,
	LINE_Y_NEGATIVE_X,
};

// init.c
void				sort_2d_points(t_line *line);
e_line_direction	init_swap_bresenham_y(t_line *line,
						int *delta_x, int *delta_y);
e_line_direction	init_swap_bresenham_x(t_line *line,
						int *delta_x, int *delta_y);
void				init_rectangle_boundary(t_line *boundary,
						t_2d_int *table_dim);
t_line				init_int_line(t_line src, t_line boundary);

// polygon.c
t_line				init_float_line(t_complex point_1, t_complex point_2,
						t_line boundary);

#endif
