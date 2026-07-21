#include"line.h"

// time : O(n * thickness)
// space: O(1)
void	draw_straight_line(t_table_fdf *dst, t_line line, t_line rectangle_boundary, t_ink ink)
{
	t_boundary		boundary;
	unsigned char	*arr;
	t_circle		end_point;

	if (dst != NULL)
	{
		boundary = init_rectangle_boundary(rectangle_boundary, dst->row, dst->col);
		line = init_first_line(line, boundary);
		arr = NULL;
		if (ink.channel == RED)
			arr = dst->r;
		if (ink.channel == GREEN)
			arr = dst->g;
		if (ink.channel == BLUE)
			arr = dst->b;
		if (ink.channel == ALPHA)
			arr = dst->a;
		if (arr != NULL)
			ink.color = (int)f_interval(ink.color, 0, 255);
		if (arr == NULL && f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
			bresenham_int_x_thick(dst->arr, line, boundary, ink);
		else if (arr == NULL && f_abs(line.p2.x - line.p1.x) < f_abs(line.p2.y - line.p1.y))
			bresenham_int_y_thick(dst->arr, line, boundary, ink);
		else if (arr != NULL && f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
			bresenham_uchar_x_thick(arr, line, boundary, ink);
		else if (arr != NULL && f_abs(line.p2.x - line.p1.x) < f_abs(line.p2.y - line.p1.y))
			bresenham_uchar_y_thick(arr, line, boundary, ink);
		end_point.radius = ink.thickness / 2;
		end_point.x = line.p1.x;
		end_point.y = line.p1.y;
		if (arr == NULL && ink.thickness > 1)
			midpoint_circle_int(dst->arr, ink.color, end_point, boundary);
		if (arr != NULL && ink.thickness > 1)
			midpoint_circle_uchar(arr, ink.color, end_point, boundary);
		end_point.x = line.p2.x;
		end_point.y = line.p2.y;
		if (arr == NULL && ink.thickness > 1)
			midpoint_circle_int(dst->arr, ink.color, end_point, boundary);
		if (arr != NULL && ink.thickness > 1)
			midpoint_circle_uchar(arr, ink.color, end_point, boundary);
	}
}
