/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 15:50:05 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/02 16:06:05 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// https://en.wikipedia.org/wiki/Isometric_projection
// https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_isometric(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = 0.5 * x - 0.5 * y;
	dst.y = 0.25 * x + 0.25 * y - z;
	return (dst);
}

// https://youtu.be/ldxFjLJ3rVY?si=jHL-OtOAWq2V8mSa

// time : O(1)
// space: O(1)
t_2d_int	perspective_2d_conformal_sin(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex_x;

	complex_x.re = x + z * 0;
	complex_x.im = y + z * 0;
	complex_x = complex_sin(complex_x);
	dst.x = (int)complex_x.re;
	dst.y = (int)complex_x.im;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	perspective_2d_conformal_square(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex_x;

	complex_x.re = x + z * 0;
	complex_x.im = y + z * 0;
	complex_x = complex_multiplication(complex_x, complex_x);
	dst.x = (int)complex_x.re;
	dst.y = (int)complex_x.im;
	return (dst);
}

// https://en.wikipedia.org/wiki/Oblique_projection#Military_projection

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_oblique(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 6.0;
	dst.x = x + z * f_cos(alpha) / 2.0;
	dst.y = y + z * f_cos(alpha) / 2.0;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_cabinet(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4.0;
	dst.x = x + z * f_cos(alpha) / 2.0;
	dst.y = y + z * f_cos(alpha) / 2.0;
	return (dst);
}
