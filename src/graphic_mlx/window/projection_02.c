/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 12:51:36 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 18:16:08 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window_private.h"

// time : O(1)
// space: O(1)
t_2d_int	projection_csin(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;

	complex.re = 1.57 * x / 1920.0;
	complex.im = 1.57 * (y - z) / 1920.0;
	complex = complex_sin(complex);
	dst.x = (int)(complex.re * 1920.0);
	dst.y = (int)(complex.im * -1920.0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cexp(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;

	complex.re = x / 1920.0;
	complex.im = (y - z) / 1920.0;
	complex = complex_exp(complex);
	dst.x = (int)(complex.re * 1920.0 - 1920.0);
	dst.y = (int)(complex.im * 1920.0);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cexp_left(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex;

	complex.re = x / 1920.0;
	complex.im = (y - z) / 1920.0;
	complex = complex_exp(complex);
	dst.x = -1 * (int)(complex.re * 1920.0 - 1920.0);
	dst.y = (int)(complex.im * 1920.0);
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
