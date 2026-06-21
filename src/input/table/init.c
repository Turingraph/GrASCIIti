#include"table.h"

// time : O(1)
// space: O(1)
void	*free_table_fdf(t_table_fdf *src)
{
	if (src == NULL)
		return (NULL);
	if (src->arr != NULL)
		free_2d_arr((void **)src->arr, src->row);
	if (src->r != NULL)
		free_2d_arr((void **)src->r, src->row);
	if (src->g != NULL)
		free_2d_arr((void **)src->g, src->row);
	if (src->b != NULL)
		free_2d_arr((void **)src->b, src->row);
	if (src->a != NULL)
		free_2d_arr((void **)src->a, src->row);
	src->arr = NULL;
	src->r = NULL;
	src->g = NULL;
	src->b = NULL;
	src->a = NULL;
	src->row = 0;
	src->col = 0;
	return (NULL);
}

// time : O(n)
// space: O(n)
t_table_fdf	init_table_fdf(size_t row, size_t col, e_bool is_rgb)
{
	t_table_fdf	dst;

	dst.r = NULL;
	dst.g = NULL;
	dst.b = NULL;
	dst.a = NULL;
	dst.arr = init_2d_int_arr(row, col);
	dst.row = row;
	dst.col = col;
	if (is_rgb == TRUE)
	{
		dst.r = init_2d_uchar_arr(row, col);
		dst.g = init_2d_uchar_arr(row, col);
		dst.b = init_2d_uchar_arr(row, col);
		dst.a = init_2d_uchar_arr(row, col);
	}
	if (dst.arr == NULL || dst.col < 1 || dst.row < 1)
		free_table_fdf(&dst);
	return (dst);
}

// time : O(n)
// space: O(1)
size_t	load_fdf_col(t_load_fdf_arr src)
{
	size_t	i;
	size_t	col;

	col = 0;
	i = 0;
	while (i < src.length && src.arr != NULL)
	{
		if (col < src.arr[i].length)
			col  = src.arr[i].length;
		i += 1;
	}
	return (col);
}

// time : O(n)
// space: O(1)
void	load_and_save_rgb(t_load_fdf_arr src, t_table_fdf dst, size_t row, size_t col)
{
	if (row < dst.row && col < dst.col && row < src.length
		&& src.arr != NULL && col < src.arr[row].length)
	{
		if (dst.r != NULL && dst.r[row] != NULL && src.arr[row].r != NULL)
			dst.r[row][col] = src.arr[row].r[col];
		if (dst.g != NULL && dst.g[row] != NULL && src.arr[row].g != NULL)
			dst.g[row][col] = src.arr[row].g[col];
		if (dst.b != NULL && dst.b[row] != NULL && src.arr[row].b != NULL)
			dst.b[row][col] = src.arr[row].b[col];
		if (dst.a != NULL && dst.a[row] != NULL && src.arr[row].a != NULL)
			dst.a[row][col] = src.arr[row].a[col];
	}
}

// time : O(n)
// space: O(1)
t_table_fdf	load_table_fdf(t_load_fdf_arr src, e_bool is_rgb)
{
	t_table_fdf	dst;
	size_t		i;
	size_t		j;

	dst = init_table_fdf(src.length, load_fdf_col(src), is_rgb);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src.length && src.arr != NULL)
	{
		j = 0;
		while (j < src.arr[i].length && src.arr[i].arr != NULL)
		{
			dst.arr[i][j] = src.arr[i].arr[j];
			if (is_rgb == TRUE)
				load_and_save_rgb(src, dst, i, j);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
