/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:15:25 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:16:04 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raster.h"

// time : O(1)
// space: O(1)
int32_t	f_rgba_to_int32(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// time : O(n)
// space: O(1)
void	color_background_mlx(mlx_image_t *dst, int32_t color)
{
	int32_t	i;
	int32_t	j;

	i = 0;
	while (dst != NULL && i < (int32_t)dst->height)
	{
		j = 0;
		while (j < (int32_t)dst->width)
		{
			mlx_put_pixel(dst, j, i, color);
			j += 1;
		}
		i += 1;
	}
}

// time : O(1)
// space: O(1)
int32_t	get_table_rgba_int32_unit(const unsigned char *src,
	size_t index, size_t col)
{
	int32_t	r;

	if (src == NULL)
		return (0);
	r = src[index];
	r += src[index + 1];
	r += src[index + col + 1];
	r += src[index + col + 1];
	return (r / 4);
}

// time : O(1)
// space: O(1)
int32_t	get_table_rgba_int32(const t_table_fdf *src, size_t index)
{
	int32_t	r;
	int32_t	g;
	int32_t	b;
	int32_t	a;

	if (src == NULL || index >= src->row * src->col)
		return (0);
	r = 0;
	g = 0;
	b = 0;
	a = 0;
	if (src->r != NULL && src->color_sampling == SAMPLE_AVERAGE)
		r = get_table_rgba_int32_unit(src->r, index, src->col);
	if (src->g != NULL && src->color_sampling == SAMPLE_AVERAGE)
		g = get_table_rgba_int32_unit(src->g, index, src->col);
	if (src->b != NULL && src->color_sampling == SAMPLE_AVERAGE)
		b = get_table_rgba_int32_unit(src->b, index, src->col);
	if (src->a != NULL && src->color_sampling == SAMPLE_AVERAGE)
		a = get_table_rgba_int32_unit(src->a, index, src->col);
	return (r << 24 | g << 16 | b << 8 | a);
}

// if (src->r != NULL && src->color_sampling != SAMPLE_AVERAGE)
// 	r = (int32_t)src->r[index];
// if (src->g != NULL && src->color_sampling != SAMPLE_AVERAGE)
// 	g = (int32_t)src->g[index];
// if (src->b != NULL && src->color_sampling != SAMPLE_AVERAGE)
// 	b = (int32_t)src->b[index];
// if (src->a != NULL && src->color_sampling != SAMPLE_AVERAGE)
// 	a = (int32_t)src->a[index];
