#include"convolution.h"

// https://en.wikipedia.org/wiki/Kernel_(image_processing)#/media/File:2D_Convolution_Animation.gif

// time : O(n)
// space: O(1)
void	row_of_src_kernel_int(int *src, double *dst, size_t col, size_t max_col)
{
	size_t	i;
	size_t	i_l;
	size_t	i_r;
	size_t	half_dim;

	half_dim = (size_t)f_floor(dst[0]);
	i = 0;
	while (i <= half_dim)
	{
		i_l = 0;
		if (i <= col)
			i_l = col - i;
		i_r = max_col - 1;
		if (col + i < max_col)
			i_r = col + i;
		dst[half_dim - i] = (double)src[i_l];
		dst[half_dim + i] = (double)src[i_r];
		i += 1;
	}
}

// time : O(n)
// space: O(n)
double	**src_kernel_int(t_table_fdf src, size_t row, size_t col, size_t half_dim)
{
	size_t	i;
	size_t	i_w;
	size_t	i_s;
	double	**dst;

	dst = blur_kernel_2d(2 * half_dim + 1, (double)half_dim);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i <= half_dim)
	{
		i_w = 0;
		if (i <= row)
			i_w = row - i;
		i_s = src.row - 1;
		if (row + i < src.row)
			i_s = row + i;
		row_of_src_kernel_int(src.arr[i_w], dst[half_dim - i], col, src.col);
		if (i != 0)
			row_of_src_kernel_int(src.arr[i_s], dst[half_dim + i], col, src.col);
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(1)
void	row_of_src_kernel_char(unsigned char *src, double *dst, size_t col, size_t max_col)
{
	size_t	i;
	size_t	i_l;
	size_t	i_r;
	size_t	half_dim;

	half_dim = (size_t)f_floor(dst[0]);
	i = 0;
	while (i <= half_dim)
	{
		i_l = 0;
		if (i <= col)
			i_l = col - i;
		i_r = max_col - 1;
		if (col + i < max_col)
			i_r = col + i;
		dst[half_dim - i] = (double)src[i_l];
		dst[half_dim + i] = (double)src[i_r];
		i += 1;
	}
}

// time : O(n)
// space: O(n)
double	**src_kernel_char(t_table_char src, size_t row, size_t col, size_t half_dim)
{
	size_t		i;
	size_t		i_w;
	size_t		i_s;
	double		**dst;

	dst = blur_kernel_2d(2 * half_dim + 1, (double)half_dim);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i <= half_dim)
	{
		i_w = 0;
		if (i <= row)
			i_w = row - i;
		i_s = src.row - 1;
		if (row + i < src.row)
			i_s = row + i;
		row_of_src_kernel_char(src.arr[i_w], dst[half_dim - i], col, src.col);
		if (i != 0)
			row_of_src_kernel_char(src.arr[i_s], dst[half_dim + i], col, src.col);
		i += 1;
	}
	return (dst);
}
