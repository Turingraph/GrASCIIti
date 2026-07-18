#include"line.h"

// time : O(1)
// space: O(1)
void	sort_2d_points(t_line *line)
{
	int		temp;
	int		delta_x;
	int		delta_y;

	delta_y = (int)f_abs(line->p2.x - line->p1.x);
	delta_x = (int)f_abs(line->p2.y - line->p1.y);
	if (line != NULL && (delta_x >= delta_y && line->p2.x < line->p1.x)
			|| (line->p2.y < line->p1.y && delta_x < delta_y))
	{
		temp = line->p2.x;
		line->p2.x = line->p1.x;
		line->p1.x = temp;
		temp = line->p2.y;
		line->p2.y = line->p1.y;
		line->p1.y = temp;
	}
}

// time : O(1)
// space: O(1)
e_line_direction	init_swap_bresenham_y(t_line *line,
	int *delta_x, int *delta_y)
{
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs(line->p2.x - line->p1.x) < f_abs(line->p2.y - line->p1.y))
	{
		*delta_y = line->p2.x - line->p1.x;
		*delta_x = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_y = line->p1.x - line->p2.x;
			*delta_x = line->p1.y - line->p2.y;
			sort_2d_points(line);
		}
		if (*delta_y < 0)
			return (LINE_Y_NEGATIVE_X);
		return (LINE_Y_POSITIVE_X);
	}
	return (LINE_XY_INVALID);
}

// time : O(1)
// space: O(1)
e_line_direction	init_swap_bresenham_x(t_line *line,
	int *delta_x, int *delta_y)
{
	if (line != NULL && delta_x != NULL && delta_y != NULL
		&& f_abs(line->p2.x - line->p1.x) >= f_abs(line->p2.y - line->p1.y))
	{
		*delta_x = line->p2.x - line->p1.x;
		*delta_y = line->p2.y - line->p1.y;
		if (*delta_x < 0)
		{
			*delta_x = line->p1.x - line->p2.x;
			*delta_y = line->p1.y - line->p2.y;
			sort_2d_points(line);
		}
		if (*delta_y < 0)
			return (LINE_X_NEGATIVE_Y);
		return (LINE_X_POSITIVE_Y);
	}
	return (LINE_XY_INVALID);
}

// time : O(1)
// space: O(1)
void	init_rectangle_boundary(t_line *boundary, t_2d_int *table_dim)
{
	int	temp;

	if (boundary != NULL && table_dim != NULL
		&& table_dim->x >= 0 && table_dim->y >= 0)
	{
		table_dim->x = f_abs(table_dim->x);
		table_dim->y = f_abs(table_dim->y);
		boundary->p1.x = (int)f_interval(boundary->p1.x, 0, table_dim->x);
		boundary->p1.y = (int)f_interval(boundary->p1.y, 0, table_dim->y);
		boundary->p2.x = (int)f_interval(boundary->p2.x, 0, table_dim->x);
		boundary->p2.y = (int)f_interval(boundary->p2.y, 0, table_dim->y);
	}
	if (boundary != NULL && boundary->p1.x > boundary->p2.x)
	{
		temp = boundary->p1.x;
		boundary->p1.x = boundary->p2.x;
		boundary->p2.x = temp;
	}
	if (boundary != NULL && boundary->p1.y > boundary->p2.y)
	{
		temp = boundary->p1.y;
		boundary->p1.y = boundary->p2.y;
		boundary->p2.y = temp;
	}
}

// time : O(1)
// space: O(1)
t_line	init_int_line(t_line src, t_line boundary)
{
	t_line	dst;

	dst.p1.x = (int)f_interval(src.p1.x, 0,
			boundary.p2.x - boundary.p1.x) + boundary.p1.x;
	dst.p2.x = (int)f_interval(src.p2.x, 0,
			boundary.p2.x - boundary.p1.x) + boundary.p1.x;
	dst.p1.y = (int)f_interval(src.p1.y, 0,
			boundary.p2.y - boundary.p1.y) + boundary.p1.y;
	dst.p2.y = (int)f_interval(src.p2.y, 0,
			boundary.p2.y - boundary.p1.y) + boundary.p1.y;
	return (dst);
}
