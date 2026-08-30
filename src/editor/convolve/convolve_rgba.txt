/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convolve_rgba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 16:15:56 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/29 17:07:07 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convolve.h"

// time : O(1)
// space: O(1)
unsigned char	clamped_rgba(const t_table_fdf *src, int ix, int iy,
	t_enum_rgba channel)
{
	unsigned char	*arr;

	arr = get_rgba_of_table_fdf(src, channel);
	if (src == NULL || arr == NULL || src->row * src->col == 0)
		return (0);
	if (ix < 0)
		ix = 0;
	else if (ix >= (int)src->col)
		ix = (int)src->col - 1;
	if (iy < 0)
		iy = 0;
	else if (iy >= (int)src->row)
		iy = (int)src->row - 1;
	return (arr[iy * src->col + ix]);
}

// time : O(n^2)
// space: O(n^2)
t_matrix	init_src_kernel_rgba(const t_table_fdf *src,
	size_t dim, int ix, int iy, t_enum_rgba channel)
{
	t_matrix	dst;
	int			i;
	int			j;

	dst.col = dim;
	dst.row = dim;
	dst.arr = malloc_talk(sizeof(int) * dim * dim,
			"editor/convolve/convolve_height.c/init_src_kernel_int\n");
	if (dst.arr == NULL || dim == 0)
		return (dst);
	i = 0;
	while (i <= (int)dim / 2)
	{
		j = 0;
		while (j <= (int)dim / 2)
		{
			dst.arr[(dim / 2 + i) * dst.col + dim / 2 + j] = clamped_rgba(src, ix + j, iy + i, channel);
			dst.arr[(dim / 2 + i) * dst.col + dim / 2 - j] = clamped_rgba(src, ix - j, iy + i, channel);
			dst.arr[(dim / 2 - i) * dst.col + dim / 2 + j] = clamped_rgba(src, ix + j, iy - i, channel);
			dst.arr[(dim / 2 - i) * dst.col + dim / 2 - j] = clamped_rgba(src, ix - j, iy - i, channel);
			j += 1;
		}
		i += 1;
	}
	return (dst);
}

// time : O(m^2)
// space: O(m^2)
unsigned char	convolve_unit_rgba(const t_table_fdf *src,
	t_matrix kernel, size_t index, t_enum_rgba channel)
{
	t_matrix	src_kernel;
	int			output;
	size_t		dim;

	dim = kernel.col;
	output = 0;
	if (src == NULL || src->arr == NULL || dim * dim == 0
		|| index >= src->row * src->col)
		return (output);
	src_kernel = init_src_kernel_rgba(src, dim,
			(int)(index % src->col), (int)(index / src->col), channel);
	if (src_kernel.arr == NULL)
		return (output);
	if (src_kernel.arr != NULL && kernel.arr != NULL)
	{
		output = dot_product(src_kernel.arr,
				kernel.arr, dim * dim);
		if ((float)(f_sum(kernel.arr, dim * dim)) > 0.2)
			output = (int)f_round(
					(float)output / (float)(f_sum(kernel.arr, dim * dim)));
	}
	else if (src_kernel.arr != NULL && kernel.arr == NULL)
		output = f_round(f_sum(src_kernel.arr, dim * dim) / (float)(dim * dim));
	free(src_kernel.arr);
	return ((unsigned char)f_interval(output, 0, 255));
}

/**
 * Apply a convolution kernel to selected RGBA channels.
 * 
 * The kernel must be a square matrix with odd dimensions (e.g. 3x3, 5x5).
 * For each pixel, the kernel is centered on that pixel. Samples outside
 * the source image are clamped to the nearest edge pixel.
 * 
 * If kernel.arr is NULL, an average kernel will be utilized instead.
 *
 * time/space: O(n * m^2) / O(n)
 * 
 * status: public api (unchecked)
 *
 * @param src source FDF table
 * @param kernel convolution kernel
 * @param channel channel to convolve
 * @return FDF table with the selected channels convolved
 * 
 * @see 3B1B convolution video https://youtu.be/KuXjwB4LzSA?si=9DNIvf9SS2SX4jET
 * for more details
 */
t_table_fdf	convolve_rgba(const t_table_fdf *src, t_matrix kernel,
	t_enum_rgba channel)
{
	t_table_fdf		dst;
	size_t			i;
	unsigned char	*arr;

	if (src == NULL || src->arr == NULL || kernel.col != kernel.row)
		return (init_table_fdf(0, 0, false));
	dst = scale_dimension_fdf(src, 1, 1);
	arr = get_rgba_of_table_fdf(&dst, channel);
	if (arr == NULL)
		return (dst);
	i = 0;
	while (i < src->col * src->row)
	{
		arr[i] = convolve_unit_rgba(src, kernel, i, channel);
		i += 1;
	}
	return (dst);
}
