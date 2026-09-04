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

	dst.x = (int)(0.866 * x - 0.866 * y);
	dst.y = (int)(0.5 * x + 0.5 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_military(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(0.707 * x - 0.707 * y);
	dst.y = (int)(0.707 * x + 0.707 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cabinet_flat(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(x - 0.353 * y);
	dst.y = (int)(0.353 * y - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_cabinet(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(x - 0.353 * y);
	dst.y = (int)(0.707 * y - z);
	return (dst);
}
