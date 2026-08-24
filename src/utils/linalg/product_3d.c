/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product_3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 10:21:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:23:06 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

// time : O(1)
// space: O(1)
void	cross_product_3d(float *update_v, const float *vec_u)
{
	float	dim_0;
	float	dim_1;
	float	dim_2;

	if (update_v != NULL && vec_u != NULL)
	{
		dim_0 = update_v[0];
		dim_1 = update_v[1];
		dim_2 = update_v[2];
		update_v[0] = dim_1 * vec_u[2] - dim_2 * vec_u[1];
		update_v[1] = (dim_0 * vec_u[2] - dim_2 * vec_u[0]) * -1.0;
		update_v[2] = dim_0 * vec_u[1] - dim_1 * vec_u[0];
	}
}

// time : O(1)
// space: O(1)
void	update_3d_vector(float *dst, float x, float y, float z)
{
	if (dst != NULL)
	{
		dst[0] = x;
		dst[1] = y;
		dst[2] = z;
	}
}

// time : O(1)
// space: O(1)
float	*init_3d_vector(float x, float y, float z)
{
	float	*dst;

	dst = malloc(sizeof(float) * 3);
	if (dst == NULL)
		return (NULL);
	dst[0] = x;
	dst[1] = y;
	dst[2] = z;
	return (dst);
}

// time : O(n)
// space: O(1)
void	matrix_3d_product(t_matrix src, t_matrix *dst)
{
	float	c[9];
	float	*b;
	size_t	i;

	if (src.arr == NULL || dst == NULL
		|| dst->arr == NULL || src.col * src.row < 9
		|| src.col * src.row != dst->col * dst->row)
		return ;
	b = dst->arr;
	c[0] = src.arr[0] * b[0] + src.arr[3] * b[1] + src.arr[6] * b[2];
	c[1] = src.arr[1] * b[0] + src.arr[4] * b[1] + src.arr[7] * b[2];
	c[2] = src.arr[2] * b[0] + src.arr[5] * b[1] + src.arr[8] * b[2];
	c[3] = src.arr[0] * b[3] + src.arr[3] * b[4] + src.arr[6] * b[5];
	c[4] = src.arr[1] * b[3] + src.arr[4] * b[4] + src.arr[7] * b[5];
	c[5] = src.arr[2] * b[3] + src.arr[5] * b[4] + src.arr[8] * b[5];
	c[6] = src.arr[0] * b[6] + src.arr[3] * b[7] + src.arr[6] * b[8];
	c[7] = src.arr[1] * b[6] + src.arr[4] * b[7] + src.arr[7] * b[8];
	c[8] = src.arr[2] * b[6] + src.arr[5] * b[7] + src.arr[8] * b[8];
	i = 0;
	while (i < 9)
	{
		dst->arr[i] = c[i];
		i += 1;
	}
}

// time : O(1)
// space: O(1)
float	matrix_det(t_matrix src)
{
	float	*a;
	float	y;

	if (src.arr == NULL || src.col * src.row < 9)
		return (0.0);
	a = src.arr;
	y = a[0] * (a[4] * a[8] - a[5] * a[7]);
	y += -1 * a[1] * (a[3] * a[8] - a[5] * a[6]);
	y += a[2] * (a[3] * a[7] - a[4] * a[6]);
	return (y);
}

