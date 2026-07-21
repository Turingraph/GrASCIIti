#include"line.h"

// time : O(1)
// space: O(1)
t_2d_int	f_complex_to_2d_position(t_complex src,
	t_line boundary)
{
	t_2d_int	dst;

	src.re = f_interval(src.re, 0, 1);
	src.im = f_interval(src.im, 0, 1);
	dst.x = (int)f_floor(src.re * (boundary.p2.x - boundary.p1.x)) + boundary.p1.x;
	dst.y = (int)f_floor(src.im * (boundary.p2.y - boundary.p1.y)) + boundary.p1.y;
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
	write(1, ">>> [", 5);
	ft_putnbr_fd(dst.p1.x, 1, "0123456789", 2);
	write(1, ", ", 2);
	ft_putnbr_fd(dst.p1.y, 1, "0123456789", 2);
	write(1, "] --> [", 8);
	ft_putnbr_fd(dst.p2.x, 1, "0123456789", 2);
	write(1, ", ", 2);
	ft_putnbr_fd(dst.p2.y, 1, "0123456789", 2);
	write(1, "]\n", 2);
	return (dst);
}

// time : O(n)
// sapce: O(1)
void	draw_polygon(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink, t_line rectangle_boundary)
{
	size_t		i;
	t_line		line;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length - 1)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[i + 1], rectangle_boundary);
		draw_straight_line(dst, line, rectangle_boundary, ink);
		i += 1;
	}
	if (dst != NULL && polygon != NULL && i == polygon->length - 1 && polygon->is_loop == true)
	{
		line = init_float_line(polygon->arr[i], polygon->arr[0], rectangle_boundary);
		draw_straight_line(dst, line, rectangle_boundary, ink);
	}
}

// time : O(n)
// sapce: O(1)
void	draw_square_tiling(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && polygon != NULL && tiling_area.y > 0 && i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling.p1.x = tiling_area.x * j;
			tiling.p1.y = tiling_area.y * i;
			tiling.p2.x = tiling_area.x * (j + 1);
			tiling.p2.y = tiling_area.y * (i + 1);
			draw_polygon(dst, polygon, ink, tiling);
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_kusama_circle(t_table_fdf *dst, t_circle circle, t_ink ink, t_2d_int tiling_area)
{
	size_t		i;
	size_t		j;
	t_line		tiling;
	t_circle	point;
	t_boundary	boundary;

	if (ink.channel != HEIGHT)
		ink.color = (int)f_interval(ink.color, 0, 255);
	point.radius = circle.radius;
	i = 0;
	while (dst != NULL && tiling_area.y > 0 && tiling_area.x > 0
		&& i < f_floor(dst->row / tiling_area.y) + 1)
	{
		j = 0;
		while (j < f_floor(dst->col / tiling_area.x) + 1)
		{
			tiling.p1.x = tiling_area.x * j;
			tiling.p1.y = tiling_area.y * i;
			tiling.p2.x = tiling_area.x * (j + 1);
			tiling.p2.y = tiling_area.y * (i + 1);
			boundary = init_rectangle_boundary(tiling, dst->row, dst->col);
			point.x = (int)f_interval(circle.x, 0,
					boundary.sub_area.p2.x - boundary.sub_area.p1.x) + boundary.sub_area.p1.x;
			point.y = (int)f_interval(circle.y, 0,
					boundary.sub_area.p2.y - boundary.sub_area.p1.y) + boundary.sub_area.p1.y;
			if (ink.channel == HEIGHT && dst->arr != NULL)
				midpoint_circle_int(dst->arr, ink.color, point, boundary);
			if (ink.channel == RED && dst->r != NULL)
				midpoint_circle_uchar(dst->r, (unsigned char)ink.color, point, boundary);
			if (ink.channel == GREEN && dst->g != NULL)
				midpoint_circle_uchar(dst->g, (unsigned char)ink.color, point, boundary);
			if (ink.channel == BLUE && dst->b != NULL)
				midpoint_circle_uchar(dst->b, (unsigned char)ink.color, point, boundary);
			if (ink.channel == ALPHA && dst->a != NULL)
				midpoint_circle_uchar(dst->a, (unsigned char)ink.color, point, boundary);
			j += 1;
		}
		i += 1;
	}
}

