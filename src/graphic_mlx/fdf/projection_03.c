/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phsottat <phsottat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/03 15:39:03 by phsottat          #+#    #+#             */
/*   Updated: 2026/09/03 15:48:03 by phsottat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_private.h"

// time : O(1)
// space: O(1)
t_2d_int	projection_y_times_z(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)x;
	dst.y = (int)(y * z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_scifi_scale(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(x * z);
	dst.y = (int)(y * z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_scifi_divide(float x, float y, float z)
{
	t_2d_int	dst;

	if (z < 0.2)
	{
		dst.x = (int)x;
		dst.y = (int)y;
		return (dst);
	}
	dst.x = (int)(x / z);
	dst.y = (int)(y / z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_zparallel(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)(-1.0 * x + f_cos(z) * y / 2.0);
	dst.y = (int)(f_sin(z) * y / 2.0 - z);
	return (dst);
}

// time : O(1)
// space: O(1)
t_2d_int	projection_wave(float x, float y, float z)
{
	t_2d_int	dst;

	dst.x = (int)x;
	dst.y = (int)(f_cos(x) + y - z);
	return (dst);
}
