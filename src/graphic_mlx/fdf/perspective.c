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
// https://www.desmos.com/calculator/on7hjekiba

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_isometric(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = x / 2.0 - y / 2.0;
	dst.y = x / 4.0 + y / 4.0 - z;
	return (dst);
}

// https://en.wikipedia.org/wiki/Oblique_projection#Military_projection

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_cavalier(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)x;
	dst.y = (int)(x / 2.0 + y / 2.0 + z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_military(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4.0;
	dst.x = x * f_cos(alpha) + y * f_sin(alpha);
	dst.y = -1 * x * f_cos(alpha) + y * f_sin(alpha) + z;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	perspective_3d_cabinet(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4.0;
	dst.x = (int)x;
	dst.y = (int)(x * f_cos(alpha) + y * f_sin(alpha) + z);
	return (dst);
}


// https://youtu.be/ldxFjLJ3rVY?si=jHL-OtOAWq2V8mSa

// time : O(1)
// space: O(1)
t_2d_int	perspective_2d_conformal_sin(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex_x;
	t_complex	complex_y;

	complex_x.re = x;
	complex_x.im = y;
	complex_x = complex_sin(complex_x);
	complex_x.re = x;
	complex_x.im = y;
	dst.x = (int)complex_x.re;
	dst.y = (int)complex_x.im;
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	perspective_conformal_reciprocal(float x, float y, float z)
{
	t_2d_int	dst;
	t_complex	complex_x;

	complex_x.re = x;
	complex_x.im = y;
	complex_x = complex_reciprocal(complex_x);
	dst.x = (int)complex_x.re * z;
	dst.y = (int)complex_x.im * z;
	return (dst);
}
