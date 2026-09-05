/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:13:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/04 18:15:33 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
Reference
*	https://www.desmos.com/calculator/ohf8ypwncs
*	https://en.wikipedia.org/wiki/Parallel_projection#/
	media/File:Comparison_of_graphical_projections.svg
*	https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc
*/

// time : O(1)
// space: O(1)
t_complex	projection_isometric(float x, float y, float z)
{
	t_complex	dst;

	dst.re = (0.866 * x - 0.866 * y);
	dst.im = (0.5 * x + 0.5 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	projection_military(float x, float y, float z)
{
	t_complex	dst;

	dst.re = (0.707 * x - 0.707 * y);
	dst.im = (0.707 * x + 0.707 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	projection_cabinet(float x, float y, float z)
{
	t_complex	dst;

	dst.re = (x - 0.353 * y);
	dst.im = (0.707 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	projection_orthogonal(float x, float y, float z)
{
	t_complex	dst;

	dst.re = x;
	dst.im = (y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_complex	projection_wave(float x, float y, float z)
{
	t_complex	dst;

	dst.re = x;
	dst.im = (z * f_cos(x) + y - z);
	return (dst);
}
