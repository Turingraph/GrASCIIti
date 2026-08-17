#include"view_line.h"

// time : O(n)
// space: O(1)
void	draw_horizontal_mlx(mlx_image_t *dst, t_line line,
	int32_t color, t_boundary boundary)
{
	int	temp;

	if (line.p1.x > line.p2.x)
	{
		temp = line.p2.x;
		line.p2.x = line.p1.x;
		line.p1.x = temp;
		temp = line.p2.y;
		line.p2.y = line.p1.y;
		line.p1.y = temp;
	}
	while (line.p1.x <= line.p2.x && dst != NULL)
	{
		if (is_in_boundary(line.p1.x, line.p1.y, boundary.sub_area) == true)
			mlx_put_pixel(dst, line.p1.x, line.p1.y, color);
		line.p1.x += 1;
	}
}

/*
In order to draw the circle,
this equation must be satisfy x^2 + (y + 0.5)^2 = r^2, where
*	r = radius
*	y + 0.5 because there are 50% chance
		that we color the pixel on the y + 1 th row.

We can check if the point outside the circle
or not by using Pythagorian theorem, such that
*	if x^2 + y^2 > r^2 means the point is outside the circle.

if (x^2 + (y + 0.5)^2 > r^2)
{
	y += 1;
}

In other words

if (x^2 + (y + 0.5)^2 - r^2 > 0)
{
	y += 1;
}

During first iteration
*	x = 0
*	y = -r (because we have to calculate the 2d position
		of the top point of the circle)

Calculating this inequality when y = -r and x = 0.
*	x^2 + (y + 0.5)^2 - r^2 > 0
*	(y + 0.5)^2 - r^2 > 0
*	y^2 + y + 0.25 - r^2 > 0
*	r^2 - r + 0.25 - r^2 > 0
*	- r + 0.25 > 0
*	- r > 0 (we can ignore the constent term to gain more efficiency)

So we can define 
*	pivot = -r

However, we have to update the pivot after each iteration.

One way to do this is the update team such that
*	new term = (new term - current term) + current term

define: g(x, y) = x^2 + (y + 0.5)^2 - r^2, then
*	g(i + 1, j) = i^2 + 2i + 1 + (j + 0.5)^2 - r^2 = g(i, j) + 2i + 1
*	g(i, j + 1) = i^2 + j^2 + 3j + 1.5^2 - r^2 = g(i, j) + 2j + 2

ChatGPT said that we have to loop 

while (dst != NULL && ix <= -1 * iy)
{
	...
}

inspired of 

while (dst != NULL && ix <= point.radius)
{
	...
}

Even through point.radius equal to the initial value of -1 * iy,
because you have to loop the circle for 45 degree, and
unlike point.radius, iy is updated.

Reference
*	https://www.youtube.com/watch?v=hpiILbMkF9w
*/

// time : O(r^2)
// space: O(1)
void	midpoint_circle_mlx(mlx_image_t *dst,
	int32_t color, t_circle point, t_boundary boundary)
{
	int		ix;
	int		iy;
	int		pivot;
	t_line	line;

	pivot = point.radius * -1;
	iy = -1 * point.radius;
	ix = 0;
	while (dst != NULL && ix <= -1 * iy)
	{
		line = define_circle_boundary(point, ix, iy, 0);
		draw_horizontal_mlx(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 1);
		draw_horizontal_mlx(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 2);
		draw_horizontal_mlx(dst, line, color, boundary);
		line = define_circle_boundary(point, ix, iy, 3);
		draw_horizontal_mlx(dst, line, color, boundary);
		if (pivot > 0)
			iy += 1;
		if (pivot > 0)
			pivot += 2 * iy + 2;
		ix += 1;
		pivot += 2 * ix + 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_kusama_tiling_fmlx_unit(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_line boundary)
{
	size_t		i;
	t_line		line;
	t_circle	circle;
	t_boundary	sub_area;

	i = 0;
	while (dst != NULL && polygon != NULL && i < polygon->length)
	{
		sub_area = init_rectangle_boundary(boundary,
				dst->height, dst->width);
		line = init_float_line(polygon->arr[i], polygon->arr[i], boundary);
		line = init_rectangle(line, sub_area);
		circle.radius = ink.thickness;
		circle.x = line.p1.x;
		circle.y = line.p1.y;
		midpoint_circle_mlx(dst, ink.color, circle, sub_area);
		i += 1;
	}
}

// time : O(n)
// sapce: O(1)
void	draw_kusama_tiling_fmlx(mlx_image_t *dst, const t_2d_polygon *polygon,
	t_ink32 ink, t_2d_int tiling_area)
{
	size_t	i;
	size_t	j;
	t_line	tiling;

	i = 0;
	while (dst != NULL && polygon != NULL && tiling_area.y > 0
		&& i < f_floor(dst->height / tiling_area.y) + 1)
	{
		j = 0;
		while (tiling_area.x > 0 && j < f_floor(dst->width / tiling_area.x) + 1)
		{
			tiling = get_tiling(tiling_area, i, j);
			draw_kusama_tiling_fmlx_unit(dst, polygon, ink, tiling);
			j += 1;
		}
		i += 1;
	}
}
