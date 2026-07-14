#include "table.h"

// time : O(n^3)
// space: O(n^3)
t_table_fdf	scale_dimension_fdf(const t_table_fdf *src, size_t scale_row, size_t scale_col)
{
	t_table_fdf	dst;
	size_t		i;
	size_t		ii;
	size_t		j;
	size_t		jj;

	i = 0;
	j = 0;
	if (src != NULL)
	{
		i = src->row * scale_row;
		j = src->col * scale_col;
	}
	dst = init_table_fdf(i, j, true);
	if (dst.arr == NULL || src == NULL || src->arr == NULL)
		return (dst);
	i = 0;
	while (i < src->row)
	{
		ii = 0;
		while (ii < scale_row)
		{
			j = 0;
			while (j < src->col)
			{
				jj = 0;
				while (jj < scale_col && dst.arr != NULL && src->arr != NULL)
				{
					dst.arr[scale_col * (dst.col * (scale_row * i + ii) + j) + jj] = src->arr[src->col * i + j];
					if (dst.r != NULL && src->r != NULL)
						dst.r[scale_col * (dst.col * (scale_row * i + ii) + j) + jj] = src->r[src->col * i + j];
					if (dst.g != NULL && src->g != NULL)
						dst.g[scale_col * (dst.col * (scale_row * i + ii) + j) + jj] = src->g[src->col * i + j];
					if (dst.b != NULL && src->b != NULL)
						dst.b[scale_col * (dst.col * (scale_row * i + ii) + j) + jj] = src->b[src->col * i + j];
					if (dst.a != NULL && src->a != NULL)
						dst.a[scale_col * (dst.col * (scale_row * i + ii) + j) + jj] = src->a[src->col * i + j];
					jj += 1;
				}
				j += 1;
			}
			ii += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	scale_multiplication_fdf(t_table_fdf *dst, float scale, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(f_round((float)dst->arr[i] * scale), -2147483648.0, 2147483647);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval((float)dst->r[i]* scale, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval((float)dst->g[i]* scale, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval((float)dst->b[i]* scale, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval((float)dst->a[i]* scale, 0, 255);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_addition_fdf(t_table_fdf *dst, int input, e_rgba channels)
{
	size_t	i;

	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && channels == HEIGHT)
			dst->arr[i] = (int)f_interval(f_round(dst->arr[i] + input), -2147483648.0, 2147483647);
		if (dst->r != NULL && channels == RED)
			dst->r[i] = (unsigned char)f_interval((int)dst->r[i] + input, 0, 255);
		if (dst->g != NULL && channels == GREEN)
			dst->g[i] = (unsigned char)f_interval((int)dst->g[i] + input, 0, 255);
		if (dst->b != NULL && channels == BLUE)
			dst->b[i] = (unsigned char)f_interval((int)dst->b[i] + input, 0, 255);
		if (dst->a != NULL && channels == ALPHA)
			dst->a[i] = (unsigned char)f_interval((int)dst->a[i] + input, 0, 255);
		i += 1;
	}
}

// time : O(n)
// space: O(1)
int	get_minmax_from_table_fdf(t_table_fdf *dst, bool is_max, e_rgba channels)
{
	int		sign;
	size_t	i;
	int		y;

	y = 0;
	sign = 1;
	if (is_max == false)
		sign = -1;
	i = 0;
	while (dst != NULL && i < dst->row * dst->col)
	{
		if (dst->arr != NULL && y * sign < dst->arr[i] * sign && channels == HEIGHT)
			y = dst->arr[i];
		if (dst->r != NULL && y * sign < (int)(dst->r[i] * sign) && channels == RED)
			y = (int)dst->r[i];
		if (dst->g != NULL && y * sign < (int)(dst->g[i] * sign) && channels == GREEN)
			y = (int)dst->g[i];
		if (dst->b != NULL && y * sign < (int)(dst->b[i] * sign) && channels == BLUE)
			y = (int)dst->b[i];
		if (dst->a != NULL && y * sign < (int)(dst->a[i] * sign) && channels == ALPHA)
			y = (int)dst->a[i];
		i += 1;
	}
	return (y);
}

// time : O(n)
// space: O(1)
void	scale_positive_fdf(t_table_fdf *dst)
{
	int	y;

	y = get_minmax_from_table_fdf(dst, false, HEIGHT);
	if (y < 0 && y > -2147483648)
		y *= -1;
	else if (y == -2147483648)
		y = 0;
	scale_addition_fdf(dst, y, HEIGHT);
}
