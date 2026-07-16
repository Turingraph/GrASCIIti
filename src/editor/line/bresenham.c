#include"line.h"

// time : O(1)
// space: O(1)
void	sort_line_index(t_line *line, char dim)
{
	int	temp;

	if (line != NULL && ((line->x1 > line->x2 && dim == 0) || (line->y1 > line->y2 && dim == 1)))
	{
		temp = line->x1;
		line->x1 = line->x2;
		line->x2 = temp;
		temp = line->y2;
		line->y2 = line->y1;
		line->y1 = temp;
	}
}

/*
The purpose of this algorithm is to draw the line.

This implementation can only draw diagonal line and horizontal line.

dx = x2 - x1
dy = y2 - y1
d = dy / dx where d in [0, 1]

yi + y1 <= d (i + 1) + y1 <= yi + y1 + 1
yi <= d (i + 1) <= yi + 1
i <= d (i + 1) <= i + 1
low <= mid <= high
if high - mid < mid - low, then add y with 1.
0 < 2mid - low - high
0 < 2d (i + 1) - 2yi - 1
0 < 2dy (i + 1) - 2dx yi - dx

Define: g(i, yi) = 2dy (i + 1) - 2dx yi - dx
*	g(0,0) = 2dy - dx

if y1 += 1, then
*	yi += 1;
*	pivot += -2dx;

if i += 1, then
*	pivot += 2dy;

Reference
*	https://youtu.be/CceepU1vIKo?si=J4eym48r-nZ4kCmt
*/

// time : O(n)
// space: O(1)
void	bresenham_line_int_x(int *dst, t_line line)
{
	int	delta_x;
	int	delta_y;
	int	pivot;
	int	sign;

	if (dst != NULL)
	{
		sort_line_index(&line, 0);
		delta_x = line.x2 - line.x1;
		delta_y = line.y2 - line.y1;
		sign = 1;
		if (delta_y < 0)
			sign = -1;
		pivot = 2 * delta_y - delta_x;
		while (line.x1 <= line.x2 && line.x1 < line.row && line.y1 < line.col)
		{
			dst[line.y1 * line.col + line.x1] = line.dark;
			if (0 < sign * pivot)
			{
				pivot -= 2 * delta_x * sign;
				line.y1 += sign;
			}
			pivot += 2 * delta_y;
			line.x1 += 1;
		}
	}
}

// time : O(n)
// space: O(1)
void	bresenham_line_int_y(int *dst, t_line line)
{
	int	delta_x;
	int	delta_y;
	int	pivot;
	int	sign;

	if (dst != NULL)
	{
		sort_line_index(&line, 1);
		delta_x = line.y2 - line.y1;
		delta_y = line.x2 - line.x1;
		sign = 1;
		if (delta_y < 0)
			sign = -1;
		pivot = 2 * delta_y - delta_x;
		while (line.y1 <= line.y2 && line.y1 < line.row && line.x1 < line.col)
		{
			dst[line.x1 * line.col + line.y1] = line.dark;
			if (0 < sign * pivot)
			{
				pivot -= 2 * delta_x * sign;
				line.x1 += sign;
			}
			pivot += 2 * delta_y;
			line.y1 += 1;
		}
	}
}

// time : O(n)
// space: O(1)
void	bresenham_line_uchar_x(unsigned char *dst, t_line line)
{
	int	delta_x;
	int	delta_y;
	int	pivot;
	int	sign;

	if (dst != NULL)
	{
		sort_line_index(&line, 0);
		delta_x = line.x2 - line.x1;
		delta_y = line.y2 - line.y1;
		sign = 1;
		if (delta_y < 0)
			sign = -1;
		pivot = 2 * delta_y - delta_x;
		while (line.x1 <= line.x2 && line.x1 < line.row && line.y1 < line.col)
		{
			dst[line.y1 * line.col + line.x1] = (unsigned char)f_interval(line.dark, 0, 255);
			if (0 < sign * pivot)
			{
				pivot -= 2 * delta_x * sign;
				line.y1 += sign;
			}
			pivot += 2 * delta_y;
			line.x1 += 1;
		}
	}
}

// time : O(n)
// space: O(1)
void	bresenham_line_uchar_y(unsigned char *dst, t_line line)
{
	int	delta_x;
	int	delta_y;
	int	pivot;
	int	sign;

	if (dst != NULL)
	{
		sort_line_index(&line, 1);
		delta_x = line.y2 - line.y1;
		delta_y = line.x2 - line.x1;
		sign = 1;
		if (delta_y < 0)
			sign = -1;
		pivot = 2 * delta_y - delta_x;
		while (line.y1 <= line.y2 && line.y1 < line.row && line.x1 < line.col)
		{
			dst[line.x1 * line.col + line.y1] = (unsigned char)f_interval(line.dark, 0, 255);
			if (0 < sign * pivot)
			{
				pivot -= 2 * delta_x * sign;
				line.x1 += sign;
			}
			pivot += 2 * delta_y;
			line.y1 += 1;
		}
	}
}
