#include"raster_private.h"

/*
dx = x2 - x1
dy = y2 - y1
d = dy / dx
yi + y1 <= d (i + 1) + y1 <= yi + y1 + 1
yi <= d (i + 1) <= yi + 1
low <= mid <= high
high - mid < mid - low

void	draw_line()
{
	while (i <= x2 - x1)
	{
		dst[yi][i] = ink;
		if (high - mid < mid - low)
			yi += 1;
		i += 1;
	}
}

0 < 2mid - low - high
0 < 2 d (i + 1) - 2 yi - 1
0 < 2 dy (i + 1) - 2 dx yi - dx

define: g(i, yi) = 2 dy (i + 1) - 2 dx yi - dx
*	g(i, 0) = 2 dy i + 2 dy - dx
*	g(0, 0) = 2 dy - dx
*	g(i + 1, j) = g(i, j) + 2 dy
*	g(i, j + 1) = g(i, j) - 2 dx

Reference
*	https://youtu.be/CceepU1vIKo?si=h9zAxMM_4gDwWVDU
*/

// time : O(n)
// space: O(1)
void	bresenham_mlx_x(mlx_image_t *dst,
	t_line line, t_boundary boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = init_swap_bresenham_x(&line, &delta_x, &delta_y);
	if (sign == 2 || sign == -2)
	{
		line = reverse_line(line);
		sign /= 2;
	}
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.x <= line.p2.x)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < sign * pivot)
		{
			pivot -= 2 * delta_x * sign;
			line.p1.y += sign;
		}
		pivot += 2 * delta_y;
		line.p1.x += 1;
	}
}

// time : O(n)
// space: O(1)
void	bresenham_mlx_y(mlx_image_t *dst,
	t_line line, t_boundary boundary, int32_t color)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	sign = init_swap_bresenham_y(&line, &delta_x, &delta_y);
	if (sign == 2 || sign == -2)
	{
		line = reverse_line(line);
		sign /= 2;
	}
	pivot = 2 * delta_y - delta_x;
	while (dst != NULL && line.p1.y <= line.p2.y)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		if (0 < sign * pivot)
		{
			pivot -= 2 * delta_x * sign;
			line.p1.x += sign;
		}
		pivot += 2 * delta_y;
		line.p1.y += 1;
	}
}

// time : O(n * thickness)
// space: O(1)
void	bresenham_mlx_x_thick(mlx_image_t *dst, t_line line, t_boundary boundary, t_ink32 ink)
{
	size_t	i;
	t_line	parallel;

	if (dst != NULL
		&& f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
	{
		bresenham_mlx_x(dst, line, boundary, ink.color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.y += 1;
			line.p2.y += 1;
			bresenham_mlx_x(dst, line, boundary, ink.color);
			parallel.p1.y -= 1;
			parallel.p2.y -= 1;
			bresenham_mlx_x(dst, parallel, boundary, ink.color);
			i += 1;
		}
	}
}

// time : O(n * thickness)
// space: O(1)
void	bresenham_mlx_y_thick(mlx_image_t *dst, t_line line, t_boundary boundary, t_ink32 ink)
{
	size_t	i;
	t_line	parallel;

	if (dst != NULL
		&& f_abs(line.p2.x - line.p1.x) < f_abs(line.p2.y - line.p1.y))
	{
		bresenham_mlx_y(dst, line, boundary, ink.color);
		parallel = line;
		i = 0;
		while (i < ink.thickness / 2)
		{
			line.p1.x += 1;
			line.p2.x += 1;
			bresenham_mlx_y(dst, line, boundary, ink.color);
			parallel.p1.x -= 1;
			parallel.p2.x -= 1;
			bresenham_mlx_y(dst, parallel, boundary, ink.color);
			i += 1;
		}
	}
}

/**
 * Draw a straight line with configurable thickness.
 *
 * The line is first restricted to the destination boundary and then
 * rendered using the Bresenham algorithm. 
 * Thick lines receive circular end caps to produce a rounded appearance.
 *
 * time/space: O(n * thickness) / O(1)
 *
 * status: internal helper
 *
 * @param dst destination MLX image
 * @param line line to draw
 * @param rectangle_boundary area in which the line is allowed to be drawn
 * @param ink drawing style containing the color and line thickness
 */
void	draw_mlx_straight_line(mlx_image_t *dst, t_line line,
	t_line rectangle_boundary, t_ink32 ink)
{
	t_boundary	boundary;
	t_circle	end_point;

	if (dst != NULL)
	{
		boundary = init_rectangle_boundary(rectangle_boundary,
				dst->height, dst->width);
		line = init_first_line(line, boundary);
		if (f_abs(line.p2.x - line.p1.x) >= f_abs(line.p2.y - line.p1.y))
			bresenham_mlx_x_thick(dst, line, boundary, ink);
		else
			bresenham_mlx_y_thick(dst, line, boundary, ink);
		end_point.radius = ink.thickness / 2 - 1;
		end_point.x = line.p1.x;
		end_point.y = line.p1.y;
		if (ink.thickness > 1)
			midpoint_circle_mlx(dst, ink.color, end_point, boundary);
		end_point.x = line.p2.x;
		end_point.y = line.p2.y;
		if (ink.thickness > 1)
			midpoint_circle_mlx(dst, ink.color, end_point, boundary);
	}
}