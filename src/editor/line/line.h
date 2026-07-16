#ifndef PAINT_H
# define PAINT_H

# include "../../input/table/table.h"

typedef struct t_line t_line;

struct t_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	size_t	col;
	size_t	row;
}

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

// bersenham.c
void	sort_line_index(t_line *line, char dim);

// xiaolin_wu.c

#endif
