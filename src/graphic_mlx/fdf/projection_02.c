/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:51:36 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 17:12:35 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(1)
// space: O(1)
t_2d_int	projection_csin(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;
	double		alpha;
	double		xxx;
	double		yyy;

	xxx = (double)x;
	yyy = (double)(y + z);
	alpha = 3.141592653 / 2.0;
	complex.re = alpha * xxx / 1920.0;
	complex.im = alpha * yyy / 1920.0;
	complex = complex_sin(complex);
	dst.x = (int)(complex.re * 1080.0);
	dst.y = (int)(complex.im * 1080.0 * -1);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cexp(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;
	double		xxx;
	double		yyy;

	xxx = (double)x;
	yyy = (double)(y + z);
	complex.re = xxx / 1920.0;
	complex.im = yyy / 1920.0;
	complex = complex_exp(complex);
	dst.x = (int)(complex.re * 1080.0 - 1920.0);
	dst.y = (int)(complex.im * 1080.0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cexp_left(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;
	double		xxx;
	double		yyy;

	xxx = (double)(-1.0 * x);
	yyy = (double)(y + z);
	complex.re = xxx / 1920.0;
	complex.im = yyy / 1920.0;
	complex = complex_exp(complex);
	dst.x = -1 * (int)(complex.re * 1080.0 - 1920.0);
	dst.y = (int)(complex.im * 1080.0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_scifi_rotate(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(f_cos(z) * x - f_cos(z) * y);
	dst.y = (int)(f_sin(z) * x + f_sin(z) * y);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_orthogonal(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)x;
	dst.y = (int)(y - z);
	return (dst);
}
