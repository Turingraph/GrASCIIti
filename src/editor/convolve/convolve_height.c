#include"convolve.h"

// time : O(1)
// space: O(1)
int	get_clamped_height(const t_table_fdf *src, int edge_row, int edge_col)
{
	size_t	row;
	size_t	col;
	int		*arr;

	if (src == NULL || src->arr == NULL || src->row == 0 || src->col == 0)
		return (0);
	arr = src->arr;
	if (arr == NULL)
		return (0);
	if (0 <= edge_row && edge_row < (int)src->row && 0 <= edge_col && edge_col < (int)src->col)
		return (arr[edge_row * src->col + edge_col]);
	row = 0;
	if (edge_row > 0 && edge_row < (int)src->row)
		row = edge_row;
	if (edge_row >= (int)src->row)
		row = src->row - 1;
	col = 0;
	if (edge_col > 0 && edge_col < (int)src->col)
		col = edge_col;
	if (edge_col >= (int)src->col)
		col = src->col - 1;
	return (arr[src->col * row + col]);
}

// time : O(n^2)
// space: O(n^2)
t_matrix	init_src_kernel_height(size_t half_dim,
	const t_table_fdf *src, size_t index)
{
	t_matrix	dst;
	size_t		i;
	size_t		j;

	dst = init_matrix(2 * half_dim + 1, 2 * half_dim + 1, 1);
	if (src == NULL || src->arr == NULL || index >= src->col * src->row)
		return (dst);
	i = 0;
	while (i < half_dim)
	{
		j = 0;
		while (j < half_dim)
		{
			dst.arr[(half_dim + i) * dst.col + half_dim + j] = get_clamped_height(src, index / src->col + i, index % src->col + j);
			dst.arr[(half_dim + i) * dst.col + half_dim - j] = get_clamped_height(src, index / src->col + i, index % src->col - j);
			dst.arr[(half_dim - i) * dst.col + half_dim + j] = get_clamped_height(src, index / src->col - i, index % src->col + j);
			dst.arr[(half_dim - i) * dst.col + half_dim - j] = get_clamped_height(src, index / src->col - i, index % src->col - j);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
int	convolve_unit_height(const t_table_fdf *src,
	t_matrix kernel, size_t index)
{
	int			output;
	t_matrix	src_kernel;

	output = 0;
	if (src != NULL && index < src->col * src->row)
	{
		src_kernel = init_src_kernel_height(kernel.col / 2, src, index);
		if (src_kernel.arr != NULL && kernel.arr != NULL)
			output = dot_product((const float *)src_kernel.arr,
					kernel.arr, kernel.col * kernel.col);
		else if (src_kernel.arr != NULL && kernel.arr == NULL)
		{
			kernel = init_src_kernel_height(kernel.col / 2, src, index);
			output = f_sum(kernel.arr, kernel.col * kernel.col);
			if (output > 0.025 || output <= -0.025)
				vector_scale(kernel.arr, 1.0 / output, kernel.col * kernel.col);
			if (kernel.arr != NULL)
				output = (int)f_round(dot_product((const float *)src_kernel.arr,
							kernel.arr, kernel.col * kernel.col));
			free_matrix(&kernel);
		}
		free_matrix(&src_kernel);
	}
	return (output);
}

/**
 * Apply a convolution kernel to HEIGHT channels.
 * 
 * The kernel must be a square matrix with odd dimensions (e.g. 3x3, 5x5).
 * For each pixel, the kernel is centered on that pixel. Samples outside
 * the source image are clamped to the nearest edge pixel.
 * 
 * If kernel.arr is NULL, an adaptive kernel is generated from the local
 * source region instead of treating the kernel as invalid. This allows
 * the same convolution path to be reused for both fixed and adaptive
 * filtering.
 *
 * time/space: O(n * m^2) / O(n)
 * 
 * status: public api (broken)
 * 
 * issue: convolution is currently incorrect and may become extremely slow
 * or appear to hang. Further debugging is deferred.
 * It used to be working before I refactor my code.
 *
 * @param src source FDF table
 * @param kernel convolution kernel
 * @return FDF table with the selected channels convolved
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 *  for more details
 */
t_table_fdf	convolve_hight(const t_table_fdf *src, t_matrix kernel)
{
	t_table_fdf	dst;
	size_t		i;

	if (src == NULL || src->arr == NULL)
		return (init_table_fdf(0, 0, false));
	dst = scale_dimension_fdf(src, 1, 1);
	i = 0;
	while (i < src->col * src->row)
	{
		dst.arr[i] = convolve_unit_height(src, kernel, i);
		i += 1;
	}
	return (dst);
}
