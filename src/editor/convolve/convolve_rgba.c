#include"convolve.h"

// time : O(1)
// space: O(1)
unsigned char	return_edge_rgba(const t_table_fdf *src, int edge_row, int edge_col, e_rgba rgba_type)
{
	size_t			row;
	size_t			col;
	unsigned char	*arr;

	if (src == NULL || src->row == 0 || src->col == 0)
		return (0);
	arr = get_rgba_of_table_fdf(src, rgba_type);
	if (arr == NULL)
		return (0);
	if (0 <= edge_row && (size_t)edge_row < src->row && 0 <= edge_col && (size_t)edge_col < src->col)
		return (arr[(size_t)edge_row * src->col + (size_t)edge_col]);
	row = 0;
	if (edge_row > 0 && (size_t)edge_row < src->row)
		row = (size_t)edge_row;
	if ((size_t)edge_row >= src->row)
		row = src->row - 1;
	col = 0;
	if (edge_col > 0 && (size_t)edge_col < src->col)
		col = (size_t)edge_col;
	if ((size_t)edge_col >= src->col)
		col = src->col - 1;
	return (arr[src->col * row + col]);
}

// time : O(n^2)
// space: O(n^2)
t_matrix	init_src_kernel_rgba(size_t half_dim, const t_table_fdf *src, size_t index, e_rgba rgba_type)
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
			dst.arr[(half_dim + i) * dst.col + half_dim + j] = (float)return_edge_rgba(src, index / src->col + i, index % src->col + j, rgba_type);
			dst.arr[(half_dim + i) * dst.col + half_dim - j] = (float)return_edge_rgba(src, index / src->col + i, index % src->col - j, rgba_type);
			dst.arr[(half_dim - i) * dst.col + half_dim + j] = (float)return_edge_rgba(src, index / src->col - i, index % src->col + j, rgba_type);
			dst.arr[(half_dim - i) * dst.col + half_dim - j] = (float)return_edge_rgba(src, index / src->col - i, index % src->col - j, rgba_type);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
unsigned char	convolve_unit_rgba(const t_table_fdf *src, t_matrix kernel, e_rgba rgba_type, size_t index)
{
	int			output;
	t_matrix	src_kernel;

	output = 0;
	if (src != NULL && index < src->col * src->row)
	{
		src_kernel = init_src_kernel_rgba(kernel.col / 2, src, index, rgba_type);
		if (src_kernel.arr != NULL && kernel.arr != NULL)
			output = dot_product((const float *)src_kernel.arr,
				kernel.arr, kernel.col * kernel.col);
		else if (src_kernel.arr != NULL && kernel.arr == NULL)
		{
			kernel = init_src_kernel_rgba(kernel.col / 2, src, index, rgba_type);
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
	return ((unsigned char)f_interval(f_round(output), 0, 255));
}

/**
 * Apply a convolution kernel to selected RGBA channels.
 *
 * time/space: O(n * m^2) / O(n)
 *
 * status: public api
 *
 * @param src source FDF table
 * @param kernel convolution kernel
 * @param target_channels channels to convolve
 * @return FDF table with the selected channels convolved
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 *  for more details
 */
t_table_fdf	convolve_rgba(const t_table_fdf *src, t_matrix kernel, e_rgba target_channels)
{
	t_table_fdf		dst;
	size_t			i;

	if (src == NULL || src->arr == NULL)
		return (init_table_fdf(0, 0, false));
	dst = scale_dimension_fdf(src, 1, 1);
	i = 0;
	while (i < src->col * src->row)
	{
		if (target_channels == RED && dst.r != NULL && src->r != NULL)
			dst.r[i] = convolve_unit_rgba(src, kernel, RED, i);
		if (target_channels == GREEN && dst.g != NULL && src->g != NULL)
			dst.g[i] = convolve_unit_rgba(src, kernel, GREEN, i);
		if (target_channels == BLUE && dst.b != NULL && src->b != NULL)
			dst.b[i] = convolve_unit_rgba(src, kernel, BLUE, i);
		if (target_channels == ALPHA && dst.a != NULL && src->a != NULL)
			dst.a[i] = convolve_unit_rgba(src, kernel, ALPHA, i);
		i += 1;
	}
	return (dst);
}
