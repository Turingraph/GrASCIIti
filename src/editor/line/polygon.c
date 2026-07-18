#include"line.h"

// time : O(1)
// space: O(1)
t_2d_int	f_complex_to_2d_position(t_complex src,
	t_line boundary)
{
	t_2d_int	dst;

	src.re = f_interval(src.re, 0, 1);
	src.im = f_interval(src.im, 0, 1);
	dst.x = (int)f_floor(src.re * (boundary.p2.x - boundary.p2.x)) + boundary.p1.x;
	dst.y = (int)f_floor(src.im * (boundary.p2.y - boundary.p2.y)) + boundary.p1.y;
	return (dst);
}

// time : O(1)
// space: O(1)
t_line	init_float_line(t_complex point_1, t_complex point_2,
	t_line boundary)
{
	t_line	dst;

	dst.p1 = f_complex_to_2d_position(point_1, boundary);
	dst.p2 = f_complex_to_2d_position(point_2, boundary);
	sort_2d_points(&dst);
	return (dst);
}
