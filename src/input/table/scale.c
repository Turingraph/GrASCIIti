#include "table.h"

// time : O(n)
// space: O(1)
void	copy_duplicated_row_rgba(const unsigned char *src, unsigned char *dst,
	size_t max_col, size_t scale_col)
{
	size_t	i;
	size_t	ii;

	i = 0;
	while (src != NULL && dst != NULL && i < max_col)
	{
		ii = 0;
		while (ii < scale_col)
		{
			*(dst + scale_col * i + ii) = *(src + i);
			ii += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	copy_duplicated_row(const int *src, int *dst,
	size_t max_col, size_t scale_col)
{
	size_t	i;
	size_t	ii;

	i = 0;
	while (src != NULL && dst != NULL && i < max_col)
	{
		ii = 0;
		while (ii < scale_col)
		{
			*(dst + scale_col * i + ii) = *(src + i);
			ii += 1;
		}
		i += 1;
	}
}

// time : O(n^3)
// space: O(n^3)
t_table_fdf	scale_dimension_fdf(const t_table_fdf *src, size_t scale_row, size_t scale_col)
{
	size_t		i;
	size_t		ii;
	t_table_fdf	dst;

	if (src == NULL || src->row == 0 || src->col == 0 || src->arr == NULL)
		return (init_table_fdf(0, 0, false));
	dst = init_table_fdf(src->row * scale_row, src->col * scale_col, true);
	i = 0;
	while (i < src->row)
	{
		ii = 0;
		while (ii < scale_row)
		{
			copy_duplicated_row(src->arr + i * src->col,
				dst.arr + (i * scale_row + ii) * dst.col, src->col, scale_col);
			if (src->r != NULL && dst.r != NULL)
				copy_duplicated_row_rgba(src->r + i * src->col,
				dst.r + (i * scale_row + ii) * dst.col, src->col, scale_col);
			if (src->g != NULL && dst.g != NULL)
				copy_duplicated_row_rgba(src->g + i * src->col,
				dst.g + (i * scale_row + ii) * dst.col, src->col, scale_col);
			if (src->b != NULL && dst.b != NULL)
				copy_duplicated_row_rgba(src->b + i * src->col,
				dst.b + (i * scale_row + ii) * dst.col, src->col, scale_col);
			if (src->a != NULL && dst.a != NULL)
				copy_duplicated_row_rgba(src->a + i * src->col,
				dst.a + (i * scale_row + ii) * dst.col, src->col, scale_col);
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
			dst->arr[i] = (int)f_interval(f_round((float)dst->arr[i] * scale), -2147483648.0, 2147483647.0);
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
			dst->arr[i] = (int)f_interval(f_round(dst->arr[i] + input), -2147483648.0, 2147483647.0);
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
