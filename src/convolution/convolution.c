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
t_table_fdf	*convolution_hight(t_table_fdf *src, double **kernel, size_t half_dim)
{
	t_table_fdf	*dst;
	double		**src_kernel;
	size_t		i;
	size_t		j;

	dst = scale_dimension_fdf(src, 1, 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < src->row)
	{
		j = 0;
		while (j < src->col)
		{
			src_kernel = src_kernel_int(src, i, j, half_dim);
			if (src_kernel == NULL)
				return (dst);
			dst->arr[i][j] = (int)f_round(dot_product_2d(src_kernel,
				kernel, 2 * half_dim + 1, 2 * half_dim + 1));
			free_nest_arr((void **)src_kernel, 2 * half_dim + 1);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(1)
// space: O(1)
t_table_char	*table_fdf_to_table_char(t_table_fdf *src, char rgb_type)
{
	unsigned char	**arr;
	t_table_char	*dst;

	arr = src->r;
	if (rgb_type == 'b')
		arr = src->b;
	if (rgb_type == 'g')
		arr = src->g;
	if (rgb_type == 'a')
		arr = src->a;
	dst = malloc_talk(sizeof(t_table_char),
		"convolution/convolution.c/table_fdf_to_table_char\n");
	if (dst == NULL)
		return (NULL);
	dst->row = src->row;
	dst->col = src->col;
	dst->arr = arr;
	return (dst);
}

// time : O(1)
// space: O(1)
unsigned char	**choose_rgb_table_fdf(t_table_fdf *src, char rgb_type)
{
	if (rgb_type == 'b')
		return (src->b);
	if (rgb_type == 'g')
		return (src->g);
	if (rgb_type == 'a')
		return (src->a);
	return (src->r);
}

// time : O(n * k^2)
// space: O(n)
t_table_fdf	*convolution_rgb(t_table_fdf *src, double **kernel, size_t half_dim, char rgb_type)
{
	t_table_fdf		*dst;
	t_table_char	*src_arr;
	double			**src_kernel;
	size_t			i;
	size_t			j;

	dst = scale_dimension_fdf(src, 1, 1);
	if (dst == NULL)
		return (NULL);
	src_arr = table_fdf_to_table_char(src, rgb_type);
	i = 0;
	while (i < src->row && src_arr != NULL)
	{
		j = 0;
		while (j < src->col)
		{
			src_kernel = src_kernel_char(src_arr, i, j, half_dim);
			if (src_kernel == NULL)
			{
				free(src_arr);
				return (dst);
			}
			(choose_rgb_table_fdf(dst, rgb_type))[i][j] = (unsigned char)f_interval(
				f_round(dot_product_2d(src_kernel, 
				kernel, 2 * half_dim + 1, 2 * half_dim + 1)), 0, 255);
			free_nest_arr((void **)src_kernel, 2 * half_dim + 1);
			j += 1;
		}
		i += 1;
	}
	if (src_arr != NULL)
		free(src_arr);
	return (dst);
}
