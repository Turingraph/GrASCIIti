#include"convolution.h"

// time : O(n)
// space: O(1)
double	dot_product_2d(double **a, double **b, size_t row, size_t col)
{
	double	y;
	size_t	i;
	size_t	j;

	y = 0;
	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < col)
		{
			y += a[i][j] * b[i][j];
			j += 1;
		}
		i += 1;
	}
	return (y);
}

// time : O(n * k^2)
// space: O(n)
t_table_fdf	convolution_hight(t_table_fdf src, double **kernel, size_t half_dim)
{
	t_table_fdf	dst;
	double		**src_kernel;
	size_t		i;
	size_t		j;

	dst = scale_dimension_fdf(src, 1);
	if (dst.arr == NULL)
		return (dst);
	i = 0;
	while (i < src.row)
	{
		j = 0;
		while (j < src.col)
		{
			src_kernel = src_kernel_int(src, i, j, half_dim);
			if (src_kernel == NULL)
				return (dst);
			dst.arr[i][j] = (int)f_round(dot_product_2d(src_kernel,
				kernel, 2 * half_dim + 1, 2 * half_dim + 1));
			free_2d_arr((void **)src_kernel, 2 * half_dim + 1);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
unsigned char	**choose_rgb_table_fdf(t_table_fdf src, char rgb_type)
{
	if (rgb_type == 'b')
		return (src.b);
	if (rgb_type == 'g')
		return (src.g);
	if (rgb_type == 'a')
		return (src.a);
	return (src.r);
}

// time : O(1)
// space: O(1)
t_table_rgba	init_table_rgb(size_t row, size_t col, unsigned char **rgb_arr)
{
	t_table_rgba	dst;

	dst.row = row;
	dst.col = col;
	dst.arr = rgb_arr;
	return (dst);
}

// time : O(n * k^2)
// space: O(n)
t_table_fdf	convolution_rgb(t_table_fdf src, double **kernel, size_t half_dim, char rgb_type)
{
	t_table_fdf		dst;
	t_table_rgba	src_arr;
	double			**src_kernel;
	size_t			i;
	size_t			j;

	dst = scale_dimension_fdf(src, 1);
	if (dst.arr == NULL || choose_rgb_table_fdf(src, rgb_type) == NULL)
		return (dst);
	src_arr = init_table_rgb(src.row, src.col, choose_rgb_table_fdf(src, rgb_type));
	i = 0;
	while (i < src.row && src_arr.arr != NULL)
	{
		j = 0;
		while (j < src.col)
		{
			src_kernel = src_kernel_char(src_arr, i, j, half_dim);
			if (src_kernel == NULL)
				return (dst);
			choose_rgb_table_fdf(dst, rgb_type)[i][j] = (unsigned char)f_interval(
				f_round(dot_product_2d(src_kernel, 
				kernel, 2 * half_dim + 1, 2 * half_dim + 1)), 0, 255);
			free_2d_arr((void **)src_kernel, 2 * half_dim + 1);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}
