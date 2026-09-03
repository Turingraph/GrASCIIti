/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 11:13:30 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 15:48:36 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

/*
Reference
*	https://www.desmos.com/calculator/ohf8ypwncs
*	https://en.wikipedia.org/wiki/Parallel_projection#/
	media/File:Comparison_of_graphical_projections.svg
*	https://medium.com/@amehri_tarik/fdf-42-a-detailed-walkthrough-7184cca317fc
*/

// time : O(1)
// space: O(1)
t_2d_int	projection_isometric(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 6.0;
	dst.x = (int)(f_cos(alpha) * x - f_cos(alpha) * y);
	dst.y = (int)(f_sin(alpha) * x + f_sin(alpha) * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_military(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4.0;
	dst.x = (int)(f_cos(alpha) * x - f_cos(alpha) * y);
	dst.y = (int)(f_sin(alpha) * x + f_sin(alpha) * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cabinet_flat(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4;
	dst.x = (int)(x - f_cos(alpha) * y / 2.0);
	dst.y = (int)(f_sin(alpha) * y / 2.0 - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cabinet(float x, float y, float z)
{
	t_2d_int	dst;
	double		alpha;

	alpha = 3.141592653 / 4;
	dst.x = (int)(x - f_cos(alpha) * y / 2.0);
	dst.y = (int)(f_sin(alpha) * y - z);
	return (dst);
}
