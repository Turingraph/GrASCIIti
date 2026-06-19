#include"table.h"

// time : O(n)
// space: O(n)
t_table_fdf	scale_dimension_fdf(t_table_fdf src, size_t scale_dim)
{
	t_table_fdf	dst;
	size_t		i;
	size_t		j;
	char		is_rgb;

	is_rgb = 0;
	if (src.r != NULL || src.g != NULL || src.b != NULL || src.a != NULL)
		is_rgb = 1;
	dst = init_table_fdf(src.row * scale_dim, src.col * scale_dim, is_rgb);
	if (dst.arr == NULL)
	{
		free_table_fdf(&dst);
		return (dst);
	}
	i = 0;
	while (i < src.row && src.arr != NULL)
	{
		j = 0;
		while (j < scale_dim)
		{
			copy_int_arr(dst.arr[i * scale_dim + j], src.arr[i], src.col, scale_dim);
			if (is_rgb > 0)
			{
				copy_uchar_arr(dst.r[i * scale_dim + j], src.r[i], src.col, scale_dim);
				copy_uchar_arr(dst.g[i * scale_dim + j], src.g[i], src.col, scale_dim);
				copy_uchar_arr(dst.b[i * scale_dim + j], src.b[i], src.col, scale_dim);
				copy_uchar_arr(dst.a[i * scale_dim + j], src.a[i], src.col, scale_dim);
			}
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	scale_addition_fdf(t_table_fdf *src, int scale)
{
	size_t	i;
	size_t	j;
	long	check;

	i = 0;
	while (i < src->row && src->arr != NULL)
	{
		j = 0;
		while (j < src->col && src->arr[i] != NULL)
		{
			check = src->arr[i][j] + scale;
			if (check > (long)2147483647)
				write(1, "Warning: Some Integer of the Table is greater than 2147483647.\n", 64);
			else if (check < (long)-2147483648)
				write(1, "Warning: Some Integer of the Table is less than -2147483648.\n", 62);
			else
				src->arr[i][j] = (int)check;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_hadamard_fdf(t_table_fdf *src, float scale)
{
	size_t	i;
	size_t	j;
	long	check;

	i = 0;
	while (i < src->row && src->arr != NULL)
	{
		j = 0;
		while (j < src->col && src->arr[i] != NULL)
		{
			check = (long)f_floor((float)src->arr[i][j] * scale);
			if (check > (long)2147483647)
				write(1, "Warning: Some Integer of the Table is greater than 2147483647.\n", 64);
			else if (check < (long)-2147483648)
				write(1, "Warning: Some Integer of the Table is less than -2147483648.\n", 62);
			else
				src->arr[i][j] = (int)check;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
void	scale_relu_fdf(t_table_fdf *src, int min, int max, int expect)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < src->row && src->arr != NULL)
	{
		j = 0;
		while (j < src->col && src->arr[i] != NULL)
		{
			if (min <= src->arr[i][j] && src->arr[i][j] <= max)
				src->arr[i][j] = expect;
			j += 1;
		}
		i += 1;
	}
}

// time : O(n)
// space: O(1)
size_t	scale_positive_fdf(t_table_fdf *src, char update)
{
	long	min;
	size_t	i;
	size_t	j;

	min = 0;
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			if (min > src->arr[i][j])
				min = src->arr[i][j];
			j += 1;
		}
		i += 1;
	}
	min *= -1;
	if (update == 1 && min <= (long)2147483647)
		scale_addition_fdf(src, min);
	return (min);
}
