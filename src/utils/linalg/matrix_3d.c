/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 22:18:04 by phsottat          #+#    #+#             */
/*   Updated: 2026/08/24 22:19:56 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_x(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = 1.0;
	dst.arr[1] = 0.0;
	dst.arr[2] = 0.0;
	dst.arr[3] = 0.0;
	dst.arr[4] = f_cos(delta);
	dst.arr[5] = -1.0 * f_sin(delta);
	dst.arr[6] = 0.0;
	dst.arr[7] = f_sin(delta);
	dst.arr[8] = f_cos(delta);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_y(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = f_cos(delta);
	dst.arr[1] = 0.0;
	dst.arr[2] = f_sin(delta);
	dst.arr[3] = 0.0;
	dst.arr[4] = 1.0;
	dst.arr[5] = 0.0;
	dst.arr[6] = -1.0 * f_sin(delta);
	dst.arr[7] = 0.0;
	dst.arr[8] = f_cos(delta);
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_rotate_matrix_z(float delta)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = f_cos(delta);
	dst.arr[1] = -1.0 * f_sin(delta);
	dst.arr[2] = 0.0;
	dst.arr[3] = f_sin(delta);
	dst.arr[4] = f_cos(delta);
	dst.arr[5] = 0.0;
	dst.arr[6] = 0.0;
	dst.arr[7] = 0.0;
	dst.arr[8] = 1.0;
	return (dst);
}

// time : O(1)
// space: O(1)
t_matrix	init_3d_zoom_matrix(float zoom)
{
	t_matrix	dst;

	dst.arr = malloc(sizeof(float) * 9);
	dst.col = 0;
	dst.row = 0;
	if (dst.arr == NULL)
		return (dst);
	dst.col = 3;
	dst.row = 3;
	dst.arr[0] = zoom;
	dst.arr[1] = 0.0;
	dst.arr[2] = 0.0;
	dst.arr[3] = 0.0;
	dst.arr[4] = zoom;
	dst.arr[5] = 0.0;
	dst.arr[6] = 0.0;
	dst.arr[7] = 0.0;
	dst.arr[8] = zoom;
	return (dst);
}

// https://www.storyofmathematics.com/inverse-of-a-3x3-matrix/

// time : O(1)
// space: O(1)
t_matrix	init_inverse_3d_matrix(t_matrix src)
{
	float		det;
	float		*a;
	t_matrix	dst;

	dst.arr = NULL;
	dst.col = 0;
	dst.row = 0;
	a = src.arr;
	det = matrix_det(src);
	if (a == NULL || (det < 1e-6f && det > -1e-6f))
		return (dst);
	dst.arr = malloc(sizeof(float) * 9);
	if (dst.arr == NULL)
		return (dst);
	dst.arr[0] = (a[4] * a[8] - a[5] * a[7]) / det;
	dst.arr[1] = -1 * (a[1] * a[8] - a[2] * a[7]) / det;
	dst.arr[2] = (a[5] * a[1] - a[2] * a[4]) / det;
	dst.arr[3] = -1 * (a[3] * a[8] - a[5] * a[6]) / det;
	dst.arr[4] = (a[0] * a[8] - a[2] * a[6]) / det;
	dst.arr[5] = -1 * (a[0] * a[5] - a[2] * a[3]) / det;
	dst.arr[6] = (a[3] * a[7] - a[4] * a[6]) / det;
	dst.arr[7] = -1 * (a[0] * a[7] - a[1] * a[6]) / det;
	dst.arr[8] = (a[0] * a[4] - a[1] * a[3]) / det;
	return (dst);
}

/*
==325392== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==325392== Command: ./coding_examples/out/graphic/window/ascii_fdf.out input_examples/view/lerem_ipsum_nvscript.txt
==325392== 
length: 402
length: 394
length: 381
length: 362
length: 340
length: 317
length: 297
length: 281
length: 272
length: 268
length: 268
length: 268
*/
