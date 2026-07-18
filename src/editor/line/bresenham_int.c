#include"line.h"

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
void	bresenham_int_x(int *dst, t_line line, t_2d_int table_dim, int ink)
{
	int	pivot;
	int	delta_x;
	int	delta_y;
	int	sign;

	init_swap_bresenham_x()
	// ...
}

// time : O(n * thickness)
// space: O(1)
void	draw_straight_line(t_table_fdf *dst, t_line line, t_line boundary, t_ink ink)
{
	//
}

// time : O(n * thickness)
// space: O(1)
void	draw_islamic_art_row(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink, size_t ith_row)
{
	//
}

// time : O(n * thickness)
// space: O(1)
void	draw_islamic_art(t_table_fdf *dst, t_2d_polygon *polygon, t_ink ink)
{
	//
}
