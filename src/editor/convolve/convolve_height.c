/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convolve_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 20:42:38 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 20:56:12 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convolve.h"

// time : O(1)
// space: O(1)
float	return_edge_height(const t_table_fdf *src, int edge_row, int edge_col)
{
	size_t	row;
	size_t	col;

	if (src == NULL || src->row == 0 || src->col == 0 || src->arr == NULL)
		return (0);
	if (0 <= edge_row && (size_t)edge_row < src->row
		&& 0 <= edge_col && (size_t)edge_col < src->col)
		return (src->arr[(size_t)edge_row * src->col + (size_t)edge_col]);
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
	return ((float)src->arr[src->col * row + col]);
}

// time : O(n^2)
// space: O(n^2)
t_matrix	init_src_kernel_height(size_t half_d,
	const t_table_fdf *src, size_t index)
{
	t_matrix	dst;
	size_t		i;
	size_t		j;

	dst = init_matrix(2 * half_d + 1, 2 * half_d + 1, 1);
	i = 0;
	while (src != NULL && src->arr != NULL && i < half_d)
	{
		j = 0;
		while (j < half_d)
		{
			dst.arr[(half_d + i) * dst.col + half_d + j] = return_edge_height(
					src, index / src->col + i, index % src->col + j);
			dst.arr[(half_d + i) * dst.col + half_d - j] = return_edge_height(
					src, index / src->col + i, index % src->col - j);
			dst.arr[(half_d - i) * dst.col + half_d + j] = return_edge_height(
					src, index / src->col - i, index % src->col + j);
			dst.arr[(half_d - i) * dst.col + half_d - j] = return_edge_height(
					src, index / src->col - i, index % src->col - j);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(n)
// space: O(n)
int	convolve_unit_height(const t_table_fdf *src,
	t_matrix kernel, size_t id)
{
	int			output;
	t_matrix	src_kernel;

	output = 0;
	if (src != NULL && src->arr != NULL && id < src->col * src->row)
	{
		src_kernel = init_src_kernel_height(kernel.col / 2, src, id);
		if (src_kernel.arr != NULL && kernel.arr != NULL)
			output = dot_product((const float *)src_kernel.arr,
					kernel.arr, kernel.col * kernel.col);
		else if (src_kernel.arr != NULL && kernel.arr == NULL)
		{
			kernel = init_src_kernel_height(kernel.col / 2, src, id);
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

// time : O(n * m^2)
// space: O(n * m^2)
t_table_fdf	convolve_hight(const t_table_fdf *src, t_matrix kernel)
{
	t_table_fdf	dst;
	size_t		i;

	if (src == NULL || src->arr == NULL)
		return (init_table_fdf(0, 0, false));
	dst = scale_dimension_fdf(src, 1, 1);
	i = 0;
	while (i < dst.col * dst.row)
	{
		dst.arr[i] = convolve_unit_height(src, kernel, i);
		i += 1;
	}
	return (dst);
}

/*
I will implement the matrix product and matrix det algorithm
later in some future.
*/

/*
// time : O(n)
// space: O(n)
t_table_fdf	detvolve_hight(const t_table_fdf *src, const t_matrix *kernel,
	size_t dim, float (*square_matrix_operation)(const float *vec_v,
	float *vec_u, size_t dim))
{
	t_table_fdf	dst;
	size_t		i;
	t_matrix	src_kernel;
	t_matrix	twin_kernel;

	if (src == NULL || src->arr == NULL)
		return (init_table_fdf(0, 0, FALSE));
	dst = scale_dimension_fdf(src, 1, 1);
	i = 0;
	while (i < dst.col * dst.row)
	{
		src_kernel = init_src_kernel_height(dim, src, i);
		if (src_kernel.arr != NULL && kernel != NULL && kernel.arr != NULL)
			dst.arr[i] = (int)f_round(matrix_det(
square_matrix_operation((const float *)src_kernel.arr, kernel.arr, dim * dim)));
		else if (src_kernel.arr != NULL && (kernel == NULL
|| kernel.arr == NULL))
		{
			twin_kernel = init_src_kernel_height(dim, src, i);
			if (twin_kernel.arr != NULL)
				dst.arr[i] = (int)f_round(matrix_det(
square_matrix_operation((const float *)src_kernel.arr,
twin_kernel.arr, dim * dim)));
			free_matrix(&twin_kernel);
		}
		free_matrix(&src_kernel);
		i += 1;
	}
	return (dst);
}
*/
